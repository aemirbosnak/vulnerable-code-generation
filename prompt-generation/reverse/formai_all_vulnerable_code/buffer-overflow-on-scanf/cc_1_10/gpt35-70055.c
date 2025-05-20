//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define ARMED 1
#define DISARMED 0

#define CALIBRATION_THRESHOLD 50

int currentAltitude = 0;
int currentSpeed = 0;
int currentDirection = 0; // 0 for North, 90 for East, 180 for South, and 270 for West

int currentBatteryLevel = 100;
int droneState = DISARMED;

void armDrone() {
    droneState = ARMED;
    printf("Drone is armed.\n");
}

void disarmDrone() {
    if (currentAltitude == 0) {
        droneState = DISARMED;
        printf("Drone is unarmed.\n");
    } else {
        printf("Cannot disarm the drone at this altitude: %d meters.\n", currentAltitude);
    }
}

void calibrateDrone() {
    printf("Calibrating the drone...\n");
    // ...

    if (currentAltitude <= CALIBRATION_THRESHOLD) {
        printf("Drone is calibrated.\n");
    } else {
        printf("Cannot calibrate the drone at this altitude: %d meters.\n", currentAltitude);
    }
}

void takeOff(int altitude) {
    if (droneState == DISARMED) {
        printf("Drone is not armed.\n");
        return;
    }

    if (altitude <= 0) {
        printf("Invalid altitude: %d meters.\n", altitude);
        return;
    }

    if (currentBatteryLevel < 20) {
        printf("Cannot take off. Low battery: %d %%\n", currentBatteryLevel);
        return;
    }

    printf("Taking off to %d meters...\n", altitude);
    currentAltitude = altitude;
}

void land() {
    if (droneState == DISARMED) {
        printf("Drone is not armed.\n");
        return;
    }

    if (currentAltitude == 0) {
        printf("Drone is already landed.\n");
        return;
    }

    printf("Landing...\n");
    currentAltitude = 0;
}

void move(int speed, int direction) {
    if (droneState == DISARMED) {
        printf("Drone is not armed.\n");
        return;
    }

    if (currentBatteryLevel < 50) {
        printf("Cannot move. Low battery: %d %%\n", currentBatteryLevel);
        return;
    }

    printf("Moving at %d meters per second to %d degrees...\n", speed, direction);

    currentSpeed = speed;
    currentDirection = direction;
}

int main() {
    printf("Welcome to the drone remote control!\n");

    while (1) {
        char input[20];
        printf("Enter a command: ");
        scanf("%s", input);

        if (strcmp(input, "arm") == 0) {
            armDrone();
        } else if (strcmp(input, "disarm") == 0) {
            disarmDrone();
        } else if (strcmp(input, "calibrate") == 0) {
            calibrateDrone();
        } else if (strcmp(input, "takeoff") == 0) {
            int altitude;
            printf("Enter an altitude: ");
            scanf("%d", &altitude);
            takeOff(altitude);
        } else if (strcmp(input, "land") == 0) {
            land();
        } else if (strcmp(input, "move") == 0) {
            int speed, direction;
            printf("Enter a speed: ");
            scanf("%d", &speed);
            printf("Enter a direction (in degrees): ");
            scanf("%d", &direction);
            move(speed, direction);
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}