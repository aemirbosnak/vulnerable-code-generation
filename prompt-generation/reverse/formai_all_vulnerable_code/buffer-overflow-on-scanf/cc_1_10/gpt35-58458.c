//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the C Drone Remote Control program!\n\n");

    int batteryLevel = 100;
    int durability = 10;
    int droneSpeed = 50;
    int droneHeight = 0;

    printf("Battery Level: %d%%\n", batteryLevel);

    while (batteryLevel > 0) {
        printf("\nEnter drone speed (0-100): ");
        scanf("%d", &droneSpeed);

        if (droneSpeed < 0 || droneSpeed > 100) {
            printf("Invalid input. Please enter a speed between 0-100.\n");
            continue;
        }

        printf("Enter desired drone height (0-50): ");
        scanf("%d", &droneHeight);

        if (droneHeight < 0 || droneHeight > 50) {
            printf("Invalid input. Please enter a height between 0-50.\n");
            continue;
        }

        if (droneHeight > durability) {
            printf("Drone crashed! Durability reduced by 1.\n");
            durability--;
            continue;
        }

        if (droneSpeed * (droneHeight + 1) > batteryLevel) {
            printf("Warning! Low battery level. Please land the drone.\n");
        }

        printf("Drone taking off... \n\n");
        batteryLevel -= droneSpeed * (droneHeight + 1);
        printf("Battery Level: %d%%\n", batteryLevel);

        printf("Drone flying at %d%% speed and %d meters height.\n", droneSpeed, droneHeight);
        printf("Press any key to land the drone.\n");
        getchar();

        printf("Drone landing... \n\n");
        batteryLevel -= 5;
        printf("Battery Level: %d%%\n", batteryLevel);

        if (batteryLevel <= 0) {
            printf("Battery empty! Drone cannot fly anymore.\n");
            break;
        }
    }

    printf("\nThank you for using the C Drone Remote Control program!\n");
    return 0;
}