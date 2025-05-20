//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pitch = 0;
    int yaw = 0;
    int roll = 0;
    int throttle = 0;
    int isArmed = 0;

    printf("Welcome to the C Drone Remote Control Program\n");

    while (1) {
        printf("Please enter the pitch, yaw, roll and throttle values separated by spaces: ");
        scanf("%d %d %d %d", &pitch, &yaw, &roll, &throttle);

        if (pitch > 100 || yaw > 100 || roll > 100 || throttle > 100) {
            printf("Invalid input values. Please enter values between 0 and 100.\n");
            continue;
        }

        printf("Commands to send to drone: Pitch=%d, Yaw=%d, Roll=%d, Throttle=%d\n", 
                pitch, yaw, roll, throttle);

        printf("Would you like to arm the drone? (1 for YES, 0 for NO): ");
        scanf("%d", &isArmed);

        if (isArmed != 0 && isArmed != 1) {
            printf("Invalid input. Please enter 1 for YES or 0 for NO.\n");
            continue;
        }

        if (isArmed == 1) {
            printf("Arming the drone...\n");
            // send command to arm drone
        }

        printf("Would you like to disarm the drone? (1 for YES, 0 for NO): ");
        scanf("%d", &isArmed);

        if (isArmed != 0 && isArmed != 1) {
            printf("Invalid input. Please enter 1 for YES or 0 for NO.\n");
            continue;
        }

        if (isArmed == 1) {
            printf("Disarming the drone...\n");
            // send command to disarm drone
        }

        printf("Would you like to exit the program? (1 for YES, 0 for NO): ");
        scanf("%d", &isArmed);

        if (isArmed != 0 && isArmed != 1) {
            printf("Invalid input. Please enter 1 for YES or 0 for NO.\n");
            continue;
        }

        if (isArmed == 1) {
            printf("Exiting the program...\n");
            break;
        }
    }

    return 0;
}