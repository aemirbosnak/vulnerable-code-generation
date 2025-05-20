//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct RCVehicle {
    int speed;
    int steering;
};

int main() {
    struct RCVehicle car = {0, 0};

    printf("Welcome to the RC Vehicle Simulation!\n");

    while (1) {
        printf("\nEnter your input:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                car.speed += 10;
                break;
            case 2:
                car.speed -= 10;
                break;
            case 3:
                car.steering += 10;
                break;
            case 4:
                car.steering -= 10;
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Speed: %d\n", car.speed);
        printf("Steering: %d\n", car.steering);

        if (car.speed < 0) {
            car.speed = 0;
        } else if (car.speed > 100) {
            car.speed = 100;
        }

        if (car.steering < 0) {
            car.steering = 0;
        } else if (car.steering > 100) {
            car.steering = 100;
        }
    }

    return 0;
}