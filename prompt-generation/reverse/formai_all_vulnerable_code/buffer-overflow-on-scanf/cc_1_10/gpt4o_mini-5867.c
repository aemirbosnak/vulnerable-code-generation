//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int isWinner(char board[SIZE][SIZE], char player);
int isBoardFull(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void aiMove(char board[SIZE][SIZE]);
int getBestMove(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int row, int col, char symbol);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);

    printf("Welcome to Tic Tac Toe!\n");
    displayBoard(board);
    
    while (1) {
        playerMove(board);

        if (isWinner(board, PLAYER)) {
            printf("Congratulations! You win!\n");
            break;
        }

        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }

        aiMove(board);
        displayBoard(board);

        if (isWinner(board, AI)) {
            printf("AI wins! Better luck next time!\n");
            break;
        }

        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent board state:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int isWinner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[2][0] == player && board[1][1] == player && board[0][2] == player)) {
        return 1;
    }
    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY) return 0;
    return 1;
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    while (1) {
        printf("Your turn! Enter row (1-3) and column (1-3): ");
        if (scanf("%d %d", &row, &col) != 2) {
            while(getchar() != '\n'); // clear invalid input
            printf("That was not a valid input. Please try again.\n");
            continue;
        }
        row--; // Convert to 0 index
        col--; // Convert to 0 index
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            makeMove(board, row, col, PLAYER);
            break;
        }
        else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    printf("AI is making its move...\n");
    int move = getBestMove(board);
    int row = move / SIZE;
    int col = move % SIZE;
    makeMove(board, row, col, AI);
}

int getBestMove(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        int row = i / SIZE;
        int col = i % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = AI;
            if (isWinner(board, AI)) {
                board[row][col] = EMPTY; // undo move
                return i;
            }
            board[row][col] = EMPTY; // undo move
        }
    }
    for (int i = 0; i < SIZE * SIZE; i++) {
        int row = i / SIZE;
        int col = i % SIZE;
        if (board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            if (isWinner(board, PLAYER)) {
                board[row][col] = EMPTY; // undo move
                return i;
            }
            board[row][col] = EMPTY; // undo move
        }
    }
    while (1) {
        int move = rand() % (SIZE * SIZE);
        int row = move / SIZE;
        int col = move % SIZE;
        if (board[row][col] == EMPTY) {
            return move;
        }
    }
}

void makeMove(char board[SIZE][SIZE], int row, int col, char symbol) {
    board[row][col] = symbol;
}