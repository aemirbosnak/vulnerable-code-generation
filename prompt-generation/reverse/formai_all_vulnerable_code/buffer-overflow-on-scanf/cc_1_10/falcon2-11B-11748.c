//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 3
#define MAX_NUM_MOVES 9

int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int moves[MAX_NUM_MOVES];

void check_move(int move, int* valid_move) {
    *valid_move = 0;

    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        if (board[i][move] == -1) {
            // Valid move
            board[i][move] = 1;
            *valid_move = 1;
            break;
        }
    }
}

void print_board() {
    printf("  | %d | %d |\n", board[0][0], board[0][1]);
    printf("  | %d | %d |\n", board[1][0], board[1][1]);
    printf("  | %d | %d |\n", board[2][0], board[2][1]);
}

int main() {
    int valid_move = 0;

    while (valid_move == 0) {
        printf("Enter a move (0-8): ");
        int move = scanf("%d", &move);

        if (move == -1) {
            printf("Invalid move.\n");
            continue;
        }

        check_move(move, &valid_move);

        if (valid_move == 1) {
            board[move / MAX_BOARD_SIZE][move % MAX_BOARD_SIZE] = -1;
            printf("Valid move.\n");
            break;
        } else {
            printf("Invalid move.\n");
        }
    }

    while (1) {
        print_board();
        printf("Enter a move (0-8): ");
        int move = scanf("%d", &move);

        if (move == -1) {
            printf("Invalid move.\n");
            continue;
        }

        check_move(move, &valid_move);

        if (valid_move == 1) {
            board[move / MAX_BOARD_SIZE][move % MAX_BOARD_SIZE] = -1;
            printf("Valid move.\n");
            break;
        } else {
            printf("Invalid move.\n");
        }
    }
}