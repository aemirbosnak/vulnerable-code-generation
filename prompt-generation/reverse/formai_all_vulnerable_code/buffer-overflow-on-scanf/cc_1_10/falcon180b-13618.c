//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define INIT_VALUE 100

int board[SIZE][SIZE] = {{0}};

void init() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = INIT_VALUE;
        }
    }
}

int getValue(int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        return board[x][y];
    }
    return -1;
}

void setValue(int x, int y, int value) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        board[x][y] = value;
    }
}

int countPieces(int player) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (getValue(i, j) == player) {
                count++;
            }
        }
    }
    return count;
}

int isCheckmate(int player) {
    int kingX, kingY, opponentPlayer;
    if (player == 1) {
        kingX = 0;
        kingY = 0;
        opponentPlayer = 2;
    } else {
        kingX = 7;
        kingY = 0;
        opponentPlayer = 1;
    }

    int dirX[] = {-1, 0, 1, 0};
    int dirY[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int newX = kingX + dirX[i];
        int newY = kingY + dirY[i];

        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
            if (getValue(newX, newY) == opponentPlayer) {
                return 0;
            }
        }
    }

    return 1;
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", getValue(i, j));
        }
        printf("\n");
    }
}

int main() {
    init();

    while (1) {
        system("clear");
        printBoard();

        int player = 1;
        int x, y;
        printf("Player %d's turn:\n", player);
        scanf("%d %d", &x, &y);

        if (getValue(x, y)!= 0) {
            printf("Invalid move!\n");
            continue;
        }

        setValue(x, y, player);

        if (isCheckmate(player)) {
            printf("Checkmate! Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}