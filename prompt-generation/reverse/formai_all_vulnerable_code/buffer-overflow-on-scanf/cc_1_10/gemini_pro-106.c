//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int angle;
} Position;

typedef struct {
    Position position;
    bool is_on;
} Vehicle;

void move_forward(Vehicle *vehicle, int distance) {
    vehicle->position.x += distance * sin(vehicle->position.angle);
    vehicle->position.y += distance * cos(vehicle->position.angle);
}

void turn_left(Vehicle *vehicle, int angle) {
    vehicle->position.angle -= angle;
}

void turn_right(Vehicle *vehicle, int angle) {
    vehicle->position.angle += angle;
}

void print_position(Vehicle *vehicle) {
    printf("Position: (%d, %d), Angle: %d\n", vehicle->position.x, vehicle->position.y, vehicle->position.angle);
}

int main() {
    Vehicle vehicle = {
        .position = {
            .x = 0,
            .y = 0,
            .angle = 0
        },
        .is_on = false
    };

    while (true) {
        char command;
        scanf("%c", &command);

        switch (command) {
            case 'w':
                move_forward(&vehicle, 10);
                break;
            case 'a':
                turn_left(&vehicle, 10);
                break;
            case 'd':
                turn_right(&vehicle, 10);
                break;
            case 'p':
                print_position(&vehicle);
                break;
            case 'q':
                exit(0);
        }
    }

    return 0;
}