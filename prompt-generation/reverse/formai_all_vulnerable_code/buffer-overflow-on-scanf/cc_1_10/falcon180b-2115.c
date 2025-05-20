//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Drone control functions
void flyForward(int speed) {
    printf("Drone is flying forward at %d meters per second.\n", speed);
}

void flyBackward(int speed) {
    printf("Drone is flying backward at %d meters per second.\n", speed);
}

void flyLeft(int speed) {
    printf("Drone is flying left at %d meters per second.\n", speed);
}

void flyRight(int speed) {
    printf("Drone is flying right at %d meters per second.\n", speed);
}

void rotateClockwise(int speed) {
    printf("Drone is rotating clockwise at %d degrees per second.\n", speed);
}

void rotateCounterClockwise(int speed) {
    printf("Drone is rotating counterclockwise at %d degrees per second.\n", speed);
}

void takeoff() {
    printf("Drone is taking off.\n");
}

void land() {
    printf("Drone is landing.\n");
}

// Remote control functions
void remoteControl() {
    int choice;

    while(1) {
        printf("\nWelcome to the Drone Remote Control!\n");
        printf("1. Takeoff\n");
        printf("2. Fly Forward\n");
        printf("3. Fly Backward\n");
        printf("4. Fly Left\n");
        printf("5. Fly Right\n");
        printf("6. Rotate Clockwise\n");
        printf("7. Rotate Counterclockwise\n");
        printf("8. Land\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                takeoff();
                break;
            case 2:
                flyForward(5);
                break;
            case 3:
                flyBackward(5);
                break;
            case 4:
                flyLeft(5);
                break;
            case 5:
                flyRight(5);
                break;
            case 6:
                rotateClockwise(10);
                break;
            case 7:
                rotateCounterClockwise(10);
                break;
            case 8:
                land();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    remoteControl();
    return 0;
}