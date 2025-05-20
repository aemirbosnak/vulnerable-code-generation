//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

/**
 * The C Drone Remote Control Program
 * This program simulates a drone remote control system.
 *
 * It allows the user to control the drone by either:
 * - Moving the drone up/down and left/right
 * - Changing the drone's altitude
 *
 * The user can also view the drone's current flight status, which includes:
 * - Altitude
 * - Speed
 * - Battery life
 */

int main(void) {
    int altitude = 0;
    int speed = 0;
    int battery_life = 100;
    char user_input;
    int is_running = 1;

    printf("Welcome to the C Drone Remote Control Program!\n");

    while (is_running) {
        printf("\n------------------------\n");
        printf("Current Altitude: %d\n", altitude);
        printf("Current Speed: %d\n", speed);
        printf("Current Battery Life: %d%%\n", battery_life);

        printf("\nEnter a command to control the drone (u/d/l/r/a/q): ");
        scanf(" %c", &user_input);

        switch(user_input) {
            case 'u':
                altitude++;
                speed++;
                break;
            case 'd':
                altitude--;
                speed--;
                break;
            case 'l':
                speed--;
                break;
            case 'r':
                speed++;
                break;
            case 'a':
                printf("Enter a new altitude: ");
                scanf("%d", &altitude);
                speed = 0;
                break;
            case 'q':
                printf("Shutting down the C Drone Remote Control Program...\n");
                is_running = 0;
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        if (altitude < 0) {
            altitude = 0;
            printf("The drone has crashed due to altitude.\n");
            is_running = 0;
        } else if (altitude > 100) {
            altitude = 100;
            printf("The drone has reached its maximum altitude.\n");
        }

        if (speed < -10) {
            speed = -10;
            printf("The drone is moving too slow.\n");
        } else if (speed > 10) {
            speed = 10;
            printf("The drone is moving too fast.\n");
        }

        battery_life--;

        if (battery_life < 0) {
            battery_life = 0;
            printf("The drone has ran out of battery life.\n");
            is_running = 0;
        }
    }

    return EXIT_SUCCESS;
}