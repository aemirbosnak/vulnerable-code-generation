//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: configurable
#include <stdio.h>

// Define drone command codes for easy reference
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4
#define MOVE_UP 5
#define MOVE_DOWN 6
#define HOVER 7

int main() {
    int command;
    printf("Welcome to your drone remote control program!\n\n");

    // Continuously prompt user for commands until they decide to exit
    while (1) {
        printf("Please enter a command code:\n\n");
        printf("1 - Move Forward\n");
        printf("2 - Move Backward\n");
        printf("3 - Move Left\n");
        printf("4 - Move Right\n");
        printf("5 - Move Up\n");
        printf("6 - Move Down\n");
        printf("7 - Hover\n");
        printf("Enter 0 to exit.\n\n");

        scanf("%d",&command);

        switch (command) {
            case MOVE_FORWARD:
                printf("Moving drone forward.\n\n");
                break;
            case MOVE_BACKWARD:
                printf("Moving drone backward.\n\n");
                break;
            case MOVE_LEFT:
                printf("Moving drone left.\n\n");
                break;
            case MOVE_RIGHT:
                printf("Moving drone right.\n\n");
                break;
            case MOVE_UP:
                printf("Moving drone up.\n\n");
                break;
            case MOVE_DOWN:
                printf("Moving drone down.\n\n");
                break;
            case HOVER:
                printf("Hovering drone in current position.\n\n");
                break;
            case 0:
                printf("Exiting drone remote control program.\n\n");
                return 0;
                break;
            default:
                printf("Invalid command code entered. Please try again.\n\n");
                break;
        }
    }
    return 0;   
}