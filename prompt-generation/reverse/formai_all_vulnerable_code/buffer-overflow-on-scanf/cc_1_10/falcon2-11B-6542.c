//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int drone_x = 0;
    int drone_y = 0;
    int drone_z = 0;
    int drone_speed = 0;
    int drone_direction = 0;

    // Get user input
    printf("Enter drone coordinates (x,y,z): ");
    scanf("%d%d%d", &drone_x, &drone_y, &drone_z);
    printf("Enter drone speed (0-10): ");
    scanf("%d", &drone_speed);
    printf("Enter drone direction (0-3): ");
    scanf("%d", &drone_direction);

    // Process user input
    if (drone_speed > 10 || drone_speed < 0) {
        printf("Invalid speed value. Speed should be between 0 and 10.\n");
    } else {
        drone_speed = drone_speed % 10;
    }

    if (drone_direction > 3 || drone_direction < 0) {
        printf("Invalid direction value. Direction should be between 0 and 3.\n");
    } else {
        drone_direction = drone_direction % 4;
    }

    // Update drone position based on user input
    switch (drone_direction) {
        case 0:
            drone_x += drone_speed;
            drone_y += drone_speed;
            drone_z += drone_speed;
            break;
        case 1:
            drone_x -= drone_speed;
            drone_y += drone_speed;
            drone_z += drone_speed;
            break;
        case 2:
            drone_x -= drone_speed;
            drone_y -= drone_speed;
            drone_z += drone_speed;
            break;
        case 3:
            drone_x += drone_speed;
            drone_y -= drone_speed;
            drone_z += drone_speed;
            break;
    }

    // Print drone position and speed
    printf("Drone Position: (%d, %d, %d)\n", drone_x, drone_y, drone_z);
    printf("Drone Speed: %d\n", drone_speed);

    // Clean up
    printf("Drone remote control program finished.\n");

    return 0;
}