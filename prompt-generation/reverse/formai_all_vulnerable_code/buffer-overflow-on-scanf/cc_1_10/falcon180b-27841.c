//Falcon-180B DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MIN_VALUE 1
#define MAX_VALUE 100

void generateBoard(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}

void printBoard(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[SIZE][SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
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
    int board[SIZE][SIZE];
    int x, y;
    int player = 1;
    srand(time(NULL));
    generateBoard(board);
    printBoard(board);

    while (1) {
        printf("Player %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == 0) {
            board[x][y] = player;
            printBoard(board);
            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
            player =!player;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}