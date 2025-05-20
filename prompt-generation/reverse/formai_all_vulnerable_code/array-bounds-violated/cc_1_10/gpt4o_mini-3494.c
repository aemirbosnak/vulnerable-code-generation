//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4
#define NUM_PAIRS (SIZE * SIZE) / 2

typedef struct {
    char symbol;
    int revealed;
} Card;

void initializeBoard(Card board[SIZE][SIZE]);
void shuffleBoard(Card board[SIZE][SIZE]);
void printBoard(Card board[SIZE][SIZE]);
int revealCard(Card board[SIZE][SIZE], int row, int col);
int checkForMatch(Card board[SIZE][SIZE], int row1, int col1, int row2, int col2);
int isGameWon(Card board[SIZE][SIZE]);
void clearScreen();

int main() {
    Card board[SIZE][SIZE];
    initializeBoard(board);
    shuffleBoard(board);

    int row1, col1, row2, col2;
    int totalAttempts = 0;
    
    while (!isGameWon(board)) {
        clearScreen();
        printBoard(board);
        printf("Enter coordinates of the first card (row and column, 0-indexed): ");
        scanf("%d %d", &row1, &col1);
        
        if (revealCard(board, row1, col1)) {
            clearScreen();
            printBoard(board);
            printf("Enter coordinates of the second card (row and column, 0-indexed): ");
            scanf("%d %d", &row2, &col2);

            if (revealCard(board, row2, col2)) {
                totalAttempts++;
                if (checkForMatch(board, row1, col1, row2, col2)) {
                    printf("It's a match!\n");
                } else {
                    printf("Not a match. Try again!\n");
                    sleep(2);
                    board[row1][col1].revealed = 0;
                    board[row2][col2].revealed = 0;
                }
            }
        }
    }
    printf("Congratulations! You've found all the pairs in %d attempts!\n", totalAttempts);
    return 0;
}

void initializeBoard(Card board[SIZE][SIZE]) {
    char symbols[NUM_PAIRS] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G'};
    int index = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].symbol = symbols[index];
            board[i][j].revealed = 0;
            index++;
        }
    }
}

void shuffleBoard(Card board[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int r1 = rand() % SIZE;
        int c1 = rand() % SIZE;
        int r2 = rand() % SIZE;
        int c2 = rand() % SIZE;

        Card temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
}

void printBoard(Card board[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].revealed) {
                printf("[%c] ", board[i][j].symbol);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int revealCard(Card board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        printf("Invalid coordinates! Try again.\n");
        return 0;
    }

    if (board[row][col].revealed) {
        printf("Card already revealed! Try another card.\n");
        return 0;
    }
    
    board[row][col].revealed = 1;
    return 1;
}

int checkForMatch(Card board[SIZE][SIZE], int row1, int col1, int row2, int col2) {
    if (board[row1][col1].symbol == board[row2][col2].symbol) {
        return 1;
    }
    return 0;
}

int isGameWon(Card board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].revealed == 0) {
                return 0; // Game not won yet
            }
        }
    }
    return 1; // All cards revealed, game won
}

void clearScreen() {
    printf("\033[H\033[J");
}