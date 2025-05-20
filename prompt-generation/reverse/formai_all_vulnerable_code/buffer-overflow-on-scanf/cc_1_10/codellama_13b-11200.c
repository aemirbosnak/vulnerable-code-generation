//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 3
#define X 1
#define O 2
#define EMPTY 0

int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_player_move(int player) {
    int move;
    do {
        printf("Player %d, enter a move: ", player);
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move, please try again.\n");
        }
    } while (move < 1 || move > 9);
    return move;
}

int get_computer_move() {
    int move = rand() % 9 + 1;
    while (board[move / 3][move % 3] != EMPTY) {
        move = rand() % 9 + 1;
    }
    return move;
}

int check_win(int player) {
    int win = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                win++;
            }
        }
        if (win == 3) {
            return 1;
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                win++;
            }
        }
        if (win == 3) {
            return 1;
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                win++;
            }
        }
        if (win == 3) {
            return 1;
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                win++;
            }
        }
        if (win == 3) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int turn = 1;
    int player = X;
    int move;

    print_board();

    while (1) {
        if (turn % 2 == 1) {
            move = get_player_move(player);
            board[move / 3][move % 3] = player;
            print_board();
            if (check_win(player)) {
                printf("Player %d wins!\n", player);
                return 0;
            }
        } else {
            move = get_computer_move();
            board[move / 3][move % 3] = player;
            print_board();
            if (check_win(player)) {
                printf("Player %d wins!\n", player);
                return 0;
            }
        }
        turn++;
    }

    return 0;
}