//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[3][3]) {
    printf(" %d | %d | %d \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %d | %d | %d \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %d | %d | %d \n", board[2][0], board[2][1], board[2][2]);
}

int check_winner(int board[3][3]) {
    // Check horizontal lines
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check vertical lines
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonal lines
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // No winner yet
    return 0;
}

void play_game() {
    int board[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int player = 1;
    int winner = 0;

    while (winner == 0) {
        print_board(board);
        printf("Player %d's turn\n", player);
        int x, y;
        scanf("%d%d", &x, &y);
        if (board[x - 1][y - 1]!= 0) {
            printf("Invalid move\n");
        } else {
            board[x - 1][y - 1] = player;
            winner = check_winner(board);
            if (winner == 0) {
                player =!player;
            }
        }
    }

    print_board(board);
    printf("Player %d wins!\n", winner);
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}