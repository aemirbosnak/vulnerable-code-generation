//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define BLACK 1
#define WHITE 2
#define EMPTY 0

void init_board(char board[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int check_win(char board[][SIZE], int player) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    for (i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

void print_board(char board[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == BLACK) {
                printf("B");
            } else if (board[i][j] == WHITE) {
                printf("W");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char board[SIZE][SIZE];
    int player = BLACK;
    int i, j;

    srand(time(NULL));

    init_board(board);

    while (1) {
        system("clear");
        print_board(board);
        int x, y;
        if (player == BLACK) {
            printf("Enter your move (row, column): ");
            scanf("%d%d", &x, &y);
            x--;
            y--;
            board[x][y] = BLACK;
            if (check_win(board, BLACK)) {
                printf("Player 1 wins!\n");
                break;
            } else {
                player = WHITE;
            }
        } else {
            printf("Enter your move (row, column): ");
            scanf("%d%d", &x, &y);
            x--;
            y--;
            board[x][y] = WHITE;
            if (check_win(board, WHITE)) {
                printf("Player 2 wins!\n");
                break;
            } else {
                player = BLACK;
            }
        }
    }

    return 0;
}