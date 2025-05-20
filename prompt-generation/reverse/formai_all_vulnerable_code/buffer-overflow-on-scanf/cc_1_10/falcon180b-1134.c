//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN_SPEED 1000
#define MIN_TURN_SPEED 500

struct vehicle {
    int speed;
    int turn_speed;
    int direction;
};

void init_vehicle(struct vehicle *vehicle) {
    vehicle->speed = 0;
    vehicle->turn_speed = 0;
    vehicle->direction = 0;
}

void move_forward(struct vehicle *vehicle, int speed) {
    printf("Moving forward at %d units/second\n", speed);
    vehicle->speed = speed;
    vehicle->direction = 0;
}

void turn_left(struct vehicle *vehicle, int turn_speed) {
    printf("Turning left at %d degrees/second\n", turn_speed);
    vehicle->turn_speed = turn_speed;
    vehicle->direction = -1;
}

void turn_right(struct vehicle *vehicle, int turn_speed) {
    printf("Turning right at %d degrees/second\n", turn_speed);
    vehicle->turn_speed = turn_speed;
    vehicle->direction = 1;
}

void stop_vehicle(struct vehicle *vehicle) {
    printf("Stopping the vehicle\n");
    vehicle->speed = 0;
    vehicle->turn_speed = 0;
    vehicle->direction = 0;
}

int main() {
    struct vehicle my_vehicle;
    init_vehicle(&my_vehicle);

    int choice;
    do {
        printf("\nRemote Control Vehicle Simulation\n");
        printf("1. Move Forward\n");
        printf("2. Turn Left\n");
        printf("3. Turn Right\n");
        printf("4. Stop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the speed (1-10): ");
                int speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
                move_forward(&my_vehicle, speed);
                break;
            case 2:
                printf("Enter the turn speed (500-1000): ");
                int turn_speed = rand() % (MAX_TURN_SPEED - MIN_TURN_SPEED + 1) + MIN_TURN_SPEED;
                turn_left(&my_vehicle, turn_speed);
                break;
            case 3:
                printf("Enter the turn speed (500-1000): ");
                turn_right(&my_vehicle, rand() % (MAX_TURN_SPEED - MIN_TURN_SPEED + 1) + MIN_TURN_SPEED);
                break;
            case 4:
                stop_vehicle(&my_vehicle);
                break;
            default:
                printf("Invalid choice\n");
        }
        sleep(1);
    } while (1);

    return 0;
}