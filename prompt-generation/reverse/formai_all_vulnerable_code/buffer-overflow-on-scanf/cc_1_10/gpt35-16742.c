//FormAI DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int high_score = 0;
    int choice;
    srand(time(0));

    printf("~~~ Welcome to the Number Guessing Game! ~~~\n");
    printf("Instructions: \n");
    printf("1. You will have to guess a number from 1 to 100.\n");
    printf("2. You have 10 chances to guess the correct number.\n");

    do {
        int random_num = rand() % 100 + 1;
        printf("\nGuess the number: \n");

        for(int i = 1; i <= 10; i++) {
            int guess;
            printf("Attempt #%d: ", i);
            scanf("%d", &guess);

            if(guess == random_num) {
                printf("\nCongratulations! You guessed the correct number in %d attempts!\n", i);
                score += 10 - i;

                if(score > high_score) {
                    high_score = score;
                }

                printf("Your current score: %d\n", score);
                printf("Your high score: %d\n", high_score);

                break;
            } else {
                printf("Incorrect guess. ");

                if(guess < random_num) {
                    printf("Try a higher number.\n");
                } else {
                    printf("Try a lower number.\n");
                }

                if(i == 10) {
                    printf("\nGame over. The correct number was: %d\n", random_num);
                }
            }
        }

        printf("Would you like to play again? (1 for Yes / 0 for No) ");
        scanf("%d", &choice);

        while(choice != 1 && choice != 0) {
            printf("Invalid choice. Please enter 1 for Yes or 0 for No: ");
            scanf("%d", &choice);
        }
    } while(choice == 1);

    printf("\nThanks for playing the Number Guessing Game!\n");

    return 0;
}