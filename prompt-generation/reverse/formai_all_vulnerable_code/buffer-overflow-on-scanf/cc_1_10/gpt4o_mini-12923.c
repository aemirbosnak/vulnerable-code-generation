//GPT-4o-mini DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message() {
    printf("************************************\n");
    printf("         NUMBER GUESSING GAME      \n");
    printf("************************************\n");
    printf("Try to guess the number I'm thinking of.\n");
    printf("It's between 1 and 100.\n");
    printf("You have 10 attempts.\n");
    printf("Good luck!\n");
    printf("************************************\n");
}

int get_guess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

void game_loop(int secret_number) {
    int guess;
    int attempts = 10;

    while (attempts > 0) {
        guess = get_guess();

        if (guess < 1 || guess > 100) {
            printf("Invalid guess! Please choose a number between 1 and 100.\n");
            continue;
        }

        if (guess == secret_number) {
            printf("Congratulations! You've guessed the correct number: %d\n", secret_number);
            return;
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        attempts--;
        if (attempts > 0) {
            printf("You have %d attempts left.\n", attempts);
        } else {
            printf("Sorry, you've run out of attempts! The correct number was: %d\n", secret_number);
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    int secret_number = rand() % 100 + 1; // Random number between 1 and 100

    print_welcome_message();
    game_loop(secret_number);

    // Prompt for a replay
    char replay;
    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &replay);
    
    while (replay == 'y' || replay == 'Y') {
        secret_number = rand() % 100 + 1; // New random number
        print_welcome_message();
        game_loop(secret_number);
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &replay);
    }

    printf("Thank you for playing! Have a great day!\n");
    return 0;
}