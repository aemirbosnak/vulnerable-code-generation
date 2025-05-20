//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 180
#define MIN_ANGLE 0

typedef struct {
    int speed;
    int angle;
} DroneData;

int getSpeedInput() {
    int speed;
    printf("Enter drone speed (0-100): ");
    scanf("%d", &speed);
    if (speed > MAX_SPEED) {
        printf("Maximum speed is %d. Setting speed to %d.\n", MAX_SPEED, MAX_SPEED);
        speed = MAX_SPEED;
    } else if (speed < MIN_SPEED) {
        printf("Minimum speed is %d. Setting speed to %d.\n", MIN_SPEED, MIN_SPEED);
        speed = MIN_SPEED;
    }
    return speed;
}

int getAngleInput() {
    int angle;
    printf("Enter drone angle (0-180): ");
    scanf("%d", &angle);
    if (angle > MAX_ANGLE) {
        printf("Maximum angle is %d. Setting angle to %d.\n", MAX_ANGLE, MAX_ANGLE);
        angle = MAX_ANGLE;
    } else if (angle < MIN_ANGLE) {
        printf("Minimum angle is %d. Setting angle to %d.\n", MIN_ANGLE, MIN_ANGLE);
        angle = MIN_ANGLE;
    }
    return angle;
}

void printDroneData(DroneData data) {
    printf("Drone speed: %d\n", data.speed);
    printf("Drone angle: %d\n", data.angle);
}

void setDroneData(DroneData *data) {
    data->speed = getSpeedInput();
    data->angle = getAngleInput();
}

int main() {
    DroneData droneData = { 0, 0 };
    char input;
    do {
        printf("Choose option:\n");
        printf("1. Set drone data\n");
        printf("2. Print drone data\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf(" %c", &input);
        switch (input) {
            case '1':
                setDroneData(&droneData);
                break;
            case '2':
                printDroneData(droneData);
                break;
            case '3':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (input != '3');
    return 0;
}