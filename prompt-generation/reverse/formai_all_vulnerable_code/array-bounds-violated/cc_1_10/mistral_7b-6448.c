//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#define SIZE 3

char board[SIZE][SIZE];

void init_board() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    printf("-----------------------\n");
    for (i = 0; i < SIZE; i++) {
        printf("|");
        for (j = 0; j < SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("-----------------------\n");
    }
}

bool check_win(char mark) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return true;
        }
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
            return true;
        }
    }
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return true;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return true;
    }
    return false;
}

void place_mark(int x, int y, char mark) {
    board[x][y] = mark;
}

bool check_empty(int x, int y) {
    if (board[x][y] == ' ') {
        return true;
    }
    return false;
}

int main() {
    char current_mark = 'X';
    int x, y;
    init_board();
    while (true) {
        print_board();
        printf("Player %c, enter your move (x, y): ", current_mark);
        scanf("%d%d", &x, &y);
        if (check_empty(x, y)) {
            place_mark(x, y, current_mark);
            if (check_win(current_mark)) {
                printf("Player %c wins!\n", current_mark);
                break;
            }
            current_mark = (current_mark == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return 0;
}