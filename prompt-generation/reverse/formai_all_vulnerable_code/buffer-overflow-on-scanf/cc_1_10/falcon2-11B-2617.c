//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0;
    int y = 0;
    int photoCount = 0;
    int photos[5];

    // Initialize variables
    x = 0;
    y = 0;
    photoCount = 0;

    // Main loop to control drone
    while (1) {
        // Read user input
        printf("Enter direction (N, E, S, W): ");
        char direction;
        scanf(" %c", &direction);

        // Update drone position
        switch (direction) {
            case 'N':
                y += 1;
                break;
            case 'E':
                x += 1;
                break;
            case 'S':
                y -= 1;
                break;
            case 'W':
                x -= 1;
                break;
            default:
                printf("Invalid direction\n");
        }

        // Check for photo count
        if (photoCount == 5) {
            // Take photo
            printf("Taking photo %d\n", photoCount);
            // Save photo to array
            photos[photoCount] = (int)getchar();
            photoCount++;
        }

        // Increment photo count
        photoCount++;
    }

    return 0;
}