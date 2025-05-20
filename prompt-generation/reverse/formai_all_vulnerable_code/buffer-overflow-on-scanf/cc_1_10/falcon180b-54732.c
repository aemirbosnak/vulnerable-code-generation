//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define MAX_X 9
#define MAX_Y 5

typedef struct {
    int x;
    int y;
} Room;

Room rooms[ROOMS];
char map[MAX_Y][MAX_X];

void initMap() {
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].x = rand() % MAX_X;
        rooms[i].y = rand() % MAX_Y;
    }

    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            map[i][j] = '.';
        }
    }

    for (int i = 0; i < ROOMS; i++) {
        map[rooms[i].y][rooms[i].x] = 'R';
    }
}

void printMap() {
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initMap();
    printMap();

    int playerX = 0;
    int playerY = 0;

    while (1) {
        system("clear");
        printMap();

        char move;
        printf("> ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                if (playerY > 0 && map[playerY - 1][playerX]!= '#') {
                    playerY--;
                }
                break;
            case's':
                if (playerY < MAX_Y - 1 && map[playerY + 1][playerX]!= '#') {
                    playerY++;
                }
                break;
            case 'a':
                if (playerX > 0 && map[playerY][playerX - 1]!= '#') {
                    playerX--;
                }
                break;
            case 'd':
                if (playerX < MAX_X - 1 && map[playerY][playerX + 1]!= '#') {
                    playerX++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }

        if (playerX == rooms[0].x && playerY == rooms[0].y) {
            printf("You won!\n");
            break;
        } else if (map[playerY][playerX] == '#') {
            printf("You died.\n");
            break;
        }
    }

    return 0;
}