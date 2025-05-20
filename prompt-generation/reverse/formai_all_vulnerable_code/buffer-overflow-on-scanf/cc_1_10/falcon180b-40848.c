//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int main() {
    char board[ROWS][COLS];
    int player_score = 0;
    int computer_score = 0;
    int current_player = 1;
    int moves = 0;

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    while (player_score < 5 && computer_score < 5) {
        print_board(board);
        printf("Player %d's turn\n", current_player);
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y] == 0) {
            board[x][y] = current_player;
            if (current_player == 1) {
                player_score++;
            } else {
                computer_score++;
            }
            moves++;
        } else {
            printf("Invalid move!\n");
        }
        current_player =!current_player;
    }

    if (player_score == 5) {
        printf("Player 1 wins!\n");
    } else if (computer_score == 5) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie game!\n");
    }

    return 0;
}