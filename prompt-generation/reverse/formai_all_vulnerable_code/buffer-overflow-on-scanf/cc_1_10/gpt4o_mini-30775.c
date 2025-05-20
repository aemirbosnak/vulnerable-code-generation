//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // 4x4 board
#define PAIRS (SIZE * SIZE) / 2

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE]) {
    char symbols[PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int idx = 0;
    
    // Fill board with pairs of symbols
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (idx < PAIRS) {
                board[i][j] = symbols[idx / 2]; // Each symbol twice
                idx++;
            }
        }
    }

    // Shuffle the symbols on the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r1 = rand() % SIZE;
            int r2 = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[r1][r2];
            board[r1][r2] = temp;
        }
    }

    // Initialize display board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            display[i][j] = '*'; // Hidden state
        }
    }
}

void displayBoard(char display[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE];
    char display[SIZE][SIZE];
    int uncoveredPairs = 0;
    int totalPairs = PAIRS;

    initializeBoard(board, display);

    while (uncoveredPairs < totalPairs) {
        displayBoard(display);

        int x1, y1, x2, y2;
        printf("Enter coordinates of the first card (row column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates of the second card (row column): ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE ||
            x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE ||
            (x1 == x2 && y1 == y2)) {
            printf("Invalid input, try again.\n");
            continue;
        }

        // Uncover the chosen cards
        display[x1][y1] = board[x1][y1];
        display[x2][y2] = board[x2][y2];

        // Check for a match
        if (board[x1][y1] == board[x2][y2]) {
            printf("It's a match!\n");
            uncoveredPairs++;
        } else {
            printf("Not a match. Try again!\n");
            // Hide cards again after a short pause
            display[x1][y1] = '*';
            display[x2][y2] = '*';
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}