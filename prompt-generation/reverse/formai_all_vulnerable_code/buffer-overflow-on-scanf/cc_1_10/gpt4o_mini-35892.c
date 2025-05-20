//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4
#define PAIRS (GRID_SIZE * GRID_SIZE) / 2
#define EMPTY_CELL ' '

void initializeBoard(char board[GRID_SIZE][GRID_SIZE], char temp[PAIRS]) {
    int index = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (index < PAIRS) {
                board[i][j] = temp[index];
            } else {
                board[i][j] = EMPTY_CELL;
            }
            index++;
        }
    }
}

void shuffleBoard(char board[GRID_SIZE][GRID_SIZE]) {
    char temp[PAIRS];
    for (int i = 0; i < PAIRS; i++) {
        temp[i] = 'A' + i;
    }

    srand(time(NULL));

    // Shuffle the temp array
    for (int i = 0; i < PAIRS; i++) {
        int r = rand() % PAIRS;
        char t = temp[i];
        temp[i] = temp[r];
        temp[r] = t;
    }

    initializeBoard(board, temp);
}

void printBoard(char board[GRID_SIZE][GRID_SIZE]) {
    printf("   0 1 2 3\n");
    printf("  ---------\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n  ---------\n");
    }
}

int isMatch(char board[GRID_SIZE][GRID_SIZE], int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

void gameLoop() {
    char board[GRID_SIZE][GRID_SIZE];
    shuffleBoard(board);
    int score = 0;
    int revealed[GRID_SIZE][GRID_SIZE] = {0};
    int totalMatches = 0;

    while (totalMatches < PAIRS) {
        printBoard(board);
        
        int row1, col1, row2, col2;
        printf("Pick the first card (row col): ");
        scanf("%d %d", &row1, &col1);
        
        if(revealed[row1][col1]) {
            printf("Card already revealed! Pick again.\n");
            continue;
        }

        revealed[row1][col1] = 1;
        
        printBoard(board);
        
        printf("Pick the second card (row col): ");
        scanf("%d %d", &row2, &col2);
        
        if (revealed[row2][col2]) {
            printf("Card already revealed! Pick again.\n");
            revealed[row1][col1] = 0; // Un-reveal the first card before exiting
            continue;
        }

        revealed[row2][col2] = 1;
        
        printBoard(board);
        
        if (isMatch(board, row1, col1, row2, col2)) {
            printf("It's a match!\n");
            totalMatches++;
            score += 10;
        } else {
            printf("Not a match. Try again!\n");
            revealed[row1][col1] = 0; // Un-reveal first card
            revealed[row2][col2] = 0; // Un-reveal second card
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    printf("Your score: %d\n", score);
}

int main() {
    printf("Welcome to the Memory Game!\n");
    gameLoop();
    return 0;
}