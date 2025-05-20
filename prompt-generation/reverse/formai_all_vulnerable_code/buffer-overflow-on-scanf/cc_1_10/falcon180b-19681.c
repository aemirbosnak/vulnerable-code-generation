//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 20
#define MIN_SPEED 1
#define MAX_TURN 20
#define MIN_TURN 1
#define MAX_DISTANCE 1000
#define MIN_DISTANCE 1

typedef struct {
    int speed;
    int turn;
    int distance;
} vehicle_t;

void init_vehicle(vehicle_t* vehicle) {
    vehicle->speed = MAX_SPEED;
    vehicle->turn = MAX_TURN;
    vehicle->distance = MAX_DISTANCE;
}

void move_forward(vehicle_t* vehicle) {
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed -= 1;
    }
}

void turn_left(vehicle_t* vehicle) {
    if (vehicle->turn > MIN_TURN) {
        vehicle->turn -= 1;
    }
}

void turn_right(vehicle_t* vehicle) {
    if (vehicle->turn < MAX_TURN) {
        vehicle->turn += 1;
    }
}

void move_backward(vehicle_t* vehicle) {
    if (vehicle->speed < MAX_SPEED) {
        vehicle->speed += 1;
    }
}

void decrease_distance(vehicle_t* vehicle) {
    if (vehicle->distance > MIN_DISTANCE) {
        vehicle->distance -= 1;
    }
}

void increase_distance(vehicle_t* vehicle) {
    if (vehicle->distance < MAX_DISTANCE) {
        vehicle->distance += 1;
    }
}

void stop(vehicle_t* vehicle) {
    vehicle->speed = 0;
    vehicle->turn = 0;
}

int main() {
    vehicle_t vehicle;
    init_vehicle(&vehicle);

    srand(time(NULL));

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Move backward\n");
        printf("5. Decrease distance\n");
        printf("6. Increase distance\n");
        printf("7. Stop\n");
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
                decrease_distance(&vehicle);
                break;
            case 6:
                increase_distance(&vehicle);
                break;
            case 7:
                stop(&vehicle);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Current speed: %d\n", vehicle.speed);
        printf("Current turn: %d\n", vehicle.turn);
        printf("Current distance: %d\n", vehicle.distance);
    } while (1);

    return 0;
}