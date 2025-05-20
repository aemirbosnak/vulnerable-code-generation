//FormAI DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Set up variables
    int secret_number = rand() % 101;
    int guess_count = 0;
    int guess_limit = 10;
    int guess;
    int easy_mode = 0;

    // Welcome message
    printf("Welcome to Guess the Number!\n");
    printf("You have %d guesses to find the secret number.\n", guess_limit);

    // Ask for game mode
    printf("Do you want to play in easy mode? (yes or no) ");
    char answer[3];
    scanf("%s", &answer);
    if (strcmp(answer, "yes") == 0) {
        guess_limit = 20;
        easy_mode = 1;
        printf("Easy mode activated! You now have %d guesses.\n", guess_limit);
    }

    // Game loop
    while (guess_count < guess_limit) {
        // Ask for guess
        printf("Guess a number between 0 and 100: ");
        scanf("%d", &guess);

        // Check if guess is out of range
        if (guess < 0 || guess > 100) {
            printf("That number is out of range! Please try again.\n");
            continue;
        }

        // Increment guess count and check if game is over
        guess_count++;
        if (guess == secret_number) {
            printf("Congratulations! You found the secret number in %d guesses!\n", guess_count);
            break;
        } else if (guess_count == guess_limit) {
            printf("Sorry, you ran out of guesses. The secret number was %d.\n", secret_number);
            break;
        }

        // Give hint based on difficulty mode
        if (easy_mode == 1) {
            if (guess < secret_number) {
                printf("Hint: The secret number is higher than %d.\n", guess);
            } else {
                printf("Hint: The secret number is lower than %d.\n", guess);
            }
        } else {
            // Give random hint in hard mode
            int hint = rand() % 3;
            if (hint == 0) {
                printf("Hint: The secret number is divisible by %d.\n", rand() % 5 + 1);
            } else if (hint == 1) {
                printf("Hint: The secret number is a multiple of %d.\n", rand() % 10 + 1);
            } else {
                printf("Hint: The secret number is between %d and %d.\n", secret_number - rand() % 20, secret_number + rand() % 20);
            }
        }
    }

    // Goodbye message
    printf("Thanks for playing Guess the Number!\n");

    return 0;
}