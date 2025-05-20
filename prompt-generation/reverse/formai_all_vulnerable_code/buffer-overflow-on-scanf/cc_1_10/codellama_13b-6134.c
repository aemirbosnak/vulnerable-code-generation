//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3
#define X_PLAYER 1
#define O_PLAYER 2
#define EMPTY 0

int board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
};

int get_move(int player) {
    int row, col;
    printf("Enter row and col for player %d: ", player);
    scanf("%d %d", &row, &col);
    return row * BOARD_SIZE + col;
}

void print_board() {
    printf(" 1 | 2 | 3 \n");
    printf(" ---------\n");
    printf(" 4 | 5 | 6 \n");
    printf(" ---------\n");
    printf(" 7 | 8 | 9 \n");
}

void update_board(int move, int player) {
    int row = move / BOARD_SIZE;
    int col = move % BOARD_SIZE;
    board[row][col] = player;
}

void print_winner(int player) {
    if (player == X_PLAYER) {
        printf("X wins!\n");
    } else if (player == O_PLAYER) {
        printf("O wins!\n");
    } else {
        printf("It's a draw!\n");
    }
}

int check_win(int player) {
    int row, col;
    int count;
    for (row = 0; row < BOARD_SIZE; row++) {
        count = 0;
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            print_winner(player);
            return 1;
        }
    }
    for (col = 0; col < BOARD_SIZE; col++) {
        count = 0;
        for (row = 0; row < BOARD_SIZE; row++) {
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            print_winner(player);
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        print_winner(player);
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        print_winner(player);
        return 1;
    }
    return 0;
}

int main() {
    int move;
    int player = X_PLAYER;
    int turn = 0;
    while (1) {
        print_board();
        move = get_move(player);
        update_board(move, player);
        turn++;
        if (check_win(player)) {
            break;
        }
        player = player == X_PLAYER ? O_PLAYER : X_PLAYER;
        if (turn == BOARD_SIZE * BOARD_SIZE) {
            print_winner(EMPTY);
            break;
        }
    }
    return 0;
}