//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Alan Touring
#include <stdio.h>

// define drone commands
#define TAKE_OFF 1
#define LAND 2
#define HOVER 3
#define MOVE_FORWARD 4
#define MOVE_BACKWARD 5
#define MOVE_LEFT 6
#define MOVE_RIGHT 7

// define drone states
#define ON_GROUND 0
#define IN_FLIGHT 1
#define HOVERING 2

int main() {
    int state = ON_GROUND;  // drone starts on the ground

    while (1) {  // loop indefinitely
        printf("Enter drone command: ");
        int command;
        scanf("%d", &command);

        switch (command) {
            case TAKE_OFF:
                if (state == ON_GROUND) {  // only take off if on the ground
                    printf("Taking off...\n");
                    state = IN_FLIGHT;
                } else {
                    printf("Error: Cannot take off while in flight or hovering\n");
                }
                break;

            case LAND:
                if (state == IN_FLIGHT || state == HOVERING) {  // only land if in flight or hovering
                    printf("Landing...\n");
                    state = ON_GROUND;
                } else {
                    printf("Error: Cannot land while on the ground\n");
                }
                break;

            case HOVER:
                if (state == IN_FLIGHT) {  // only hover if in flight
                    printf("Hovering...\n");
                    state = HOVERING;
                } else {
                    printf("Error: Cannot hover while on the ground or already hovering\n");
                }
                break;

            case MOVE_FORWARD:
                if (state == IN_FLIGHT || state == HOVERING) {  // only move forward if in flight or hovering
                    printf("Moving forward...\n");
                } else {
                    printf("Error: Cannot move forward while on the ground\n");
                }
                break;

            case MOVE_BACKWARD:
                if (state == IN_FLIGHT || state == HOVERING) {  // only move backward if in flight or hovering
                    printf("Moving backward...\n");
                } else {
                    printf("Error: Cannot move backward while on the ground\n");
                }
                break;

            case MOVE_LEFT:
                if (state == IN_FLIGHT || state == HOVERING) {  // only move left if in flight or hovering
                    printf("Moving left...\n");
                } else {
                    printf("Error: Cannot move left while on the ground\n");
                }
                break;

            case MOVE_RIGHT:
                if (state == IN_FLIGHT || state == HOVERING) {  // only move right if in flight or hovering
                    printf("Moving right...\n");
                } else {
                    printf("Error: Cannot move right while on the ground\n");
                }
                break;

            default:
                printf("Error: Invalid command\n");
                break;
        }
    }

    return 0;
}