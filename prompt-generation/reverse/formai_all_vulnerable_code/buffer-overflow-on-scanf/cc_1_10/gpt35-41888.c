//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MAX_ANGLE 180

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int speed;
    int angle;
} Direction;

typedef struct {
    Position position;
    Direction direction;
} Vehicle;

void printVehicleStatus(Vehicle *vehicle) {
    printf("Vehicle Status:\n");
    printf("Position: (%d,%d)\n", vehicle->position.x, vehicle->position.y);
    printf("Speed: %d\n", vehicle->direction.speed);
    printf("Angle: %d\n", vehicle->direction.angle);
}

void changeVehicleDirection(Vehicle *vehicle) {
    vehicle->direction.speed = rand() % MAX_SPEED + 1;
    vehicle->direction.angle = rand() % MAX_ANGLE + 1;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Remote Control Vehicle Simulation!\n\n");

    Vehicle vehicle;
    vehicle.position.x = 0;
    vehicle.position.y = 0;
    vehicle.direction.speed = 0;
    vehicle.direction.angle = 0;

    printVehicleStatus(&vehicle);

    char input;
    do {
        printf("\nPlease enter a control command (w: move forward, a: turn left, d: turn right, r: randomize direction, q: quit): ");
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                vehicle.position.x += vehicle.direction.speed;
                vehicle.position.y += vehicle.direction.speed;
                break;
            case 'a':
                vehicle.direction.angle += 10;
                if (vehicle.direction.angle > MAX_ANGLE) {
                    vehicle.direction.angle = MAX_ANGLE;
                }
                break;
            case 'd':
                vehicle.direction.angle -= 10;
                if (vehicle.direction.angle < 0) {
                    vehicle.direction.angle = 0;
                }
                break;
            case 'r':
                changeVehicleDirection(&vehicle);
                break;
            case 'q':
                break;
            default:
                printf("Invalid input!\n");
                break;
        }

        printVehicleStatus(&vehicle);
        
    } while (input != 'q');

    printf("\nThank you for using the Remote Control Vehicle Simulation!\n");

    return 0;
}