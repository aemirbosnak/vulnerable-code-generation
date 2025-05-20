//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    int droneId;
    printf("Enter drone ID: ");
    scanf("%d", &droneId);

    if (droneId <= 0 || droneId > 100) {
        printf("Error: Invalid drone ID!\n");
        return 1;
    }

    int batteryLevel = 100;
    int altitude = 0;
    int speed = 0;
    int direction = 0;

    printf("----- Drone Control Panel -----\n");
    printf("Drone ID: %d\n", droneId);
    printf("Battery Level: %d%%\n", batteryLevel);
    printf("Altitude: %d meters\n", altitude);
    printf("Speed: %d km/h\n", speed);
    printf("Direction: %d degrees\n", direction);
    printf("-------------------------------\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Increase altitude\n");
        printf("2. Decrease altitude\n");
        printf("3. Increase speed\n");
        printf("4. Decrease speed\n");
        printf("5. Change direction\n");
        printf("6. Land\n");
        printf("7. Emergency stop\n");
        printf("8. Exit\n");

        int option;
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                altitude += 10;
                if (altitude > 500) {
                    printf("Error: Maximum altitude exceeded!\n");
                    altitude = 500;
                } else {
                    printf("Increased altitude to %d meters.\n", altitude);
                }
                break;
            case 2:
                altitude -= 10;
                if (altitude < 0) {
                    printf("Error: Minimum altitude reached!\n");
                    altitude = 0;
                } else {
                    printf("Decreased altitude to %d meters.\n", altitude);
                }
                break;
            case 3:
                speed += 10;
                if (speed > 100) {
                    printf("Error: Maximum speed exceeded!\n");
                    speed = 100;
                } else {
                    printf("Increased speed to %d km/h.\n", speed);
                }
                break;
            case 4:
                speed -= 10;
                if (speed < 0) {
                    printf("Error: Minimum speed reached!\n");
                    speed = 0;
                } else {
                    printf("Decreased speed to %d km/h.\n", speed);
                }
                break;
            case 5:
                printf("Enter new direction (in degrees): ");
                scanf("%d", &direction);
                if (direction < 0 || direction > 360) {
                    printf("Error: Invalid direction!\n");
                    direction = 0;
                } else {
                    printf("Changed direction to %d degrees.\n", direction);
                }
                break;
            case 6:
                altitude = 0;
                printf("Landing drone...\n");
                break;
            case 7:
                altitude = 0;
                speed = 0;
                direction = 0;
                printf("Emergency stop!\n");
                break;
            case 8:
                printf("Exiting control panel...\n");
                exit(0);
            default:
                printf("Error: Invalid option!\n");
                break;
        }

        if (altitude > 0) {
            batteryLevel -= altitude/10;
        } else {
            batteryLevel -= speed/10;
        }

        if (batteryLevel <= 0) {
            printf("Error: Drone battery dead!\n");
            altitude = 0;
            speed = 0;
            direction = 0;
            break;
        }

        printf("-------------------------------\n");
        printf("Drone ID: %d\n", droneId);
        printf("Battery Level: %d%%\n", batteryLevel);
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d km/h\n", speed);
        printf("Direction: %d degrees\n", direction);
        printf("-------------------------------\n");
    }

    return 0;
}