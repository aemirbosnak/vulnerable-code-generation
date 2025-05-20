//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_VEHICLE_COUNT 100
#define MAX_STEPS 1000
#define MAX_SPEED 10

struct vehicle {
    int x;
    int y;
    int direction;
    int speed;
};

struct vehicle vehicles[MAX_VEHICLE_COUNT];
int vehicle_count = 0;

int main(int argc, char* argv[]) {
    int steps;
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <steps>\n", argv[0]);
        exit(1);
    }

    steps = atoi(argv[1]);

    printf("Remote Control Vehicle Simulation\n");
    printf("-----------------------------\n");

    for (i = 0; i < MAX_VEHICLE_COUNT; i++) {
        vehicles[i].x = rand() % (MAX_STEPS + 1);
        vehicles[i].y = rand() % (MAX_STEPS + 1);
        vehicles[i].direction = rand() % 4;
        vehicles[i].speed = rand() % MAX_SPEED + 1;
        vehicle_count++;
    }

    printf("Vehicle count: %d\n", vehicle_count);

    for (i = 0; i < steps; i++) {
        printf("Step %d:\n", i + 1);

        for (int j = 0; j < vehicle_count; j++) {
            switch (vehicles[j].direction) {
                case 0:
                    vehicles[j].x += vehicles[j].speed;
                    break;
                case 1:
                    vehicles[j].x -= vehicles[j].speed;
                    break;
                case 2:
                    vehicles[j].y += vehicles[j].speed;
                    break;
                case 3:
                    vehicles[j].y -= vehicles[j].speed;
                    break;
            }

            if (vehicles[j].x < 0 || vehicles[j].x >= MAX_STEPS ||
                vehicles[j].y < 0 || vehicles[j].y >= MAX_STEPS) {
                vehicles[j].speed = 0;
            }
        }

        for (int j = 0; j < vehicle_count; j++) {
            printf("Vehicle %d: x=%d, y=%d, speed=%d\n", j + 1,
                   vehicles[j].x, vehicles[j].y, vehicles[j].speed);
        }
    }

    printf("\nSimulation complete.\n");
    return 0;
}