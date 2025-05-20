//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

char board[ROWS][COLS]; // initialize the board

void print_board() {
    int i, j;

    printf("\n---------\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n|---|");
        for (j = 0; j < COLS; j++) {
            printf("---|");
        }
        printf("\n");
    }
}

void initialize_board() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

int check_win(char mark, int row, int col) {
    int i, j, count = 1;

    // Check row and column
    for (i = 0; i < ROWS; i++) {
        if (board[i][col] != mark) {
            count = 0;
            break;
        }
        count++;
    }
    if (count == ROWS) {
        return 1;
    }

    count = 1;
    for (i = 0; i < COLS; i++) {
        if (board[row][i] != mark) {
            count = 0;
            break;
        }
        count++;
    }
    if (count == COLS) {
        return 1;
    }

    // Check diagonal
    if (row == col) {
        for (i = 0; i < ROWS; i++) {
            if (board[i][i] != mark) {
                count = 0;
                break;
            }
            count++;
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check anti-diagonal
    if (row + col < ROWS && row - col >= 0) {
        for (i = 0; i < ROWS; i++) {
            if (board[i][row - col] != mark) {
                count = 0;
                break;
            }
            count++;
        }
        if (count == ROWS) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int row, col, mark = 'X', other_mark = 'O';
    int player = 1, winner = 0;

    initialize_board();

    while (!winner) {
        print_board();
        printf("\nPlayer %d (%c), enter row and column: ", player, mark);
        scanf("%d%d", &row, &col);

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ') {
            printf("\nInvalid move! Try again.\n");
            continue;
        }

        board[row][col] = mark;

        winner = check_win(mark, row, col);
        if (winner) {
            print_board();
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player % 2) ? 2 : 1;
        mark = (mark == 'X') ? 'O' : 'X';
    }

    return 0;
}