//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
/*
 * Cryptic Tic Tac Toe AI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 0
#define O 1
#define EMPTY 2
#define MAX_MOVES 9

int board[MAX_MOVES];
int current_player = X;

void print_board() {
    printf("  1 | 2 | 3\n");
    printf("  ---------\n");
    printf("  4 | 5 | 6\n");
    printf("  ---------\n");
    printf("  7 | 8 | 9\n");
}

void update_board(int move) {
    if (current_player == X) {
        board[move] = X;
    } else {
        board[move] = O;
    }
    current_player = (current_player + 1) % 2;
}

void check_win() {
    for (int i = 0; i < MAX_MOVES; i++) {
        if (board[i] == X) {
            printf("X wins!\n");
            exit(0);
        } else if (board[i] == O) {
            printf("O wins!\n");
            exit(0);
        }
    }
}

void play_game() {
    print_board();
    while (1) {
        int move;
        printf("Enter a move (1-9): ");
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move!\n");
            continue;
        }
        update_board(move);
        print_board();
        check_win();
    }
}

int main() {
    play_game();
    return 0;
}