//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define drone parameters
#define DRONE_SPEED 100
#define DRONE_RANGE 1000
#define DRONE_HEIGHT 500

// Define remote control buttons
#define BUTTON_UP 'w'
#define BUTTON_DOWN's'
#define BUTTON_LEFT 'a'
#define BUTTON_RIGHT 'd'
#define BUTTON_TAKEOFF 't'
#define BUTTON_LAND 'l'

int main() {
    // Initialize drone position
    double drone_x = 0;
    double drone_y = 0;
    double drone_z = 0;

    // Initialize remote control buttons
    char remote_button;

    // Seed random number generator
    srand(time(NULL));

    // Main loop
    while (1) {
        // Print drone status
        printf("Drone status:\n");
        printf("X: %.2f\n", drone_x);
        printf("Y: %.2f\n", drone_y);
        printf("Z: %.2f\n", drone_z);
        printf("\n");

        // Get remote control button
        scanf("%c", &remote_button);

        // Process remote control button
        switch (remote_button) {
            case BUTTON_UP:
                drone_z += DRONE_SPEED;
                break;
            case BUTTON_DOWN:
                drone_z -= DRONE_SPEED;
                break;
            case BUTTON_LEFT:
                drone_x -= DRONE_SPEED;
                break;
            case BUTTON_RIGHT:
                drone_x += DRONE_SPEED;
                break;
            case BUTTON_TAKEOFF:
                drone_z = 0;
                break;
            case BUTTON_LAND:
                drone_z = 0;
                break;
            default:
                printf("Invalid button!\n");
        }

        // Check drone boundaries
        if (drone_z > DRONE_HEIGHT) {
            printf("Drone out of range!\n");
            break;
        }
        if (drone_x > DRONE_RANGE || drone_x < -DRONE_RANGE ||
            drone_y > DRONE_RANGE || drone_y < -DRONE_RANGE) {
            printf("Drone out of range!\n");
            break;
        }
    }

    return 0;
}