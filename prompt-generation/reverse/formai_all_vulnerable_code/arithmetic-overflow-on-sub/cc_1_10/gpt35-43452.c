//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXROWS 6
#define MAXCOLS 6

char board[MAXROWS][MAXCOLS];
int player1Score = 0;
int player2Score = 0;

void initializeBoard() {
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    printf("   1   2   3   4   5   6\n");
    printf(" +---+---+---+---+---+---+\n");
    for (int i = 0; i < MAXROWS; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < MAXCOLS; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        printf(" +---+---+---+---+---+---+\n");
    }
}

int isValidPosition(int row, int col) {
    if (row >= 0 && row < MAXROWS && col >= 0 && col < MAXCOLS) {
        return 1;
    }
    return 0;
}

void placeToken(char token, int row, int col) {
    if (isValidPosition(row, col)) {
        board[row][col] = token;
    }
    else {
        printf("Invalid position\n");
    }
}

int checkRow(int row, char token) {
    if (board[row][0] == token && board[row][1] == token && board[row][2] == token &&
        board[row][3] == token && board[row][4] == token && board[row][5] == token) {
        return 1;
    }
    return 0;
}

int checkCol(int col, char token) {
    if (board[0][col] == token && board[1][col] == token && board[2][col] == token &&
        board[3][col] == token && board[4][col] == token && board[5][col] == token) {
        return 1;
    }
    return 0;
}

int checkDiagonal(char token) {
    if (board[0][0] == token && board[1][1] == token && board[2][2] == token &&
        board[3][3] == token && board[4][4] == token && board[5][5] == token) {
        return 1;
    }
    if (board[0][5] == token && board[1][4] == token && board[2][3] == token &&
        board[3][2] == token && board[4][1] == token && board[5][0] == token) {
        return 1;
    }
    return 0;
}

int checkWinner(char token) {
    for (int i = 0; i < MAXROWS; i++) {
        if (checkRow(i, token) || checkCol(i, token)) {
            return 1;
        }
    }
    if (checkDiagonal(token)) {
        return 1;
    }
    return 0;
}

int getRow() {
    int row;
    printf("Enter row: ");
    scanf("%d", &row);
    return row - 1;
}

int getCol() {
    int col;
    printf("Enter column: ");
    scanf("%d", &col);
    return col - 1;
}

int main() {
    int player = 1;
    char playerToken = 'X';
    srand(time(0));
    int randomRow = rand() % MAXROWS;
    int randomCol = rand() % MAXCOLS;
    board[randomRow][randomCol] = 'O';
    initializeBoard();
    printBoard();
    printf("PLAYER %d starts the game\n", player);
    while (1) {
        int row = getRow();
        int col = getCol();
        placeToken(playerToken, row, col);
        printBoard();
        if (checkWinner(playerToken)) {
            printf("PLAYER %d wins!\n", player);
            if (player == 1) {
                player1Score++;
            }
            else if (player == 2) {
                player2Score++;
            }
            printf("Score: Player 1 - %d | Player 2 - %d\n", player1Score, player2Score);
            break;
        }
        if (player == 1) {
            player = 2;
            playerToken = 'O';
        }
        else {
            player = 1;
            playerToken = 'X';
        }
        printf("PLAYER %d's turn\n", player);
    }
    return 0;
}