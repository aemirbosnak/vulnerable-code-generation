//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // The grid size will be 4x4
#define TOTAL_PAIRS (SIZE * SIZE) / 2

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void shuffleBoard(char board[SIZE][SIZE], char symbols[TOTAL_PAIRS]);
void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]);
int isMatch(char first, char second);
void playGame(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char symbols[TOTAL_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int revealed[SIZE][SIZE] = {0}; // 0 -> hidden, 1 -> revealed

    initializeBoard(board);
    shuffleBoard(board, symbols);
    
    printf("Welcome to the Memory Game!\n");
    playGame(board);
    
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void shuffleBoard(char board[SIZE][SIZE], char symbols[TOTAL_PAIRS]) {
    char tempBoard[SIZE][SIZE];
    int index = 0;

    // Create an array with pairs of symbols
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        tempBoard[index / SIZE][index % SIZE] = symbols[i % TOTAL_PAIRS];
        index++;
    }

    // Shuffle the board
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int randI = rand() % SIZE;
            int randJ = rand() % SIZE;
            char temp = tempBoard[i][j];
            tempBoard[i][j] = tempBoard[randI][randJ];
            tempBoard[randI][randJ] = temp;
        }
    }

    // Copy shuffled values to the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }
}

void printBoard(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("   0 1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int isMatch(char first, char second) {
    return first == second;
}

void playGame(char board[SIZE][SIZE]) {
    int revealed[SIZE][SIZE] = {0};
    int attempts = 0, pairsFound = 0;

    while (pairsFound < TOTAL_PAIRS) {
        printBoard(board, revealed);
        printf("Attempts: %d | Pairs Found: %d\n", attempts, pairsFound);
        int row1, col1, row2, col2;

        // Get first choice
        printf("Select first card (row col): ");
        scanf("%d %d", &row1, &col1);
        revealed[row1][col1] = 1;
        printBoard(board, revealed);

        // Get second choice
        printf("Select second card (row col): ");
        scanf("%d %d", &row2, &col2);
        revealed[row2][col2] = 1;
        printBoard(board, revealed);

        attempts++;

        // Check for match
        if (isMatch(board[row1][col1], board[row2][col2])) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match, try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
    }

    printf("Congratulations! You've found all pairs in %d attempts!\n", attempts);
}