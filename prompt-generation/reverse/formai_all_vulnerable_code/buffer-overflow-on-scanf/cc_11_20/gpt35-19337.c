//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 5

int main() {
    int drone_num = 1;
    int command;

    printf("Welcome to Genius C Drone Remote Control!\n");
    printf("There are currently %d drones available.\n\n", MAX_DRONES);

    while(1) {
        printf("Please select a drone (1 - %d) or 0 to exit:", MAX_DRONES);
        scanf("%d", &drone_num);

        if(drone_num == 0) {
            printf("Exiting program...");
            exit(0);
        } else if(drone_num < 1 || drone_num > MAX_DRONES) {
            printf("Invalid drone number! Please choose a drone (1 - %d).\n\n", MAX_DRONES);
            continue;
        }

        printf("\nYou are controlling drone %d.\n", drone_num);
        printf("Available commands: \n");
        printf("1. Take off\n");
        printf("2. Land\n");
        printf("3. Move up\n");
        printf("4. Move down\n");
        printf("5. Move left\n");
        printf("6. Move right\n");
        printf("7. Rotate left\n");
        printf("8. Rotate right\n");
        printf("9. Return to default position\n");
        printf("0. Change drone\n\n");

        while(1) {
            printf("Please enter a command (1 - 9) or 0 to change drone:");
            scanf("%d", &command);

            switch(command) {
                case 0:
                    goto change_drone;
                    break;
                case 1:
                    printf("Drone %d is taking off...\n", drone_num);
                    break;
                case 2:
                    printf("Drone %d is landing...\n", drone_num);
                    break;
                case 3:
                    printf("Drone %d is moving up...\n", drone_num);
                    break;
                case 4:
                    printf("Drone %d is moving down...\n", drone_num);
                    break;
                case 5:
                    printf("Drone %d is moving left...\n", drone_num);
                    break;
                case 6:
                    printf("Drone %d is moving right...\n", drone_num);
                    break;
                case 7:
                    printf("Drone %d is rotating left...\n", drone_num);
                    break;
                case 8:
                    printf("Drone %d is rotating right...\n", drone_num);
                    break;
                case 9:
                    printf("Drone %d is returning to default position...\n", drone_num);
                    break;
                default:
                    printf("Invalid command! Please enter a valid command.\n");
                    break;
            }
        }

        change_drone: printf("\n");
    }

    return 0;
}