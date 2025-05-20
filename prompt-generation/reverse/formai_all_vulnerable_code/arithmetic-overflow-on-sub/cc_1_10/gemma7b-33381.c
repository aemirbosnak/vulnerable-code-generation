//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, direction, speed;
} Car;

Car cars[MAX_CARS];

void initializeCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].x = 0;
        cars[i].y = 0;
        cars[i].direction = 0;
        cars[i].speed = 0;
    }
}

void moveCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        switch (cars[i].direction) {
            case 0:
                cars[i].x++;
                break;
            case 1:
                cars[i].y++;
                break;
            case 2:
                cars[i].x--;
                break;
            case 3:
                cars[i].y--;
                break;
        }

        if (cars[i].x >= MAX_LANE || cars[i].x < 0) {
            cars[i].direction = (cars[i].direction + 1) % 4;
        }

        if (cars[i].y >= MAX_LANE || cars[i].y < 0) {
            cars[i].direction = (cars[i].direction + 1) % 4;
        }
    }
}

void printTraffic() {
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: (%d, %d), Direction: %d, Speed: %d\n", i + 1, cars[i].x, cars[i].y, cars[i].direction, cars[i].speed);
    }
}

int main() {
    initializeCars();

    time_t tStart = time(NULL);
    while (time(NULL) - tStart < 10) {
        moveCars();
        printTraffic();
        sleep(1);
    }

    return 0;
}