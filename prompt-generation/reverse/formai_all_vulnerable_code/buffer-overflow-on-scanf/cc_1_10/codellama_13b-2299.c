//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 6
#define NUM_COLS 7

// Function prototypes
void printTable(int table[NUM_ROWS][NUM_COLS]);
void generateRandomValues(int table[NUM_ROWS][NUM_COLS]);
int getUserInput();

int main() {
    int table[NUM_ROWS][NUM_COLS];

    // Generate random values for the table
    generateRandomValues(table);

    // Print the table
    printTable(table);

    // Get user input
    int userInput = getUserInput();

    // Print the result
    printf("You have won! Your input was %d.\n", userInput);

    return 0;
}

// Function definitions
void printTable(int table[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void generateRandomValues(int table[NUM_ROWS][NUM_COLS]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            table[i][j] = rand() % 100;
        }
    }
}

int getUserInput() {
    int input;
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &input);
    return input;
}