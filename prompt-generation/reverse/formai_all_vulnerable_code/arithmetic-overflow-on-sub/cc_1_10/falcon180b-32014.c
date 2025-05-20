//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0, choice, result;
    char play_again;

    srand(time(NULL));

    do {
        printf("Welcome to the Number Guessing Game!\n");
        printf("You have to guess a number between 1 and 100.\n");
        printf("The computer will also guess a number.\n");
        printf("Whoever guesses the correct number first wins!\n\n");

        printf("Do you want to play? (y/n): ");
        scanf("%c", &play_again);

        if (play_again == 'y' || play_again == 'Y') {
            int number = rand() % 100 + 1;
            int attempts = 0;

            while (attempts < 10) {
                printf("Attempt %d: ", attempts + 1);
                scanf("%d", &choice);

                result = choice - number;

                if (result == 0) {
                    printf("You win!\n");
                    player_score++;
                } else if (result > 0) {
                    printf("Too high.\n");
                } else {
                    printf("Too low.\n");
                }

                attempts++;
            }

            if (attempts == 10) {
                printf("You lose. The number was %d.\n", number);
                computer_score++;
            }
        } else {
            printf("Thanks for playing!\n");
        }

        printf("Player score: %d\n", player_score);
        printf("Computer score: %d\n\n", computer_score);

        printf("Do you want to play again? (y/n): ");
        scanf("%c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}