//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int maze[10][10];
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
                if (maze[i][j] == 0) {
                    printf("  ");
                } else {
                    printf("X ");
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
            case's':
                if (playerY < 9 && maze[playerY + 1][playerX] == 0) {
                    playerY++;
                    score++;
                }
                break;
            case 'a':
                if (playerX > 0 && maze[playerY][playerX - 1] == 0) {
                    playerX--;
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

        if (score == 25) {
            gameOver = 1;
            printf("You won!\n");
        } else if (playerX < 0 || playerX > 9 || playerY < 0 || playerY > 9) {
            gameOver = 1;
            printf("You lost!\n");
        }
    }

    return 0;
}