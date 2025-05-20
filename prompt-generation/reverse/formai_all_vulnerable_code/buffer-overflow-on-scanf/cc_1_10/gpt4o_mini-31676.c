//GPT-4o-mini DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to safely get user input
void safe_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = 0;
}

// Function to generate a random number within a specified range
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to display the menu
void display_menu() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("1. Start Game\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to start the game
void start_game() {
    int number_to_guess, user_guess, attempts = 0, max_attempts = 5;
    char play_again[4];

    // Seed the random number generator
    srand(time(NULL));
    number_to_guess = random_number(1, 100);

    printf("I have picked a number between 1 and 100. You have %d attempts to guess it!\n", max_attempts);

    while (attempts < max_attempts) {
        printf("Enter your guess: ");
        if (scanf("%d", &user_guess) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue; // skip to the next iteration
        }
        attempts++;

        if (user_guess < 1 || user_guess > 100) {
            printf("Please guess a number within the valid range (1-100).\n");
            continue;
        }

        if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number in %d attempts!\n", attempts);
            break;
        }
    }

    if (attempts >= max_attempts) {
        printf("Sorry! You've used all your attempts. The number was %d.\n", number_to_guess);
    }

    // Ask if the user wants to play again
    printf("Do you want to play again? (yes/no): ");
    safe_input(play_again, sizeof(play_again));
    if (strncmp(play_again, "yes", 3) == 0) {
        start_game(); // Restart the game
    } else {
        printf("Thanks for playing!\n");
    }
}

// Main function
int main() {
    int option;

    do {
        display_menu();
        if (scanf("%d", &option) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            option = 0; // reset option to an invalid value
            continue; // skip to the next iteration
        }

        switch (option) {
            case 1:
                start_game();
                break;
            case 2:
                printf("Exiting the game. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (option != 2);

    return 0;
}