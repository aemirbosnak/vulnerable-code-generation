//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define WHEEL_RADIUS 0.05
#define WHEEL_BASE 0.15

#define LEFT_MOTOR 1
#define RIGHT_MOTOR 2

void forward(int speed) {
    printf("Moving forward at %d%% speed\n", speed);
}

void backward(int speed) {
    printf("Moving backward at %d%% speed\n", speed);
}

void turn_left(int speed) {
    printf("Turning left at %d%% speed\n", speed);
}

void turn_right(int speed) {
    printf("Turning right at %d%% speed\n", speed);
}

void stop() {
    printf("Stopping the robot\n");
}

int main() {
    int choice, speed;

    printf("Welcome to the Robot Control Program\n");
    printf("Please choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Stop\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the speed (1-100): ");
            scanf("%d", &speed);
            forward(speed);
            break;
        case 2:
            printf("Enter the speed (1-100): ");
            scanf("%d", &speed);
            backward(speed);
            break;
        case 3:
            printf("Enter the speed (1-100): ");
            scanf("%d", &speed);
            turn_left(speed);
            break;
        case 4:
            printf("Enter the speed (1-100): ");
            scanf("%d", &speed);
            turn_right(speed);
            break;
        case 5:
            stop();
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}