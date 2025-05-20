//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // Size of the puzzle, it will be 4x4
#define MAX_PAIRED_NUMBERS (SIZE * SIZE) / 2

char board[SIZE][SIZE];
char display[SIZE][SIZE];
int pairsFound = 0;

// Function to initialize the board with random numbers
void initializeBoard() {
    int numbers[MAX_PAIRED_NUMBERS];
    for (int i = 0; i < MAX_PAIRED_NUMBERS; i++) {
        numbers[i] = i + 1;
    }

    // Fill the board with pairs of random numbers
    for (int i = 0; i < MAX_PAIRED_NUMBERS; i++) {
        numbers[i] *= 2; // To ensure we have distinct pairs
    }

    // Shuffle the numbers on the board
    srand(time(NULL));
    for (int i = 0; i < MAX_PAIRED_NUMBERS; i++) {
        int j = rand() % MAX_PAIRED_NUMBERS;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Place the numbers on the board
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[index % MAX_PAIRED_NUMBERS];
            display[i][j] = '*'; // Display hidden initially
            index++;
        }
    }
}

// Function to display the current state of the game
void displayBoard() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the selected cells match
int checkMatch(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

// Function to reveal a cell
void revealCell(int x, int y) {
    display[x][y] = board[x][y];
}

int main() {
    initializeBoard();
    int x1, y1, x2, y2;

    printf("Welcome to the Memory Game!\n");
    printf("Try to find all the pairs by selecting two cells each turn.\n");

    while (pairsFound < MAX_PAIRED_NUMBERS) {
        displayBoard();
        printf("Enter the coordinates (x1 y1) of the first cell (0-3): ");
        scanf("%d %d", &x1, &y1);

        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || display[x1][y1] != '*') {
            printf("Invalid input! Please try again.\n");
            continue;
        }

        revealCell(x1, y1);
        displayBoard();

        printf("Enter the coordinates (x2 y2) of the second cell (0-3): ");
        scanf("%d %d", &x2, &y2);

        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || (x2 == x1 && y2 == y1) || display[x2][y2] != '*') {
            printf("Invalid input! Please try again.\n");
            display[x1][y1] = '*'; // Hide revealed cell
            continue;
        }

        revealCell(x2, y2);
        displayBoard();

        if (checkMatch(x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            // Hide the cells again after a brief pause
            display[x1][y1] = '*';
            display[x2][y2] = '*';
        }
    }

    printf("Congratulations! You've found all the pairs!\n");
    return 0;
}