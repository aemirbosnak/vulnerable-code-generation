//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PLAYERS 4 // Maximum number of players in the game

// Function to print the menu options of the calculator
void printMenu() {
    printf("\nWelcome to the Multiplayer Calculator!\n\n");
    printf("Menu:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    printf("7. Logarithm\n");
    printf("8. Exit\n");
}

// Function to get the input values for the operation
void getInput(double *a, double *b) {
    printf("Enter the first number: ");
    scanf("%lf", a);
    printf("Enter the second number: ");
    scanf("%lf", b);
}

int main() {
    int playerCount = 0;

    // Ask for the number of players in the game
    while (playerCount == 0 || playerCount > MAX_PLAYERS) {
        printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &playerCount);
    }

    // Initialize an array to keep track of the scores of each player
    int *scores = calloc(playerCount, sizeof(int));

    // Initialize the game loop
    int running = 1;
    int currentPlayer = 0;

    while (running) {
        // Print the menu and get the chosen operation
        printMenu();
        int choice;
        printf("\nPlayer %d, choose an operation: ", currentPlayer + 1);
        scanf("%d", &choice);

        // Perform the chosen operation and update the score of the current player
        double a, b, result;
        switch (choice) {
            case 1: // Add
                getInput(&a, &b);
                result = a + b;
                printf("Result: %lf\n", result);
                scores[currentPlayer]++;
                break;

            case 2: // Subtract
                getInput(&a, &b);
                result = a - b;
                printf("Result: %lf\n", result);
                scores[currentPlayer]++;
                break;

            case 3: // Multiply
                getInput(&a, &b);
                result = a * b;
                printf("Result: %lf\n", result);
                scores[currentPlayer]++;
                break;

            case 4: // Divide
                getInput(&a, &b);
                result = a / b;
                printf("Result: %lf\n", result);
                scores[currentPlayer]++;
                break;

            case 5: // Power
                getInput(&a, &b);
                result = pow(a, b);
                printf("Result: %lf\n", result);
                scores[currentPlayer]++;
                break;

            case 6: // Square root
                printf("Enter a number: ");
                scanf("%lf", &a);
                result = sqrt(a);
                printf("Result: %lf\n", result);
                scores[currentPlayer]++;
                break;

            case 7: // Logarithm
                printf("Enter a number: ");
                scanf("%lf", &a);
                printf("Enter the base: ");
                scanf("%lf", &b);
                result = log(a) / log(b);
                printf("Result: %lf\n", result);
                scores[currentPlayer]++;
                break;

            case 8: // Exit
                running = 0;
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        // Print the scores of each player
        printf("\nScores:\n");
        for (int i = 0; i < playerCount; i++) {
            printf("Player %d: %d\n", i + 1, scores[i]);
        }

        // Move on to the next player
        currentPlayer++;
        if (currentPlayer == playerCount) {
            currentPlayer = 0;
        }
    }

    free(scores);
    return 0;
}