//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '
#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;
}

int checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    
    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY)
                return 0;
    return 1;
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER_X;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    int row, col;
    // Simple AI algorithm: Random move
    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = PLAYER_O;
            break;
        }
    }
}

void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    int turn = 0;

    while (1) {
        printBoard(board);
        
        if (turn % 2 == 0) {
            playerMove(board);
        } else {
            printf("AI is making a move...\n");
            aiMove(board);
        }

        if (checkWin(board, PLAYER_X)) {
            printBoard(board);
            printf("Congratulations! You win!\n");
            break;
        } else if (checkWin(board, PLAYER_O)) {
            printBoard(board);
            printf("AI wins! Better luck next time.\n");
            break;
        } else if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        turn++;
    }
}

int main() {
    printf("Welcome to Shape-Shifting Tic Tac Toe!\n");
    printf("You are X, and the AI is O.\n");
    playGame();
    return 0;
}