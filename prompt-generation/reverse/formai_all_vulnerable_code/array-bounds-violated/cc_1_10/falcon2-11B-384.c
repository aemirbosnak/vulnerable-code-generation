//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int board[3][3] = {0,0,0,0,0,0,0,0,0};

void setup_board() {
    board[0][0] = 1;
    board[0][1] = 2;
    board[0][2] = 3;
    board[1][0] = 4;
    board[1][1] = 5;
    board[1][2] = 6;
    board[2][0] = 7;
    board[2][1] = 8;
    board[2][2] = 9;
}

bool check_win() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

void make_move(int move) {
    board[move/3][move%3] = 1;
}

void ai_move() {
    int move = -1;
    while (move == -1) {
        srand(time(NULL));
        move = rand() % 9;
        if (check_win()) {
            move = -1;
        }
    }
    make_move(move);
}

int main() {
    setup_board();
    bool game_over = false;
    while (!game_over) {
        printf("Player 1 turn\n");
        int move = -1;
        while (move == -1) {
            printf("Enter your move (1-9): ");
            if (scanf("%d", &move)!= 1) {
                printf("Invalid input!\n");
            } else {
                if (board[move/3][move%3] == 0) {
                    break;
                } else {
                    printf("Space already taken!\n");
                }
            }
        }
        make_move(move);

        if (check_win()) {
            printf("Player 1 wins!\n");
            game_over = true;
        } else {
            ai_move();

            if (check_win()) {
                printf("Player 2 wins!\n");
                game_over = true;
            }
        }
    }

    return 0;
}