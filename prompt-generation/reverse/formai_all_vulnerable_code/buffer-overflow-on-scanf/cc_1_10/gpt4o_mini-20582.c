//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[3][3];

// Function Prototypes
void initializeBoard();
void displayBoard();
int checkWinner();
void playerTurn();
void aiTurn();
int isBoardFull();
void makeMove(int row, int col, char player);
void getBestMove(int *row, int *col);

int main() {
    int winner = 0;
    initializeBoard();
    
    printf("Welcome to Tic Tac Toe!\n");
    displayBoard();
    
    while (winner == 0 && !isBoardFull()) {
        playerTurn();
        winner = checkWinner();
        if (winner || isBoardFull()) break;
        
        aiTurn();
        displayBoard();
        winner = checkWinner();
    }
    
    if (winner == PLAYER) {
        printf("Congratulations! You win!\n");
    } else if (winner == AI) {
        printf("The AI has won! Better luck next time.\n");
    } else {
        printf("It's a draw!\n");
    }
    
    return 0;
}

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == PLAYER) ? PLAYER : AI;
        }

        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == PLAYER) ? PLAYER : AI;
        }
    }

    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == PLAYER) ? PLAYER : AI;
    }

    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == PLAYER) ? PLAYER : AI;
    }
    
    return 0; // No winner
}

void playerTurn() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column: 0-2): ");
        scanf("%d %d", &row, &col);
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            makeMove(row, col, PLAYER);
            displayBoard();
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiTurn() {
    int row, col;
    getBestMove(&row, &col);
    makeMove(row, col, AI);
    printf("AI has made its move!\n");
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(int row, int col, char player) {
    board[row][col] = player;
}

void getBestMove(int *row, int *col) {
    // Naive strategy: pick first empty spot
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}