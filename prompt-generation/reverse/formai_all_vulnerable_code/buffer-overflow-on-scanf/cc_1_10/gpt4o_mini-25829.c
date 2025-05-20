//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

void display_welcome_message() {
    printf("====================================\n");
    printf("        Welcome to Guess the Number!\n");
    printf("====================================\n");
    printf("Instructions:\n");
    printf("1. A random number between 1 and 100 will be generated.\n");
    printf("2. You have %d attempts to guess the number.\n", MAX_TRIES);
    printf("3. After each guess, you'll receive feedback.\n");
    printf("====================================\n");
}

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int random_number = get_random_number(1, 100);
    int guess;
    int attempts = 0;

    display_welcome_message();
    
    while (attempts < MAX_TRIES) {
        printf("Attempt %d: Enter your guess (1-100): ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (guess == random_number) {
            printf("Congratulations! You've guessed the correct number %d in %d attempts!\n", random_number, attempts);
            break;
        } else if (guess < random_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        if (attempts == MAX_TRIES) {
            printf("Sorry! You've used all attempts. The correct number was %d.\n", random_number);
        }
    }

    printf("Thank you for playing! Would you like to play again? (y/n): ");
    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        // Reset the game
        main(); // Recalling main for a new game session
    } else {
        printf("Exiting the game. Goodbye!\n");
    }

    return 0;
}