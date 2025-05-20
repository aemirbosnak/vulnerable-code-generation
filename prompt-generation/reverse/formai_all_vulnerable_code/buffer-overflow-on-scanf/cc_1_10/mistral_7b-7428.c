//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_CELL ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct {
    int rows;
    int cols;
    char cells[BOARD_SIZE][BOARD_SIZE];
} Board;

void initializeBoard(Board* board) {
    int i, j;
    for (i = 0; i < board->rows; i++) {
        for (j = 0; j < board->cols; j++) {
            board->cells[i][j] = EMPTY_CELL;
        }
    }
}

int isFullBoard(Board board) {
    int i, j;
    for (i = 0; i < board.rows; i++) {
        for (j = 0; j < board.cols; j++) {
            if (board.cells[i][j] == EMPTY_CELL) {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(Board board, char player) {
    int i, j;
    // Check rows
    for (i = 0; i < board.rows; i++) {
        if ((board.cells[i][0] == player) && (board.cells[i][1] == player) && (board.cells[i][2] == player)) {
            return 1;
        }
    }
    // Check columns
    for (i = 0; i < board.rows; i++) {
        if ((board.cells[0][i] == player) && (board.cells[1][i] == player) && (board.cells[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board.cells[0][0] == player) && (board.cells[1][1] == player) && (board.cells[2][2] == player)) {
        return 1;
    }
    if ((board.cells[0][2] == player) && (board.cells[1][1] == player) && (board.cells[2][0] == player)) {
        return 1;
    }
    return 0;
}

void printBoard(Board board) {
    int i, j;
    for (i = 0; i < board.rows; i++) {
        for (j = 0; j < board.cols; j++) {
            printf("%c ", board.cells[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Board board;
    initializeBoard(&board);
    board.rows = BOARD_SIZE;
    board.cols = BOARD_SIZE;
    int player = PLAYER_X;
    int currentRow, currentCol;
    int gameResult;

    srand(time(NULL));

    printf("Welcome to the Retro Tic-Tac-Toe Game!\n");
    do {
        printf("\nPlayer %c's turn\n", player == PLAYER_X ? 'X' : 'O');
        printf("Enter row and column (1-%d):\n", board.rows);
        scanf("%d%d", &currentRow, &currentCol);
        currentRow--;
        currentCol--;

        if (board.cells[currentRow][currentCol] != EMPTY_CELL) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board.cells[currentRow][currentCol] = player;
        printBoard(board);

        gameResult = checkWin(board, player);
        if (gameResult == 1) {
            printf("\nPlayer %c wins!\n", player);
            break;
        }

        if (isFullBoard(board)) {
            printf("\nIt's a draw!\n");
            break;
        }

        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    } while (1);

    return 0;
}