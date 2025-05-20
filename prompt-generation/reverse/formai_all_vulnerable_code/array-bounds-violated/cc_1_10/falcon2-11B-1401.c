//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 9

int board[9];
int current_player;
int turn;

void print_board() {
    printf("   |   |   \n");
    printf(" %2d | %2d | %2d \n", board[0], board[1], board[2]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %2d | %2d | %2d \n", board[3], board[4], board[5]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %2d | %2d | %2d \n", board[6], board[7], board[8]);
    printf("   |   |   \n");
}

void make_move(int move) {
    board[move] = current_player;
    current_player =!current_player;
    turn++;
}

int check_win() {
    if (board[0] == board[1] && board[1] == board[2] && board[2]!= 0) {
        return 1;
    }
    if (board[3] == board[4] && board[4] == board[5] && board[5]!= 0) {
        return 1;
    }
    if (board[6] == board[7] && board[7] == board[8] && board[8]!= 0) {
        return 1;
    }
    if (board[0] == board[3] && board[3] == board[6] && board[6]!= 0) {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7] && board[7]!= 0) {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8] && board[8]!= 0) {
        return 1;
    }
    if (board[0] == board[4] && board[4] == board[8] && board[8]!= 0) {
        return 1;
    }
    if (board[6] == board[4] && board[4] == board[2] && board[2]!= 0) {
        return 1;
    }
    return 0;
}

int check_draw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(0));

    current_player = 1;
    turn = 0;

    while (1) {
        print_board();

        if (turn == MAX_MOVES) {
            printf("It's a draw!\n");
            break;
        }

        printf("Player %d's turn.\n", current_player + 1);
        int move;
        scanf("%d", &move);

        if (move >= 1 && move <= 9 && board[move] == 0) {
            make_move(move);
        } else {
            printf("Invalid move!\n");
        }

        if (check_win()) {
            printf("Player %d wins!\n", current_player + 1);
            break;
        }

        if (check_draw()) {
            printf("It's a draw!\n");
            break;
        }

        current_player =!current_player;
        turn++;
    }

    return 0;
}