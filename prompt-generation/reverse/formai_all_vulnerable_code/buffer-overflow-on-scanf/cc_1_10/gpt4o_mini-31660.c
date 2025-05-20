//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int speed;
    int direction; // 0: Forward, 1: Backward, 2: Left, 3: Right
} RemoteControlVehicle;

void initializeVehicle(RemoteControlVehicle *vehicle, const char *name) {
    strcpy(vehicle->name, name);
    vehicle->speed = 0;
    vehicle->direction = 0; // Default is forward
}

void showVehicleStatus(RemoteControlVehicle *vehicle) {
    const char *directionStr[] = {"Forward", "Backward", "Left", "Right"};
    printf("Vehicle Name: %s\n", vehicle->name);
    printf("Speed: %d\n", vehicle->speed);
    printf("Direction: %s\n", directionStr[vehicle->direction]);
}

void moveVehicle(RemoteControlVehicle *vehicle) {
    if (vehicle->speed > 0) {
        printf("%s is moving at speed %d in the direction %d.\n", vehicle->name, vehicle->speed, vehicle->direction);
    } else {
        printf("%s is stationary.\n", vehicle->name);
    }
}

void changeSpeed(RemoteControlVehicle *vehicle, int newSpeed) {
    if (newSpeed >= 0) {
        vehicle->speed = newSpeed;
    } else {
        printf("Speed cannot be negative. Using previous speed: %d\n", vehicle->speed);
    }
}

void changeDirection(RemoteControlVehicle *vehicle, int newDirection) {
    if (newDirection >= 0 && newDirection <= 3) {
        vehicle->direction = newDirection;
    } else {
        printf("Invalid direction. Use 0: Forward, 1: Backward, 2: Left, 3: Right.\n");
    }
}

void displayMenu() {
    printf("\n--- Remote Control Vehicle Menu ---\n");
    printf("1. Show Vehicle Status\n");
    printf("2. Change Speed\n");
    printf("3. Change Direction\n");
    printf("4. Move Vehicle\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    RemoteControlVehicle vehicle;
    initializeVehicle(&vehicle, "MyRCCar");
    int choice;
    int newSpeed, newDirection;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                showVehicleStatus(&vehicle);
                break;
            case 2:
                printf("Enter new speed: ");
                scanf("%d", &newSpeed);
                changeSpeed(&vehicle, newSpeed);
                break;
            case 3:
                printf("Enter new direction (0: Forward, 1: Backward, 2: Left, 3: Right): ");
                scanf("%d", &newDirection);
                changeDirection(&vehicle, newDirection);
                break;
            case 4:
                moveVehicle(&vehicle);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}