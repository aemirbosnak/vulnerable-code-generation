//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int speed;
    int direction;
} Vehicle;

void moveVehicle(Vehicle* vehicle, int steps) {
    vehicle->position.x += steps * vehicle->speed * vehicle->direction;
}

void turnVehicle(Vehicle* vehicle, int angle) {
    vehicle->direction += angle;
    if (vehicle->direction < 0) {
        vehicle->direction += 360;
    } else if (vehicle->direction > 360) {
        vehicle->direction -= 360;
    }
}

int main() {
    srand(time(NULL));

    int mapWidth = 10;
    int mapHeight = 10;

    char map[mapHeight][mapWidth];
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            map[i][j] = rand() % 2;
        }
    }

    Vehicle vehicle;
    vehicle.position.x = 0;
    vehicle.position.y = 0;
    vehicle.speed = 1;
    vehicle.direction = 0;

    while (TRUE) {
        system("clear");
        for (int i = 0; i < mapHeight; i++) {
            for (int j = 0; j < mapWidth; j++) {
                if (map[i][j] == 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("Vehicle: (%d, %d) Speed: %d Direction: %d\n",
               vehicle.position.x, vehicle.position.y, vehicle.speed, vehicle.direction);

        char command;
        scanf("%c", &command);

        switch (command) {
            case 'w':
                moveVehicle(&vehicle, 1);
                break;
            case's':
                moveVehicle(&vehicle, -1);
                break;
            case 'a':
                turnVehicle(&vehicle, -1);
                break;
            case 'd':
                turnVehicle(&vehicle, 1);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }

        if (vehicle.position.x < 0 || vehicle.position.x >= mapWidth ||
            vehicle.position.y < 0 || vehicle.position.y >= mapHeight ||
            map[vehicle.position.y][vehicle.position.x] == 1) {
            printf("Game over.\n");
            exit(0);
        }
    }

    return 0;
}