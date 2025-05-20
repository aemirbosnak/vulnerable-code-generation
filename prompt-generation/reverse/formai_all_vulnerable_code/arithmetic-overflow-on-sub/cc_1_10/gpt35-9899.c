//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];
char player = 'X';
int moves = 0;

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    int i, j;
    printf("-------------\n");
    for (i = 0; i < 3; ++i) {
        printf("| ");
        for (j = 0; j < 3; ++j) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

bool is_valid(int row, int col) {
    if ((row >= 0) && (row <= 2)) {
        if ((col >= 0) && (col <= 2)) {
            if (board[row][col] == '-') {
                return true;
            }
        }
    }
    return false;
}

bool has_won(char player) {
    int i;
    for (i = 0; i < 3; ++i) {
        if ((board[i][0] == player) && (board[i][1] == player) && (board[i][2] == player)) {
            return true;
        }
        if ((board[0][i] == player) && (board[1][i] == player) && (board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) {
        return true;
    }
    if ((board[0][2] == player) && (board[1][1] == player) && (board[2][0] == player)) {
        return true;
    }
    return false;
}

void ai_move() {
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (is_valid(i, j)) {
                board[i][j] = 'O';
                if (has_won('O')) {
                    return;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (is_valid(i, j)) {
                board[i][j] = 'X';
                if (has_won('X')) {
                    board[i][j] = 'O';
                    return;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while (!is_valid(i, j));
    board[i][j] = 'O';
}

int main() {
    initialize_board();
    printf("Welcome to Tic Tac Toe in C!\n");
    printf("You are %c, the computer is O.\n", player);
    printf("Use 1-9 to place your move, like this:\n");
    printf("1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n");
    while (true) {
        print_board();
        if (has_won(player)) {
            printf("You won!\n");
            break;
        }
        if (has_won('O')) {
            printf("The computer won!\n");
            break;
        }
        if (moves == 9) {
            printf("It's a tie!\n");
            break;
        }
        int row, col;
        printf("Enter row (1-3) and column (1-3): ");
        scanf("%d %d", &row, &col);
        --row;
        --col;
        if (is_valid(row, col)) {
            board[row][col] = 'X';
            ++moves;
            ai_move();
            ++moves;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    print_board();
    return 0;
}