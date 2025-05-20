//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int width, height, x, y, playerX = 0, playerY = 0;
    char map[100][100], ch;
    int choice;

    printf("Enter the width of the map: ");
    scanf("%d", &width);
    printf("Enter the height of the map: ");
    scanf("%d", &height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = rand() % 2? '.' : '#';
        }
    }

    while (1) {
        system("clear");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == playerY && j == playerX) {
                    printf("@");
                } else {
                    printf("%c", map[i][j]);
                }
            }
            printf("\n");
        }

        printf("\nPress 'w' to move up,'s' to move down, 'a' to move left, 'd' to move right, or 'q' to quit.\n");
        scanf(" %c", &ch);

        switch (ch) {
            case 'w':
                if (playerY > 0 && map[playerY - 1][playerX]!= '#') {
                    playerY--;
                }
                break;
            case's':
                if (playerY < height - 1 && map[playerY + 1][playerX]!= '#') {
                    playerY++;
                }
                break;
            case 'a':
                if (playerX > 0 && map[playerY][playerX - 1]!= '#') {
                    playerX--;
                }
                break;
            case 'd':
                if (playerX < width - 1 && map[playerY][playerX + 1]!= '#') {
                    playerX++;
                }
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid input.\n");
        }

        if (map[playerY][playerX] == '#') {
            printf("You hit a wall.\n");
        }
    }

    return 0;
}