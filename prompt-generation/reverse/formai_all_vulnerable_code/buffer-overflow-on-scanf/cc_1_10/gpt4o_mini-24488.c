//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4         // Size of the game board
#define EMPTY ' '      // Representation of an empty cell
#define PLAYER 'O'     // Representation of the player
#define COMPUTER 'X'   // Representation of the computer

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int isWinner(char board[SIZE][SIZE], char player);
int isBoardFull(char board[SIZE][SIZE]);
int playerMove(char board[SIZE][SIZE]);
int computerMove(char board[SIZE][SIZE]);
void playGame();

int main() {
    srand(time(NULL)); // Seed the random number generator
    playGame();
    return 0;
}

// Function to initialize the game board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// Function to print the game board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("----");
                if (k < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int isWinner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player)) {
            return 1;
        }
    }
    
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player) ||
        (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player)) {
        return 1;
    }

    return 0;
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to handle player's move
int playerMove(char board[SIZE][SIZE]) {
    int row, col;

    while (1) {
        printf("\nEnter your move (row and column 0-3): ");
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
            printf("Invalid move. Try again.\n");
        } else {
            board[row][col] = PLAYER;
            break;
        }
    }
    return 0;
}

// Function to handle computer's move
int computerMove(char board[SIZE][SIZE]) {
    int row, col;

    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if (board[row][col] == EMPTY) {
            board[row][col] = COMPUTER;
            printf("Computer chose row %d and column %d.\n", row, col);
            break;
        }
    }
    return 0;
}

// Function to control the game flow
void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    printBoard(board);

    while (1) {
        playerMove(board);
        printBoard(board);
        if (isWinner(board, PLAYER)) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }
        
        computerMove(board);
        printBoard(board);
        if (isWinner(board, COMPUTER)) {
            printf("Computer wins! Better luck next time.\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }
    }
}