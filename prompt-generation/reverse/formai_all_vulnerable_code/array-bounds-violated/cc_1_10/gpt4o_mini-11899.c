//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE], char display[BOARD_SIZE][BOARD_SIZE]) {
    char symbols[NUM_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    // Fill the board with pairs of symbols
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (index < NUM_PAIRS) {
                board[i][j] = symbols[index];
                board[i][++j] = symbols[index]; // duplicate for pairs
                index++;
            }
        }
    }
    
    // Shuffle the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int rand_i = rand() % BOARD_SIZE;
            int rand_j = rand() % BOARD_SIZE;

            // Swap the elements
            char temp = board[i][j];
            board[i][j] = board[rand_i][rand_j];
            board[rand_i][rand_j] = temp;
        }
    }

    // Initialize display board with asterisks
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            display[i][j] = '*';
        }
    }
}

void displayBoard(char display[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

int checkForMatch(char board[BOARD_SIZE][BOARD_SIZE], char display[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    if (board[x1][y1] == board[x2][y2]) {
        display[x1][y1] = board[x1][y1];
        display[x2][y2] = board[x2][y2];
        return 1; // Match found
    }
    return 0; // No match
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];
    char display[BOARD_SIZE][BOARD_SIZE];
    int attempts = 0;
    int pairsFound = 0;
    
    initializeBoard(board, display);

    while (pairsFound < NUM_PAIRS) {
        displayBoard(display);
        printf("Enter coordinates of first selection (row and column): ");
        int x1, y1;
        scanf("%d %d", &x1, &y1);
        
        display[x1][y1] = board[x1][y1]; // Show first choice
        displayBoard(display);

        printf("Enter coordinates of second selection (row and column): ");
        int x2, y2;
        scanf("%d %d", &x2, &y2);

        display[x2][y2] = board[x2][y2]; // Show second choice
        displayBoard(display);

        attempts++;
        if (checkForMatch(board, display, x1, y1, x2, y2)) {
            printf("You found a match!\n");
            pairsFound++;
        } else {
            printf("No match found. Try again.\n");
            // Hide the choices again after a moment, for visibility you can pause if needed
            display[x1][y1] = '*';
            display[x2][y2] = '*';
        }

        printf("Attempts: %d\n", attempts);
    }

    printf("Congratulations! You've found all pairs in %d attempts.\n", attempts);
    return 0;
}