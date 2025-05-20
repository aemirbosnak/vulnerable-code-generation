//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int isWinner(char board[SIZE][SIZE], char player);
int isBoardFull(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int row, int col, char player);
void getPlayerMove(int *row, int *col);
void clearInputBuffer(); 

int main() {
    char board[SIZE][SIZE];
    char player = 'X';
    int row, col;
    int moves = 0;

    initializeBoard(board);

    while (1) {
        printBoard(board);
        getPlayerMove(&row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        makeMove(board, row, col, player);
        moves++;

        if (isWinner(board, player)) {
            printBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            printf("The game is a draw.\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X'; // Switch player
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
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

int isWinner(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Check anti-diagonal

    return 0; // No winner
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return 0; // Found an empty space
    return 1; // Board is full
}

void makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    board[row][col] = player;
}

void getPlayerMove(int *row, int *col) {
    printf("Enter your move (row and column: 0, 1, or 2): ");
    clearInputBuffer();
    if (scanf("%d %d", row, col) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        clearInputBuffer();
        *row = -1; // Invalid row
        *col = -1; // Invalid column
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}