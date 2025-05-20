//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void display_board(int board[N][N]) {
    printf("  1 | 2 | 3\n");
    printf("  ---------\n");
    printf("  4 | 5 | 6\n");
    printf("  ---------\n");
    printf("  7 | 8 | 9\n");
}

void print_result(int board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int check_win(int board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void ai_move(int board[N][N], int player) {
    int i, j, move;
    do {
        move = rand() % 9;
    } while (board[move / N][move % N] != 0);
    board[move / N][move % N] = player;
}

int main() {
    int board[N][N] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int move;
    srand(time(NULL));
    printf("Welcome to medieval Tic Tac Toe!\n");
    display_board(board);
    while (1) {
        printf("Player %d, enter a move: ", player);
        scanf("%d", &move);
        if (move >= 1 && move <= 9) {
            board[move / N][move % N] = player;
        } else {
            printf("Invalid move.\n");
            continue;
        }
        print_result(board);
        if (check_win(board)) {
            printf("Player %d wins!", player);
            break;
        }
        ai_move(board, player == 1 ? 2 : 1);
        print_result(board);
        if (check_win(board)) {
            printf("AI wins!");
            break;
        }
        player = player == 1 ? 2 : 1;
    }
    return 0;
}