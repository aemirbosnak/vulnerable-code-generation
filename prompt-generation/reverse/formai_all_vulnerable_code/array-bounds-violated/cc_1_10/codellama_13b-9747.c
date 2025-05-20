//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_SQUARES (BOARD_SIZE * BOARD_SIZE)

typedef enum {
    EMPTY,
    PLAYER_X,
    PLAYER_O
} square_t;

square_t board[NUM_SQUARES];

void init_board(void) {
    for (int i = 0; i < NUM_SQUARES; i++) {
        board[i] = EMPTY;
    }
}

void print_board(void) {
    printf("  1 | 2 | 3\n");
    printf("  ---------\n");
    printf("  4 | 5 | 6\n");
    printf("  ---------\n");
    printf("  7 | 8 | 9\n");
}

void play_game(void) {
    init_board();
    while (1) {
        print_board();
        int player = rand() % 2;
        int square = rand() % NUM_SQUARES;
        if (board[square] == EMPTY) {
            board[square] = player == 0 ? PLAYER_X : PLAYER_O;
        }
        if (check_win()) {
            break;
        }
    }
}

int check_win(void) {
    for (int i = 0; i < NUM_SQUARES; i++) {
        if (board[i] == EMPTY) {
            continue;
        }
        int row = i / BOARD_SIZE;
        int col = i % BOARD_SIZE;
        if (board[i] == board[i - BOARD_SIZE] && board[i] == board[i - BOARD_SIZE - 1]) {
            return 1;
        }
        if (board[i] == board[i - 1] && board[i] == board[i - BOARD_SIZE + 1]) {
            return 1;
        }
        if (board[i] == board[i - BOARD_SIZE] && board[i] == board[i - BOARD_SIZE + 1]) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    srand(time(NULL));
    play_game();
    return 0;
}