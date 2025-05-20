//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 4
#define MAX_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2

// Function prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void shuffleBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]);
int checkMatch(char board[BOARD_SIZE][BOARD_SIZE], int firstX, int firstY, int secondX, int secondY);
int isGameWon(int revealed[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int moves = 0;
    int firstX, firstY, secondX, secondY;

    printf("🌟 Welcome to the C Memory Game! 🌟\n");
    printf("Match the pairs! Let's have some fun!\n");
    
    initializeBoard(board);
    shuffleBoard(board);
    
    while (!isGameWon(revealed)) {
        printBoard(board, revealed);
        printf("Choose the first card (row, column): ");
        scanf("%d %d", &firstX, &firstY);
        
        if (revealed[firstX][firstY]) {
            printf("That card is already revealed, try again!\n");
            continue;
        }
        
        revealed[firstX][firstY] = 1;
        printBoard(board, revealed);
        
        printf("Choose the second card (row, column): ");
        scanf("%d %d", &secondX, &secondY);
        
        if (revealed[secondX][secondY] || (firstX == secondX && firstY == secondY)) {
            printf("Invalid choice, try again!\n");
            revealed[firstX][firstY] = 0;
            continue;
        }

        revealed[secondX][secondY] = 1;
        printBoard(board, revealed);
        
        if (checkMatch(board, firstX, firstY, secondX, secondY)) {
            printf("🎉 You found a match! 🎉\n");
        } else {
            printf("😢 No match! Try again.\n");
            revealed[firstX][firstY] = 0;
            revealed[secondX][secondY] = 0;
        }
        moves++;
    }

    printf("🎊 Congratulations! You've won the game in %d moves! 🎊\n", moves);
    return 0;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    char symbols[MAX_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    // Fill the board with pairs of symbols
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = symbols[index / 2]; // Pair symbols
            if (index < MAX_PAIRS - 1) {
                index++;
            } else {
                index = 0; // Reset for the next pair
            }
        }
    }
}

void shuffleBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int randX = rand() % BOARD_SIZE;
            int randY = rand() % BOARD_SIZE;
            // Swap the current element with a random element
            char temp = board[i][j];
            board[i][j] = board[randX][randY];
            board[randX][randY] = temp;
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" ? ");
            }
        }
        printf("\n");
    }
}

int checkMatch(char board[BOARD_SIZE][BOARD_SIZE], int firstX, int firstY, int secondX, int secondY) {
    return board[firstX][firstY] == board[secondX][secondY];
}

int isGameWon(int revealed[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!revealed[i][j]) {
                return 0; // Not yet won
            }
        }
    }
    return 1; // All cards revealed
}