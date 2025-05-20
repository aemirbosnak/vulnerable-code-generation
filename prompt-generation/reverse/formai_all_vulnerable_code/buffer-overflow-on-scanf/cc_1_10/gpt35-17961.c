//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
#include <stdio.h>

struct RemoteControlVehicle {
    int speed;
    int batteryLevel;
    int isOn;
};

void startVehicle(struct RemoteControlVehicle *vehicle) {
    vehicle->isOn = 1;
    printf("Vehicle started!\n");
}

void stopVehicle(struct RemoteControlVehicle *vehicle) {
    vehicle->isOn = 0;
    printf("Vehicle stopped.\n");
}

void increaseSpeed(struct RemoteControlVehicle *vehicle) {
    if (vehicle->isOn && vehicle->batteryLevel > 0) {
        vehicle->speed++;
        vehicle->batteryLevel--;
        printf("Speed increased to %d mph.\n", vehicle->speed);
    } else if (!vehicle->isOn) {
        printf("Cannot increase speed. Vehicle is not turned on.\n");
    } else {
        printf("Cannot increase speed. Battery level is too low.\n");
    }
}

void decreaseSpeed(struct RemoteControlVehicle *vehicle) {
    if (vehicle->isOn && vehicle->speed > 0) {
        vehicle->speed--;
        printf("Speed decreased to %d mph.\n", vehicle->speed);
    } else if (!vehicle->isOn) {
        printf("Cannot decrease speed. Vehicle is not turned on.\n");
    } else {
        printf("Cannot decrease speed further.\n");
    }
}

void checkBattery(struct RemoteControlVehicle *vehicle) {
    printf("Battery level: %d%%.\n", vehicle->batteryLevel);
}

int main() {
    struct RemoteControlVehicle vehicle = {0, 100, 0};

    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Commands:\n");
    printf("1: Start vehicle\n");
    printf("2: Stop vehicle\n");
    printf("3: Increase speed\n");
    printf("4: Decrease speed\n");
    printf("5: Check battery level\n");
    printf("0: Exit simulator\n");

    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                startVehicle(&vehicle);
                break;
            case 2:
                stopVehicle(&vehicle);
                break;
            case 3:
                increaseSpeed(&vehicle);
                break;
            case 4:
                decreaseSpeed(&vehicle);
                break;
            case 5:
                checkBattery(&vehicle);
                break;
            case 0:
                printf("Exiting simulator...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}