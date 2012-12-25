#include <cstdlib>
#include <QCoreApplication>
#include <QtGui>

qint8 roll_dice()
{
    return rand() % 6 + 1;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString response = QString("%1\nDICE 1: %2\nDICE 2: %3\n SUM: %4");
    QString message_title;
    bool continue_game;
    int first_dice;
    int second_dice;
    int sum_dice;
    int answer;

    srand(time(0));

    do {
        first_dice = roll_dice();
        second_dice = roll_dice();
        sum_dice = first_dice + second_dice;

        switch (sum_dice) {
            case 7:
            case 11:
                continue_game = false;
                message_title = QString("You Win");
                response = QString("%1\nDICE 1: %2\nDICE 2: %3\n SUM: %4")
                        .arg("YOU WIN!!!!")
                        .arg(first_dice)
                        .arg(second_dice)
                        .arg(sum_dice);
                break;
            case 2:
                continue_game = false;
                message_title = QString("You Lose");
                response = QString("%1\nDICE 1: %2\nDICE 2: %3\n SUM: %4")
                        .arg("YOU LOSE :(")
                        .arg(first_dice)
                        .arg(second_dice)
                        .arg(sum_dice);
                break;
            default:
                continue_game = true;
                response = QString("DICE 1: %2\nDICE 2: %3\n SUM: %4")
                        .arg(first_dice)
                        .arg(second_dice)
                        .arg(sum_dice);
                QMessageBox::information(
                            0,          // Parent
                            "Dice Results", // Title
                            response);

        }
    } while (true == continue_game);

    answer = QMessageBox::question(
                    0,          // Parent
                    "You Win",  // Title
                    response,   // Response
                    QMessageBox::Yes | QMessageBox::No
                    );

    return EXIT_SUCCESS;
}
