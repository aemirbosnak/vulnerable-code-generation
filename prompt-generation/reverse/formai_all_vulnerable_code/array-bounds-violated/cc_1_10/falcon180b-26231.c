//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int check_winner() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j]!= 'X' && board[i][j]!= 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int check_draw() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int player = 1;
    int choice;
    int move;
    int i, j;
    while (1) {
        system("clear");
        print_board();
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (1-%d): ", BOARD_SIZE * BOARD_SIZE - 1);
        scanf("%d", &move);
        move--;
        i = move / BOARD_SIZE;
        j = move % BOARD_SIZE;
        if (board[i][j] == '-') {
            board[i][j] = (player == 1)? 'X' : 'O';
            if (check_winner()) {
                printf("\nPlayer %d wins!\n", player);
                break;
            } else if (check_draw()) {
                printf("\nDraw.\n");
                break;
            }
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}