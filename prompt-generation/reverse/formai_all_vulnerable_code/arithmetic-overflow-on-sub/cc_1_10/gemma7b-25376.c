//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct Point {
    int x;
    int y;
} Point;

Point currentLocation;
Point destination;

void drawMap() {
    system("clear");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == currentLocation.x && y == currentLocation.y) {
                printf("O ");
            } else if (x == destination.x && y == destination.y) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void moveCharacter() {
    int direction = rand() % 4;
    switch (direction) {
        case 0:
            currentLocation.x--;
            break;
        case 1:
            currentLocation.x++;
            break;
        case 2:
            currentLocation.y--;
            break;
        case 3:
            currentLocation.y++;
            break;
    }

    if (currentLocation.x < 0 || currentLocation.x >= MAP_WIDTH) {
        currentLocation.x = destination.x;
    }
    if (currentLocation.y < 0 || currentLocation.y >= MAP_HEIGHT) {
        currentLocation.y = destination.y;
    }
}

int main() {
    currentLocation.x = 0;
    currentLocation.y = 0;
    destination.x = 10;
    destination.y = 10;

    time_t t = time(NULL);

    while (time(NULL) - t < 10) {
        drawMap();
        moveCharacter();
        sleep(1);
    }

    printf("You have reached your destination!\n");

    return 0;
}