//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Size of the board (4x4)
#define PAIRS (SIZE * SIZE / 2)

void initializeBoard(int board[SIZE][SIZE]) {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (num <= PAIRS) {
                board[i][j] = num;
                if (j + 1 < SIZE && num < PAIRS) {
                    board[i][++j] = num;
                }
                num++;
            } else {
                board[i][j] = 0; // Empty spot
            }
        }
    }
}

void shuffleBoard(int board[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int random_i = rand() % SIZE;
            int random_j = rand() % SIZE;
            int temp = board[i][j];
            board[i][j] = board[random_i][random_j];
            board[random_i][random_j] = temp;
        }
    }
}

void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

bool checkMatch(int board[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

bool isGameWon(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false}; 

    // Initialize, shuffle, and present the board to the players
    initializeBoard(board);
    shuffleBoard(board);
    
    printf("Welcome to the Memory Game, inspired by the early days of computing!\n");
    printf("Match the pairs of numbers to win the game!\n\n");

    int x1, y1, x2, y2;
    while (!isGameWon(revealed)) {
        printBoard(board, revealed);
        
        printf("Select the coordinates of the first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        printf("Select the coordinates of the second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        
        // Validate the coordinates
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        // Reveal the selected cards
        revealed[x1][y1] = true;
        revealed[x2][y2] = true;
        printBoard(board, revealed);

        // Check if they match
        if (checkMatch(board, x1, y1, x2, y2)) {
            printf("It's a match!\n");
        } else {
            printf("No match, flipping cards back...\n");
            revealed[x1][y1] = false;
            revealed[x2][y2] = false;
        }

        printf("\n");
    }

    printBoard(board, revealed);
    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}