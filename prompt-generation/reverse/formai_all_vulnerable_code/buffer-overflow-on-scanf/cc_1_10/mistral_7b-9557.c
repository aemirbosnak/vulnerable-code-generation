//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define SPEED 1

typedef struct {
    int x, y;
} position;

void move_vehicle(position *vehicle, int direction) {
    switch (direction) {
        case 'W':
            vehicle->y--;
            break;
        case 'S':
            vehicle->y++;
            break;
        case 'A':
            vehicle->x--;
            break;
        case 'D':
            vehicle->x++;
            break;
    }
}

int main() {
    srand(time(NULL));
    position vehicle = {5, 5};
    char direction;

    while (1) {
        printf("Current position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Enter direction (W/A/S/D): ");
        scanf("%c", &direction);

        move_vehicle(&vehicle, direction);

        // Randomly change direction
        if (rand() % 100 < 10) {
            direction = rand() % 4 + 'A';
            printf("\nVehicle changed direction to %c.\n", direction);
            move_vehicle(&vehicle, direction);
        }
    }

    return 0;
}