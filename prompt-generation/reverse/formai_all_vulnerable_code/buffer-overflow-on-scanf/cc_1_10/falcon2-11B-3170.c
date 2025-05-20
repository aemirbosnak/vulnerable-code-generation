//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize robot variables
    int x = 0;
    int y = 0;
    int theta = 0;

    // Read user input to set robot position
    printf("Enter x coordinate: ");
    scanf("%d", &x);
    printf("Enter y coordinate: ");
    scanf("%d", &y);
    printf("Enter theta angle: ");
    scanf("%d", &theta);

    // Move robot based on user input
    printf("Moving robot...\n");
    if (x < 0) {
        x = 0;
    }
    else if (x > 100) {
        x = 100;
    }
    else {
        x++;
    }
    if (y < 0) {
        y = 0;
    }
    else if (y > 100) {
        y = 100;
    }
    else {
        y++;
    }
    if (theta < 0) {
        theta = 0;
    }
    else if (theta > 360) {
        theta = 360;
    }
    else {
        theta++;
    }

    // Output robot's new position
    printf("Robot position: (%d, %d, %d)\n", x, y, theta);

    // Exit program
    return 0;
}