//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 50
#define MIN_SPEED 1
#define TURN_RADIUS 10
#define FORWARD_SPEED 20
#define BACKWARD_SPEED -20
#define LEFT_SPEED -20
#define RIGHT_SPEED 20

typedef struct {
    int speed;
    int direction;
} Vehicle;

void move_forward(Vehicle* vehicle) {
    printf("Romantically moving forward...\n");
    vehicle->speed = FORWARD_SPEED;
    vehicle->direction = 0;
}

void turn_left(Vehicle* vehicle) {
    printf("Gracefully turning left...\n");
    vehicle->speed = LEFT_SPEED;
    vehicle->direction = -90;
}

void turn_right(Vehicle* vehicle) {
    printf("Elegantly turning right...\n");
    vehicle->speed = RIGHT_SPEED;
    vehicle->direction = 90;
}

void move_backward(Vehicle* vehicle) {
    printf("Smoothly moving backward...\n");
    vehicle->speed = BACKWARD_SPEED;
    vehicle->direction = 180;
}

void stop(Vehicle* vehicle) {
    printf("Coming to a gentle stop...\n");
    vehicle->speed = 0;
}

int main() {
    Vehicle vehicle;

    printf("Starting the remote controlled vehicle...\n");
    vehicle.speed = 0;
    vehicle.direction = 0;

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Move backward\n");
        printf("5. Stop\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_forward(&vehicle);
                break;
            case 2:
                turn_left(&vehicle);
                break;
            case 3:
                turn_right(&vehicle);
                break;
            case 4:
                move_backward(&vehicle);
                break;
            case 5:
                stop(&vehicle);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice!= 6);

    return 0;
}