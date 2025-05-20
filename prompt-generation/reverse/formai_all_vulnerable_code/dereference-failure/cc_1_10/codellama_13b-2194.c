//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define WIN 3

typedef struct {
    int row;
    int col;
} move_t;

void print_board(char board[ROWS][COLS]) {
    printf(" 1 | 2 | 3 \n");
    printf(" ---------\n");
    printf(" 4 | 5 | 6 \n");
    printf(" ---------\n");
    printf(" 7 | 8 | 9 \n");
}

int check_win(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int make_move(char board[ROWS][COLS], int row, int col, char player) {
    if (board[row][col] != ' ') {
        return 0;
    }
    board[row][col] = player;
    return 1;
}

void make_random_move(char board[ROWS][COLS], char player) {
    int row, col;
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while (board[row][col] != ' ');
    make_move(board, row, col, player);
}

void get_move(char board[ROWS][COLS], char player) {
    move_t move;
    do {
        printf("Player %c, enter a row and column (e.g. 1 2): ", player);
        scanf("%d %d", &move.row, &move.col);
    } while (!make_move(board, move.row, move.col, player));
}

int main() {
    char board[ROWS][COLS] = {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' }
    };
    srand(time(NULL));
    char player = 'X';
    int done = 0;
    while (!done) {
        print_board(board);
        get_move(board, player);
        if (check_win(board)) {
            printf("Player %c wins!\n", player);
            done = 1;
        } else {
            make_random_move(board, player == 'X' ? 'O' : 'X');
            if (check_win(board)) {
                printf("Player %c wins!\n", player == 'X' ? 'O' : 'X');
                done = 1;
            }
            player = player == 'X' ? 'O' : 'X';
        }
    }
    return 0;
}