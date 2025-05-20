//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // Size of the board (4x4)
#define NUM_PAIRS (SIZE * SIZE) / 2

typedef struct {
    char symbol;
    int isFlipped;
} Card;

void initializeBoard(Card board[SIZE][SIZE]);
void printBoard(Card board[SIZE][SIZE]);
void shuffleBoard(Card board[SIZE][SIZE]);
void playGame(Card board[SIZE][SIZE]);
int flipCard(Card board[SIZE][SIZE], int row, int col);
int isGameOver(Card board[SIZE][SIZE]);

int main() {
    Card board[SIZE][SIZE];
    initializeBoard(board);
    shuffleBoard(board);
    playGame(board);
    return 0;
}

void initializeBoard(Card board[SIZE][SIZE]) {
    char symbols[NUM_PAIRS] = { 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D',
                                 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H' };
    srand(time(NULL));
    
    // Initialize cards
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].symbol = symbols[i * SIZE + j];
            board[i][j].isFlipped = 0; // 0 means unflipped
        }
    }
}

void shuffleBoard(Card board[SIZE][SIZE]) {
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int r1 = rand() % SIZE;
        int c1 = rand() % SIZE;
        int r2 = rand() % SIZE;
        int c2 = rand() % SIZE;

        // Swap cards
        Card temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
}

void printBoard(Card board[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].isFlipped) {
                printf(" %c ", board[i][j].symbol);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

void playGame(Card board[SIZE][SIZE]) {
    int firstRow, firstCol, secondRow, secondCol;
    int firstCard, secondCard;

    while (!isGameOver(board)) {
        printBoard(board);
        printf("Pick the first card (row col): ");
        scanf("%d %d", &firstRow, &firstCol);
        if (flipCard(board, firstRow, firstCol) == -1) continue;

        printBoard(board);
        printf("Pick the second card (row col): ");
        scanf("%d %d", &secondRow, &secondCol);
        if (flipCard(board, secondRow, secondCol) == -1) {
            board[firstRow][firstCol].isFlipped = 0; // Unflip if invalid
            continue;
        }

        if (board[firstRow][firstCol].symbol == board[secondRow][secondCol].symbol) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Try again!\n");
            // Unflip the cards after a short delay
            board[firstRow][firstCol].isFlipped = 0;
            board[secondRow][secondCol].isFlipped = 0;
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
}

int flipCard(Card board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        printf("Invalid position! Please choose again.\n");
        return -1;
    }
    
    if (board[row][col].isFlipped) {
        printf("Card already flipped! Please choose another card.\n");
        return -1;
    }

    board[row][col].isFlipped = 1; // Flip the card
    return 0;
}

int isGameOver(Card board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].isFlipped) {
                return 0; // Game is not over
            }
        }
    }
    return 1; // Game is over
}