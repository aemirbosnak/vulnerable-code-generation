//Falcon-180B DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define NUM_PLAYERS 2

int board[SIZE][SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int players[NUM_PLAYERS] = {1, 2};

void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void play_turn(int player) {
    int row, col;
    printf("Player %d's turn:\n", player);
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == 0) {
        board[row][col] = player;
    } else {
        printf("Invalid move.\n");
        play_turn(player);
    }
}

int check_winner() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int current_player = 1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    while (1) {
        print_board();
        play_turn(current_player);

        int winner = check_winner();
        if (winner!= 0) {
            printf("Player %d wins!\n", winner);
            break;
        }

        current_player = (current_player == 1)? 2 : 1;
    }

    return 0;
}