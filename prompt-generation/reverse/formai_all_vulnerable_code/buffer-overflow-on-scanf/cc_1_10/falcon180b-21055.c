//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int speed;
    int direction;
} Vehicle;

void initialize(Vehicle *vehicle, int x, int y, int speed, int direction) {
    vehicle->x = x;
    vehicle->y = y;
    vehicle->speed = speed;
    vehicle->direction = direction;
}

void move(Vehicle *vehicle) {
    vehicle->x += (vehicle->speed * cos(vehicle->direction)) / 100;
    vehicle->y += (vehicle->speed * sin(vehicle->direction)) / 100;
}

void turn(Vehicle *vehicle, int angle) {
    vehicle->direction += angle;
    if (vehicle->direction > 360) {
        vehicle->direction -= 360;
    } else if (vehicle->direction < 0) {
        vehicle->direction += 360;
    }
}

int main() {
    srand(time(NULL));

    Vehicle vehicle;
    initialize(&vehicle, 0, 0, 100, rand() % 360);

    while (1) {
        system("clear");
        printf("Current position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Current speed: %d\n", vehicle.speed);
        printf("Current direction: %d degrees\n", vehicle.direction);

        char command[100];
        scanf("%s", command);

        if (strcmp(command, "forward") == 0) {
            move(&vehicle);
        } else if (strcmp(command, "turn") == 0) {
            int angle;
            scanf("%d", &angle);
            turn(&vehicle, angle);
        } else if (strcmp(command, "stop") == 0) {
            vehicle.speed = 0;
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}