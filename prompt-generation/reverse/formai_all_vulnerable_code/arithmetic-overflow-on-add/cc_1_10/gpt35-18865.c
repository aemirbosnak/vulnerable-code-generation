//FormAI DATASET v1.0 Category: Table Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set up the game
    int table[4][4];
    int score = 0;
    srand(time(0));

    // Fill the table with random numbers
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            table[i][j] = rand() % 10;
        }
    }

    // Print the table
    printf("Welcome to the C Table Game!\n");
    printf("Current score: %d\n", score);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // Play the game
    int row, col;
    printf("Enter the row and column of the number you want to change: ");
    scanf("%d %d", &row, &col);
    printf("Enter the new number: ");
    scanf("%d", &table[row][col]);

    // Update the score
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            score += table[i][j];
        }
    }

    // Print the updated table and score
    printf("Updated table:\n");
    printf("Current score: %d\n", score);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // End the game
    printf("Thanks for playing the C Table Game!\n");

    return 0;
}