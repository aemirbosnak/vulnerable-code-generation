//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void init(int *board) {
    for (int i = 0; i < SIZE; i++) {
        board[i] = -1;
    }
}

void print_board(int *board) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", board[i]);
    }
    printf("\n");
}

int check_win(int *board, int player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i]!= player) {
            return 0;
        }
    }
    return 1;
}

int get_move(int *board, int player) {
    int move = 0;
    while (move < 0 || move >= SIZE || board[move]!= -1) {
        printf("Player %d, enter your move: ", player);
        scanf("%d", &move);
    }
    return move;
}

int main() {
    int board[SIZE];
    init(board);

    int player = 1;
    int moves = 0;
    while (moves < SIZE * SIZE) {
        print_board(board);
        int move = get_move(board, player);
        board[move] = player;

        if (check_win(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
        moves++;
    }

    return 0;
}