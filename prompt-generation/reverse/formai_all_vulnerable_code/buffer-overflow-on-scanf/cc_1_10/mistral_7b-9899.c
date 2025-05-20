//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS];

void initialize_board() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

bool is_valid_move(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == ' ') {
        return true;
    }
    return false;
}

void print_board() {
    int i, j;

    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool check_win(char symbol) {
    int i;

    for (i = 0; i < ROWS; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }

    return false;
}

void make_move(int row, int col, char symbol) {
    if (is_valid_move(row, col)) {
        board[row][col] = symbol;
    }
}

void game() {
    int row, col, turn = 0;
    char x = 'X', o = 'O';

    initialize_board();

    while (!check_win(x) && !check_win(o)) {
        print_board();
        printf("Player %d, enter row and column to place X: ", turn + 1);
        scanf("%d%d", &row, &col);

        if (is_valid_move(row, col)) {
            make_move(row, col, x);
            turn++;
        } else {
            printf("Invalid move! Try again.\n");
            turn--;
        }

        if (check_win(x)) {
            print_board();
            printf("Player %c wins!\n", x);
            break;
        }

        turn++;

        if (turn % 2 != 0) {
            printf("Player %d, enter row and column to place O: ", turn);
            scanf("%d%d", &row, &col);

            if (is_valid_move(row, col)) {
                make_move(row, col, o);
                turn++;
            } else {
                printf("Invalid move! Try again.\n");
                turn--;
            }
        }
    }

    print_board();
}

int main() {
    game();
    return 0;
}