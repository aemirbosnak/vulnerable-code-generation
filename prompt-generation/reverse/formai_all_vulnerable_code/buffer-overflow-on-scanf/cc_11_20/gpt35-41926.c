//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int computer, player, result;
    int wins = 0, losses = 0, draws = 0;
    char choice;

    printf("Welcome to Rock, Paper, Scissors!\n");

    do {
        srand(time(0));

        printf("\nChoose (R)ock, (P)aper, or (S)cissors: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'r':
            case 'R':
                player = 1;
                printf("You chose Rock!\n");
                break;

            case 'p':
            case 'P':
                player = 2;
                printf("You chose Paper!\n");
                break;

            case 's':
            case 'S':
                player = 3;
                printf("You chose Scissors!\n");
                break;

            default:
                printf("Invalid input, please choose R, P, or S.\n");
                continue;
        }

        computer = (rand() % 3) + 1;

        if (computer == 1) {
            printf("Computer chose Rock!\n");

            if (player == 1) {
                printf("It's a draw!\n");
                draws++;
            } else if (player == 2) {
                printf("You win!\n");
                wins++;
            } else {
                printf("You lose!\n");
                losses++;
            }
        } else if (computer == 2) {
            printf("Computer chose Paper!\n");

            if (player == 1) {
                printf("You lose!\n");
                losses++;
            } else if (player == 2) {
                printf("It's a draw!\n");
                draws++;
            } else {
                printf("You win!\n");
                wins++;
            }
        } else {
            printf("Computer chose Scissors!\n");

            if (player == 1) {
                printf("You win!\n");
                wins++;
            } else if (player == 2) {
                printf("You lose!\n");
                losses++;
            } else {
                printf("It's a draw!\n");
                draws++;
            }
        }

        printf("Wins: %d, Losses: %d, Draws: %d\n", wins, losses, draws);

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}