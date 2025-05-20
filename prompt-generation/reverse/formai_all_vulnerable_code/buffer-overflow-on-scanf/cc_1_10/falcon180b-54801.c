//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int check_draw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j]!= 'X' && board[i][j]!= 'O') {
                return 0;
            }
        }
    }
    return 1;
}

void paranoid_move(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return;
    }
    if (board[x][y]!= '-') {
        return;
    }
    board[x][y] = 'O';
}

int main() {
    int player = 1;
    int x, y;
    char choice;
    while (1) {
        print_board();
        printf("Player %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%c", &x, &choice);
        y = choice - '0';
        if (player == 1) {
            paranoid_move(x, y);
            if (check_win()) {
                printf("Player 1 wins!\n");
                break;
            } else if (check_draw()) {
                printf("Draw.\n");
                break;
            }
            player = 2;
        } else {
            paranoid_move(x, y);
            if (check_win()) {
                printf("Player 2 wins!\n");
                break;
            } else if (check_draw()) {
                printf("Draw.\n");
                break;
            }
            player = 1;
        }
    }
    return 0;
}