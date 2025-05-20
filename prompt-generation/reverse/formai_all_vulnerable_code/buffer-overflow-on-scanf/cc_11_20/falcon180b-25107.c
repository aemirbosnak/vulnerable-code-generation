//Falcon-180B DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int i = 0;
    char play_again = 'y';

    srand(time(NULL));

    while (play_again == 'y' || play_again == 'Y') {
        printf("Player score: %d\n", player_score);
        printf("Computer score: %d\n\n", computer_score);

        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You chose rock.\n");
                i = rand() % 3;
                if (i == 0) {
                    printf("Computer chose scissors.\n");
                    computer_score++;
                } else if (i == 1) {
                    printf("Computer chose paper.\n");
                } else {
                    printf("Computer chose rock.\n");
                    player_score++;
                }
                break;
            case 2:
                printf("You chose paper.\n");
                i = rand() % 3;
                if (i == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                } else if (i == 1) {
                    printf("Computer chose scissors.\n");
                } else {
                    printf("Computer chose paper.\n");
                    player_score++;
                }
                break;
            case 3:
                printf("You chose scissors.\n");
                i = rand() % 3;
                if (i == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                } else if (i == 1) {
                    printf("Computer chose paper.\n");
                } else {
                    printf("Computer chose scissors.\n");
                    player_score++;
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");

        if (player_score == 5 || computer_score == 5) {
            printf("Game over! Player wins!\n");
        } else if (computer_score == 5) {
            printf("Game over! Computer wins!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    return 0;
}