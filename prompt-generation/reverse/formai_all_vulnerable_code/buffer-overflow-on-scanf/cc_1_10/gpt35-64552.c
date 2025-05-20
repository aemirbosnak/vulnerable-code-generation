//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>

// create a struct for the remote control vehicle
struct rc_vehicle {
    int speed;
    int direction;
};

void main() {
    // initialize the remote control vehicle
    struct rc_vehicle car;
    car.speed = 0;
    car.direction = 0;

    printf("Hello! Welcome to the RC Vehicle Simulator.\n");

    // simulate the user controlling the vehicle
    while (1) {
        int input;

        printf("\nPlease enter a command (1-5):\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");

        scanf("%d", &input);

        // react to user input
        switch(input) {
            case 1:
                car.speed += 10;
                printf("Current speed: %d\n", car.speed);
                break;
            case 2:
                car.speed -= 10;
                if (car.speed < 0) {
                    car.speed = 0;
                }
                printf("Current speed: %d\n", car.speed);
                break;
            case 3:
                car.direction -= 1;
                printf("Current direction: %d\n", car.direction);
                break;
            case 4:
                car.direction += 1;
                printf("Current direction: %d\n", car.direction);
                break;
            case 5:
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
}