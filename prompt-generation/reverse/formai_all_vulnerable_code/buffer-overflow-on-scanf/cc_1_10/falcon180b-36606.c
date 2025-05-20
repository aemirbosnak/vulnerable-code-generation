//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define STEP_SIZE 10

typedef struct {
    int x;
    int y;
    int speed;
    int direction;
} Vehicle;

void draw_vehicle(Vehicle v) {
    printf("Vehicle at position (%d, %d) with speed %d and direction %d\n", v.x, v.y, v.speed, v.direction);
}

void move_vehicle(Vehicle* v, int dx, int dy) {
    v->x += dx;
    v->y += dy;
}

int main() {
    srand(time(NULL));
    int width = rand() % 50 + 10;
    int height = rand() % 30 + 10;
    int vehicle_x = rand() % width;
    int vehicle_y = rand() % height;
    int vehicle_speed = MIN_SPEED;
    int vehicle_direction = 0;

    Vehicle vehicle = {.x = vehicle_x,.y = vehicle_y,.speed = vehicle_speed,.direction = vehicle_direction};

    char command;
    while (1) {
        printf("Current vehicle position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Enter command (f/b/l/r/+/-) to move the vehicle:\n");
        scanf(" %c", &command);

        switch (command) {
            case 'f':
                vehicle_direction = 0;
                break;
            case 'b':
                vehicle_direction = 1;
                break;
            case 'l':
                vehicle_direction = 2;
                break;
            case 'r':
                vehicle_direction = 3;
                break;
            case '+':
                vehicle_speed += STEP_SIZE;
                if (vehicle_speed > MAX_SPEED) {
                    vehicle_speed = MAX_SPEED;
                }
                break;
            case '-':
                vehicle_speed -= STEP_SIZE;
                if (vehicle_speed < MIN_SPEED) {
                    vehicle_speed = MIN_SPEED;
                }
                break;
            default:
                printf("Invalid command\n");
        }

        move_vehicle(&vehicle, 0, 0);
        draw_vehicle(vehicle);
    }

    return 0;
}