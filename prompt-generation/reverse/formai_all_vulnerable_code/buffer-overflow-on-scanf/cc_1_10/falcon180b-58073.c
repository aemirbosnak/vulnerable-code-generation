//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50
#define MIN_SPEED 1
#define ACCELERATION 5

//struct to hold vehicle data
typedef struct {
    int speed;
    int direction;
    int position;
} vehicle_t;

void init_vehicle(vehicle_t* vehicle) {
    vehicle->speed = MIN_SPEED;
    vehicle->direction = 1;
    vehicle->position = 0;
}

//move vehicle forward
void move_forward(vehicle_t* vehicle) {
    if(vehicle->speed < MAX_SPEED) {
        vehicle->speed += ACCELERATION;
    }
    vehicle->position += vehicle->speed;
    printf("Vehicle is moving forward at %d units per second, current position is %d\n", vehicle->speed, vehicle->position);
}

//move vehicle backward
void move_backward(vehicle_t* vehicle) {
    if(vehicle->speed > MIN_SPEED) {
        vehicle->speed -= ACCELERATION;
    }
    vehicle->position -= vehicle->speed;
    printf("Vehicle is moving backward at %d units per second, current position is %d\n", vehicle->speed, vehicle->position);
}

//turn vehicle left
void turn_left(vehicle_t* vehicle) {
    vehicle->direction = -1;
    printf("Vehicle is turning left, current direction is %d\n", vehicle->direction);
}

//turn vehicle right
void turn_right(vehicle_t* vehicle) {
    vehicle->direction = 1;
    printf("Vehicle is turning right, current direction is %d\n", vehicle->direction);
}

//main function to simulate vehicle movement
int main() {
    vehicle_t vehicle;
    init_vehicle(&vehicle);

    int choice;
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move_forward(&vehicle);
                break;
            case 2:
                move_backward(&vehicle);
                break;
            case 3:
                turn_left(&vehicle);
                break;
            case 4:
                turn_right(&vehicle);
                break;
            default:
                printf("Invalid choice\n");
        }
        sleep(1);
    }

    return 0;
}