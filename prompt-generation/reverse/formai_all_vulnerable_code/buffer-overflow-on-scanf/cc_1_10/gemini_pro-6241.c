//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to play a guessing game
void play_guessing_game() {
    // Generate a random number between 1 and 100
    int secret_number = rand_range(1, 100);

    // Get the player's guess
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);

    // Check if the player's guess is correct
    while (guess != secret_number) {
        // If the player's guess is too low, tell them to guess higher
        if (guess < secret_number) {
            printf("Your guess is too low. Guess higher: ");
            scanf("%d", &guess);
        } 
        // If the player's guess is too high, tell them to guess lower
        else {
            printf("Your guess is too high. Guess lower: ");
            scanf("%d", &guess);
        }
    }

    // If the player's guess is correct, tell them they won
    printf("Congratulations! You guessed the correct number: %d\n", secret_number);
}

// Function to play a multiplication game
void play_multiplication_game() {
    // Generate two random numbers between 1 and 10
    int num1 = rand_range(1, 10);
    int num2 = rand_range(1, 10);

    // Get the player's answer
    int answer;
    printf("What is %d multiplied by %d? ", num1, num2);
    scanf("%d", &answer);

    // Check if the player's answer is correct
    if (answer == num1 * num2) {
        printf("Correct!\n");
    } 
    // If the player's answer is incorrect, tell them the correct answer
    else {
        printf("Incorrect. The correct answer is %d\n", num1 * num2);
    }
}

// Function to play a division game
void play_division_game() {
    // Generate two random numbers between 1 and 10
    int num1 = rand_range(1, 10);
    int num2 = rand_range(1, 10);

    // Get the player's answer
    int answer;
    printf("What is %d divided by %d? ", num1, num2);
    scanf("%d", &answer);

    // Check if the player's answer is correct
    if (answer == num1 / num2) {
        printf("Correct!\n");
    } 
    // If the player's answer is incorrect, tell them the correct answer
    else {
        printf("Incorrect. The correct answer is %d\n", num1 / num2);
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's choice of game
    int choice;
    printf("Which game would you like to play?\n");
    printf("1. Guessing game\n");
    printf("2. Multiplication game\n");
    printf("3. Division game\n");
    scanf("%d", &choice);

    // Play the user's chosen game
    switch (choice) {
        case 1:
            play_guessing_game();
            break;
        case 2:
            play_multiplication_game();
            break;
        case 3:
            play_division_game();
            break;
        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
    }

    return 0;
}