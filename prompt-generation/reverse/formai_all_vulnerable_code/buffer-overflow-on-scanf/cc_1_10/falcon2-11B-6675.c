//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
} Coordinates;

void print_board(int board[3][3], int players) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("Players: %d\n", players);
}

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int players = 0;

    srand(time(NULL));

    while (1) {
        print_board(board, players);
        printf("Player %d's turn.\n", (players + 1) % 2);
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[row][col]!= 0) {
            printf("This position is occupied.\n");
            continue;
        }
        board[row][col] = (players + 1) % 2;
        if (is_win(board)) {
            printf("Player %d wins!\n", (players + 1) % 2);
            break;
        }
        if (is_tie(board)) {
            printf("It's a tie!\n");
            break;
        }
        players = (players + 1) % 2;
    }
    return 0;
}

int is_win(int board[3][3]) {
    int rows[3] = {0, 1, 2};
    int cols[3] = {0, 1, 2};
    int diags[2] = {0, 1, 2};
    for (int i = 0; i < 3; i++) {
        if (board[rows[i]][cols[i]] == (i + 1) % 2) {
            return 1;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (board[diags[i]][diags[i + 1]] == (i + 1) % 2) {
            return 1;
        }
    }
    return 0;
}

int is_tie(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}