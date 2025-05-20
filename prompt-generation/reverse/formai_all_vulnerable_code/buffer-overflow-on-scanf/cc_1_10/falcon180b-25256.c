//Falcon-180B DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns in the table
#define ROWS 10
#define COLS 10

int main() {
    // Initialize the table with random numbers
    int table[ROWS][COLS] = { { 0 } };
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = rand() % 100;
        }
    }

    // Print the table
    printf("Table:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // Ask the user to guess a value
    int guess;
    printf("Guess a value between 0 and 99: ");
    scanf("%d", &guess);

    // Check if the guess is correct
    int correct = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (table[i][j] == guess) {
                printf("Correct! The value is in row %d, column %d.\n", i, j);
                correct = 1;
                break;
            }
        }
        if (correct) {
            break;
        }
    }
    if (!correct) {
        printf("Incorrect. The value is not in the table.\n");
    }

    return 0;
}