//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define DRONE_SPEED 10

typedef struct {
    int x;
    int y;
    int z;
} Vector3;

void moveDrone(Vector3* drone, int dx, int dy, int dz) {
    drone->x += dx * DRONE_SPEED;
    drone->y += dy * DRONE_SPEED;
    drone->z += dz * DRONE_SPEED;
}

int main() {
    Vector3 drone = {0, 0, 0};
    int running = 1;

    while (running) {
        printf("Enter movement (w/a/s/d): ");
        char move;
        scanf("%c", &move);

        switch (move) {
            case 'w':
                moveDrone(&drone, 0, 1, 0);
                break;
            case 'a':
                moveDrone(&drone, -1, 0, 0);
                break;
            case's':
                moveDrone(&drone, 0, -1, 0);
                break;
            case 'd':
                moveDrone(&drone, 1, 0, 0);
                break;
            default:
                printf("Invalid movement.\n");
        }

        printf("Drone position: (%d, %d, %d)\n", drone.x, drone.y, drone.z);

        if (move == 'q') {
            running = 0;
        }
    }

    return 0;
}