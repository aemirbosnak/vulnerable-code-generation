//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void drawBoard(int board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int board[10][10] = {0};
    int playerBoard[10][10] = {0};
    Point playerPos = {0, 0};
    Point enemyPos = {9, 9};
    int turn = 0;
    int gameOver = 0;

    while (!gameOver) {
        system("clear");
        drawBoard(board);
        if (turn % 2 == 0) {
            printf("Your turn!\n");
        } else {
            printf("Enemy's turn...\n");
        }
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y] == 0) {
            board[x][y] = turn % 2 + 1;
            if (turn % 2 == 0) {
                playerBoard[x][y] = 1;
                playerPos.x = x;
                playerPos.y = y;
            } else {
                int dx = abs(playerPos.x - x);
                int dy = abs(playerPos.y - y);
                if (dx == dy) {
                    enemyPos.x = x;
                    enemyPos.y = y;
                }
            }
            turn++;
        } else {
            printf("Invalid move!\n");
        }
        if (gameOver) {
            printf("GAME OVER!\n");
            break;
        }
    }

    return 0;
}