//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variable declaration and initialization
    int drone_x = 0, drone_y = 0, drone_alt = 0;
    char command = ' ';
    printf("Welcome to the C Drone Remote Control!\n");
    printf("Use the arrow keys to control the drone.\n");
    printf("Press 'q' to exit the program.\n");

    // Control loop
    while (command != 'q') {
        printf("Drone position: (%d, %d), altitude: %d\n", drone_x, drone_y, drone_alt);
        printf("Enter command: ");
        scanf(" %c", &command);

        // Handle commands
        switch (command) {
            case 'w':
                drone_y += 1;
                printf("Moving drone forward!\n");
                break;
            case 'a':
                drone_x -= 1;
                printf("Moving drone left!\n");
                break;
            case 's':
                drone_y -= 1;
                printf("Moving drone backward!\n");
                break;
            case 'd':
                drone_x += 1;
                printf("Moving drone right!\n");
                break;
            case 'u':
                drone_alt += 1;
                printf("Increasing altitude!\n");
                break;
            case 'j':
                drone_alt -= 1;
                printf("Decreasing altitude!\n");
                break;
            case 'q':
                printf("Exiting program!\n");
                break;
            default:
                printf("Unknown command!\n");
        }

        // Check drone position and altitude
        if (drone_x < 0 || drone_x > 100 ||
            drone_y < 0 || drone_y > 100 ||
            drone_alt < 0 || drone_alt > 50) {
            printf("Drone out of bounds!\n");
            exit(0);
        }
    }
    return 0;
}