//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear the terminal
void clearScreen() {
    system("clear || cls");
}

int main() {
    // Welcome message for the user
    printf("Welcome to the Energy Game!\n");

    // Initialize random seed
    srand(time(NULL));

    // Variables to keep track of the energy level and score
    int energyLevel = 100, score = 0;

    // Loop until energy level reaches zero
    while (energyLevel > 0) {
        // Clear the screen for new output
        clearScreen();

        // Generate random number between 1 and 10
        int randomNumber = rand() % 10 + 1;

        // Display energy level and score
        printf("Energy Level: %d\n", energyLevel);
        printf("Score: %d\n", score);

        // Display the instructions
        printf("\nPress any key to generate energy! (Q to quit)\n");

        // Get input from user
        char input;
        scanf(" %c", &input);

        // Check if user wants to quit
        if (input == 'Q' || input == 'q') {
            clearScreen();
            printf("Thanks for playing! Your final score is %d.\n", score);
            return 0;
        }

        // Increase energy level by random number
        energyLevel += randomNumber;

        // Increase score by 10
        score += 10;
    }

    // Clear the screen for final output
    clearScreen();

    // Display game over message and final score
    printf("Game over! Your final score is %d. Thanks for playing!\n", score);

    return 0;
}