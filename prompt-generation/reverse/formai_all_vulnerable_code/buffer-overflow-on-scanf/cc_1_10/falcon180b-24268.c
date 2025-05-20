//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int countPieces(int color) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == color) {
                count++;
            }
        }
    }
    return count;
}

int checkmate(int color) {
    int count = countPieces(color);
    if (count == 1) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    initBoard();
    int player = 1;
    while (1) {
        printBoard();
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y] == 0) {
            board[x][y] = player;
            player =!player;
        } else {
            printf("Invalid move\n");
        }
        int check = checkmate(player);
        if (check) {
            printf("Checkmate!\n");
            break;
        }
    }
    return 0;
}