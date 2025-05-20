//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 5

typedef struct Car {
    int x, y, speed, direction;
    char name[20];
} Car;

Car cars[MAX_CARS];

void initCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].x = 0;
        cars[i].y = 0;
        cars[i].speed = 0;
        cars[i].direction = 0;
        strcpy(cars[i].name, "");
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
    }
}

int main() {
    initCars();

    // Simulate racing for 10 seconds
    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        moveCars();
        printf("Cars' positions:\n");
        for (int i = 0; i < MAX_CARS; i++) {
            printf("%s: (%d, %d) speed %d direction %d\n", cars[i].name, cars[i].x, cars[i].y, cars[i].speed, cars[i].direction);
        }

        sleep(1);
    }

    return 0;
}