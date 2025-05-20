//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int level, score;
    int choice, guess, num_guesses;

    srand(time(0));

    printf("Welcome to Guess the Number!\n");
    printf("Choose your level (1-3):\n");
    scanf("%d", &level);

    switch(level) {
        case 1:
            score = 10;
            break;
        case 2:
            score = 20;
            break;
        case 3:
            score = 30;
            break;
        default:
            printf("Invalid level selected.\n");
            return 0;
    }

    printf("You have %d points. Guess the number!\n", score);

    int range = level * 10;
    int secret_num = rand() % range + 1;

    num_guesses = 0;
    guess = 0;

    while(guess != secret_num && num_guesses < level * 2) {
        printf("Enter your guess (1-%d):\n", range);
        scanf("%d", &guess);

        if(guess < 1 || guess > range) {
            printf("Invalid guess. Try again.\n");
            continue;
        }

        if(guess < secret_num) {
            printf("Too low. Guess again.\n");
        } else if (guess > secret_num) {
            printf("Too high. Guess again.\n");
        }

        num_guesses++;
    }

    if(guess == secret_num) {
        printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
        score -= num_guesses;
    } else {
        printf("Sorry, you didn't guess the number. The number was %d.\n", secret_num);
        score = 0;
    }

    printf("Your final score is %d.\n", score);
    printf("Would you like to play again? (1 for yes, 0 for no)\n");
    scanf("%d", &choice);

    if(choice == 1) {
        main();
    }

    return 0;
}