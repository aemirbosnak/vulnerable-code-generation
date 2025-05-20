//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 1 && (i == 0 || board[i-1][j] == 2))
                return 1;
            if (board[i][j] == 2 && (i == SIZE-1 || board[i+1][j] == 1))
                return 1;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == 1 && (i == 0 || board[i-1][0] == 2))
            return 1;
        if (board[i][0] == 2 && (i == SIZE-1 || board[i+1][0] == 1))
            return 1;
    }
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == 1 && (j == 0 || board[0][j-1] == 2))
            return 1;
        if (board[0][j] == 2 && (j == SIZE-1 || board[0][j+1] == 1))
            return 1;
    }
    return 0;
}

int main() {
    int board[SIZE][SIZE] = {0};
    int player = 1;
    int game_over = 0;

    while (!game_over) {
        printf("Player %d's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d %d", &player, &player);
        board[player][player] = player;
        print_board(board);
        game_over = check_win(board);
        if (!game_over) {
            player++;
            if (player > 2)
                player = 1;
        }
    }

    return 0;
}