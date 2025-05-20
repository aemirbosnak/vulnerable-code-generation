//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int board[SIZE][SIZE];
int player_mark = 1; // 1 for X, -1 for O
int move = 0;
int win_count = 0;
int game_over = 0;

void print_board(int player_mark) {
    printf("-------------\n");
    printf("|%c|%c|%c|\n", board[0][0], board[0][1], board[0][2]);
    printf("|%c|%c|%c|\n", board[1][0], board[1][1], board[1][2]);
    printf("|%c|%c|%c|\n", board[2][0], board[2][1], board[2][2]);
    printf("-------------\n");
}

void set_board() {
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void make_move(int pos, int player_mark) {
    board[pos / SIZE][pos % SIZE] = player_mark;
}

int get_winner(int player_mark) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == player_mark) {
                continue;
            }
            if (board[i][j]!= 0) {
                break;
            }
            return 1;
        }
    }
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    set_board();
    int player = 1;

    while (game_over == 0) {
        print_board(player);
        printf("Player %d, it's your turn\n", player);
        scanf("%d", &move);
        make_move(move, player);
        player = -player;
        if (get_winner(player) == 1) {
            win_count++;
            game_over = 1;
            break;
        }
    }

    if (win_count == 0) {
        printf("Game over, it's a draw\n");
    } else if (win_count == 1) {
        printf("Congratulations, player %d won!\n", player);
    } else if (win_count == 2) {
        printf("Player %d won two times, he is the winner of this game\n", player);
    } else {
        printf("Game over, it's a draw\n");
    }

    return 0;
}