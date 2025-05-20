//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>

int main() {
    int option, speed = 0, direction = 0, battery_level = 100;
    printf("Welcome to Remote Control Vehicle Simulation!\n");

    while(1) {
        printf("\nPlease select an option:\n");
        printf("1. Increase speed.\n");
        printf("2. Decrease speed.\n");
        printf("3. Turn left.\n");
        printf("4. Turn right.\n");
        printf("5. Show battery level.\n");
        printf("6. Exit.\n");
        printf("Option: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                speed += 5;
                printf("Speed increased to %d mph.\n", speed);
                break;
            case 2:
                if(speed <= 0) {
                    printf("Vehicle is already stopped.\n");
                }
                else {
                    speed -= 5;
                    printf("Speed decreased to %d mph.\n", speed);
                }
                break;
            case 3:
                if(speed == 0) {
                    printf("Vehicle is stopped, cannot turn.\n");
                }
                else {
                    direction -= 5;
                    printf("Vehicle turned left by %d degrees.\n", direction);
                }
                break;
            case 4:
                if(speed == 0) {
                    printf("Vehicle is stopped, cannot turn.\n");
                }
                else {
                    direction += 5;
                    printf("Vehicle turned right by %d degrees.\n", direction);
                }
                break;
            case 5:
                printf("Battery level is at %d percent.\n", battery_level);
                break;
            case 6:
                printf("Exiting Program...\n");
                return 0;
                break;
            default:
                printf("Invalid option, please try again.\n");
        }

        battery_level -= 2;

        if(battery_level <= 0) {
            printf("Battery level too low, vehicle shutting down.\n");
            return 0;
        }
    }
}