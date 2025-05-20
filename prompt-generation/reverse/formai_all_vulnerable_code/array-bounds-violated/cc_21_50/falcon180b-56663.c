//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int playerX = 0, playerY = 0;
    int map[10][10] = { {1,1,1,1,1,1,1,1,1,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,0,1,1,1,1,1,1,1,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1} };
    int playerDirection = 0; // 0 = up, 1 = right, 2 = down, 3 = left
    int gameOver = 0;

    while (!gameOver) {
        system("clear");
        printf("Score: %d\n", playerX + playerY);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 1) {
                    printf("#");
                } else if (map[i][j] == 0) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("Player: %c\n", '0' + playerDirection);

        char input = getchar();
        switch (input) {
            case 'w':
            case 'W':
                if (playerDirection!= 0 && map[playerY][playerX - 1] == 0) {
                    playerX--;
                }
                playerDirection = 0;
                break;
            case 'a':
            case 'A':
                if (playerDirection!= 1 && map[playerY][playerX + 1] == 0) {
                    playerX++;
                }
                playerDirection = 1;
                break;
            case's':
            case 'S':
                if (playerDirection!= 2 && map[playerY + 1][playerX] == 0) {
                    playerY++;
                }
                playerDirection = 2;
                break;
            case 'd':
            case 'D':
                if (playerDirection!= 3 && map[playerY][playerX - 1] == 0) {
                    playerX--;
                }
                playerDirection = 3;
                break;
            default:
                break;
        }

        if (playerX < 0 || playerX >= 10 || playerY < 0 || playerY >= 10) {
            gameOver = 1;
        }
    }

    return 0;
}