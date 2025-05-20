//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4
#define MAX_ATTEMPTS 10

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE]) {
    char symbols[SIZE * SIZE / 2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Randomly assign pairs of characters to the board
            int randomIndex;
            do {
                randomIndex = rand() % (SIZE * SIZE / 2);
            } while (symbols[randomIndex] == '\0' && index < SIZE * SIZE / 2);

            if (index < SIZE * SIZE / 2 && (i * SIZE + j) % 2 == 0) {
                board[i][j] = symbols[randomIndex];
                symbols[randomIndex] = '\0'; // remove the symbol to ensure pairing
                index++;
            } else {
                board[i][j] = symbols[randomIndex];
            }
            display[i][j] = '*'; // Show unrevealed cards
        }
    }
}

void printBoard(char display[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

int revealCard(char board[SIZE][SIZE], char display[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return 0; // Invalid coordinates
    if (display[row][col] != '*')
        return 0; // Card already revealed

    display[row][col] = board[row][col];
    return 1; // Card revealed successfully
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    char display[SIZE][SIZE];
    int attempts = 0;
    int matches = 0;
    int totalPairs = SIZE * SIZE / 2;

    initializeBoard(board, display);

    printf("Welcome to the Memory Game!\n");
    printf("You have %d attempts to find all pairs.\n", MAX_ATTEMPTS);
    
    while (attempts < MAX_ATTEMPTS && matches < totalPairs) {
        printBoard(display);
        int row1, col1, row2, col2;
        
        printf("Enter coordinates for first card (row col): ");
        scanf("%d %d", &row1, &col1);
        if (!revealCard(board, display, row1, col1)) {
            printf("Invalid selection! Try again.\n");
            continue;
        }
        
        printBoard(display);

        printf("Enter coordinates for second card (row col): ");
        scanf("%d %d", &row2, &col2);
        if (!revealCard(board, display, row2, col2)) {
            printf("Invalid selection! Try again.\n");
            display[row1][col1] = '*'; // Hide the first card again
            continue;
        }

        if (board[row1][col1] == board[row2][col2]) {
            printf("You found a pair: %c!\n", board[row1][col1]);
            matches++;
        } else {
            printf("Not a match. Try again!\n");
            display[row1][col1] = display[row2][col2] = '*'; // Hide both cards
        }
        
        attempts++;
    }

    if (matches == totalPairs) {
        printf("Congratulations! You've found all pairs!\n");
    } else {
        printf("Game over! You've exhausted your attempts.\n");
    }

    printBoard(board); // Show the completed board
    return 0;
}