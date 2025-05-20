//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
    // Declare variables to store user input
    char name[MAX_NAME_LENGTH];
    int age;

    // Print a welcome message
    printf("Welcome to the Age Calculator!\n");

    // Ask the user for their name
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Ask the user for their age
    printf("How old are you? ");
    scanf("%d", &age);

    // Check for invalid input
    if (age < 0 || age > MAX_AGE) {
        printf("Invalid age! Please enter a positive integer less than or equal to %d.\n", MAX_AGE);
        return 1;
    }

    // Calculate the user's age in years, months, and days
    int years = age / 365;
    int months = (age % 365) / 30;
    int days = (age % 365) % 30;

    // Print the user's age in years, months, and days
    printf("You are %d years, %d months, and %d days old.\n", years, months, days);

    // Ask the user if they want to play a game
    printf("Do you want to play a game? (y/n) ");
    char game_input;
    scanf(" %c", &game_input);

    // If the user wants to play a game, continue executing the program
    if (game_input == 'y' || game_input == 'Y') {
        // Print a fun message
        printf("Let's get this party started! \n");

        // Play a game of "Guess My Number"
        int secret_number = 542;
        int guess = 0;

        do {
            // Print a question about the secret number
            printf("I'm thinking of a number between 1 and 100. Can you guess it? ");

            // Ask the user for their guess
            scanf("%d", &guess);

            // Check if the user guessed the correct number
            if (guess == secret_number) {
                printf("You guessed it! The secret number was %d.\n", secret_number);
                break;
            }

            // If the user didn't guess the correct number, print a hint
            else {
                printf("Too high! The secret number is lower than %d. Keep trying...\n", guess);
            }
        } while (guess != secret_number);
    }

    return 0;
}