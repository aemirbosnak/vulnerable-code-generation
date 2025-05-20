//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int random_number;
    char play_again;

    srand(time(NULL));

    do {
        printf("Welcome to the Number Guessing Game!\n");
        printf("Guess a number between 1 and 100.\n");

        printf("Choose an option:\n");
        printf("1. Guess a number\n");
        printf("2. Let the computer guess\n");
        printf("3. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your guess: ");
                scanf("%d", &random_number);

                if(random_number == rand() % 100 + 1) {
                    printf("Congratulations! You guessed the number correctly.\n");
                    player_score++;
                } else if(random_number < rand() % 100 + 1) {
                    printf("Your guess is too low.\n");
                } else {
                    printf("Your guess is too high.\n");
                }

                break;

            case 2:
                random_number = rand() % 100 + 1;

                if(random_number == 1) {
                    printf("The computer guessed the number correctly.\n");
                    computer_score++;
                } else {
                    printf("The computer guessed the number incorrectly.\n");
                }

                break;

            case 3:
                printf("Thanks for playing! Do you want to play again? (y/n)\n");
                scanf(" %c", &play_again);

                if(play_again == 'y' || play_again == 'Y') {
                    system("clear");
                }

                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPlayer score: %d\n", player_score);
        printf("Computer score: %d\n\n", computer_score);

    } while(play_again == 'y' || play_again == 'Y');

    return 0;
}