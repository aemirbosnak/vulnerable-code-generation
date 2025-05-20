//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>

#define MAX_SPEED 100
#define DEFAULT_SPEED 50

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int speed;
    Position position;
} RCVehicle;

void print_position(Position p) {
    printf("Current Position: (%d, %d)\n", p.x, p.y);
}

void print_speed(int s) {
    printf("Speed: %d\n", s);
}

void move_forward(RCVehicle *vehicle) {
    vehicle->position.x += vehicle->speed;
    print_position(vehicle->position);
}

void move_backward(RCVehicle *vehicle) {
    vehicle->position.x -= vehicle->speed;
    print_position(vehicle->position);
}

void increase_speed(RCVehicle *vehicle) {
    if (vehicle->speed + 10 <= MAX_SPEED) {
        vehicle->speed += 10;
        print_speed(vehicle->speed);
    } else {
        printf("Cannot increase speed beyond %d\n", MAX_SPEED);
    }
}

void decrease_speed(RCVehicle *vehicle) {
    if (vehicle->speed - 10 >= 0) {
        vehicle->speed -= 10;
        print_speed(vehicle->speed);
    } else {
        printf("Cannot decrease speed below 0\n");
    }
}

int main() {
    RCVehicle vehicle = {DEFAULT_SPEED, {0, 0}};

    printf("RCVehicle Simulator\n");
    printf("-------------------\n\n");
    printf("Starting Position: (%d, %d)\n", vehicle.position.x, vehicle.position.y);
    printf("Starting Speed: %d\n\n", vehicle.speed);

    char input;
    do {
        printf("Enter a command (F=move forward, B=move backward, I=increase speed, D=decrease speed, Q=quit): ");
        scanf(" %c", &input);

        switch (input) {
            case 'F':
            case 'f':
                move_forward(&vehicle);
                break;
            case 'B':
            case 'b':
                move_backward(&vehicle);
                break;
            case 'I':
            case 'i':
                increase_speed(&vehicle);
                break;
            case 'D':
            case 'd':
                decrease_speed(&vehicle);
                break;
            case 'Q':
            case 'q':
                printf("Exiting RCVehicle Simulator...\n");
                break;
            default:
                printf("Invalid command! Try again.\n");
        }
    } while (input != 'Q' && input != 'q');

    return 0;
}