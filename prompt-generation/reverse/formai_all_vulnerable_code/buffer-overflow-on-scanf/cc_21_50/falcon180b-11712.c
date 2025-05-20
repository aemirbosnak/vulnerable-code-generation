//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int maze[10][10] = {0};
    int playerX = 0, playerY = 0, score = 0;
    int gameOver = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    while (!gameOver) {
        system("clear");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (maze[i][j] == 1) {
                    printf("X");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("Score: %d\n", score);
        printf("Player at (%d, %d)\n", playerX, playerY);

        char move;
        scanf("%c", &move);

        switch (move) {
            case 'w':
                if (playerY > 0 && maze[playerY - 1][playerX] == 0) {
                    playerY--;
                    score++;
                }
                break;
            case 'a':
                if (playerX > 0 && maze[playerY][playerX - 1] == 0) {
                    playerX--;
                    score++;
                }
                break;
            case's':
                if (playerY < 9 && maze[playerY + 1][playerX] == 0) {
                    playerY++;
                    score++;
                }
                break;
            case 'd':
                if (playerX < 9 && maze[playerY][playerX + 1] == 0) {
                    playerX++;
                    score++;
                }
                break;
            default:
                printf("Invalid move\n");
        }

        if (playerX == 9 && playerY == 9) {
            gameOver = 1;
            printf("You win!\n");
        } else if (maze[playerY][playerX] == 1) {
            gameOver = 1;
            printf("You lose!\n");
        }
    }

    return 0;
}