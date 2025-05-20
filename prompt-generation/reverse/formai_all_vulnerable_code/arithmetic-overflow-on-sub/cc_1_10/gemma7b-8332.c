//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 512
#define MAP_HEIGHT 512

typedef struct Point {
    int x;
    int y;
} Point;

void drawMap(Point player, Point destination) {
    system("cls");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == player.x && y == player.y) {
                printf("P");
            } else if (x == destination.x && y == destination.y) {
                printf("D");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    Point player = {0, 0};
    Point destination = {256, 256};

    time_t start = time(NULL);

    while (time(NULL) - start < 10) {
        drawMap(player, destination);

        int direction = rand() % 4;

        switch (direction) {
            case 0:
                player.x--;
                break;
            case 1:
                player.x++;
                break;
            case 2:
                player.y--;
                break;
            case 3:
                player.y++;
                break;
        }

        sleep(1);
    }

    drawMap(player, destination);

    printf("You reached the destination!");

    return 0;
}