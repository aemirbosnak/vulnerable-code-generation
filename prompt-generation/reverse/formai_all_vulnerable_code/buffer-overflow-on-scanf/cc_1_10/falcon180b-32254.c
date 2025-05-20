//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, randomNum;
    char playAgain;
    int score = 0;
    int lives = 3;

    // Initialize random seed
    srand(time(NULL));

    // Game loop
    while (lives > 0) {
        // Print game instructions
        printf("Welcome to the Text-Based Adventure Game!\n");
        printf("You have %d lives left.\n", lives);
        printf("Please choose an option:\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Go forward\n");
        printf("4. Quit\n");

        // Get user input
        scanf("%d", &choice);

        // Generate a random number between 1 and 3
        randomNum = rand() % 3 + 1;

        // Check user choice
        if (choice == 1 && randomNum!= 2) {
            printf("You went left.\n");
            score++;
        } else if (choice == 2 && randomNum!= 1) {
            printf("You went right.\n");
            score++;
        } else if (choice == 3 && randomNum!= 2) {
            printf("You went forward.\n");
            score++;
        } else {
            printf("You hit a wall and lost a life.\n");
            lives--;
        }

        // Ask user if they want to play again
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &playAgain);

        // Check if user wants to play again
        if (playAgain == 'y' || playAgain == 'Y') {
            lives = 3;
            score = 0;
        } else {
            printf("Thank you for playing! Your final score is: %d\n", score);
            break;
        }
    }

    return 0;
}