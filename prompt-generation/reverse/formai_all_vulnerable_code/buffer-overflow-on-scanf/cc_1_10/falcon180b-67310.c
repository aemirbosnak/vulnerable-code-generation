//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void drawBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j == SIZE - 1)
                printf("\n");
        }
        if (i == SIZE - 1)
            printf("\n\n");
    }
}

int winner(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = (i + j) % 2 + '0';

    int player = 1;
    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0 || x > SIZE - 1 || y < 0 || y > SIZE - 1) {
            printf("Invalid move\n");
            continue;
        }
        if (board[x][y]!= '0' && board[x][y]!= '1') {
            printf("Invalid move\n");
            continue;
        }
        board[x][y] = (player == 1)? '1' : '2';
        if (winner(board)) {
            drawBoard(board);
            printf("\nPlayer %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }

    return 0;
}