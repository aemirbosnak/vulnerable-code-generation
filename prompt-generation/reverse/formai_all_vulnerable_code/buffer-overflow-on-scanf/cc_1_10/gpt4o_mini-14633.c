//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Function prototypes
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE], char player);
int checkDraw(char board[SIZE][SIZE]);
void playerTurn(char board[SIZE][SIZE], char player);
void computerTurn(char board[SIZE][SIZE], char player);

int main() {
    char board[SIZE][SIZE] = { {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY} };
    char currentPlayer = PLAYER_X;
    int gameOver = 0;

    printf("Welcome to Retro Tic-Tac-Toe!\n");
    
    while (!gameOver) {
        printBoard(board);
        if (currentPlayer == PLAYER_X) {
            printf("Player X's turn:\n");
            playerTurn(board, currentPlayer);
        } else {
            printf("Computer O's turn:\n");
            computerTurn(board, currentPlayer);
        }
        
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        } else if (checkDraw(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            gameOver = 1;
        }
        
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X; // Switch player
    }
    
    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE - 1; k++) printf("--");
            printf("-\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) return 0;
        }
    }
    return 1;
}

void playerTurn(char board[SIZE][SIZE], char player) {
    int row, col;
    while (1) {
        printf("Enter row (0, 1, 2) and column (0, 1, 2) (space separated): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void computerTurn(char board[SIZE][SIZE], char player) {
    srand(time(NULL));
    int row, col;
    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = player;
            break;
        }
    }
}