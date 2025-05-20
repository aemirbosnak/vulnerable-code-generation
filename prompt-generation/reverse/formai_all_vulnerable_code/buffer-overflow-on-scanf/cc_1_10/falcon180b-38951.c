//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main() {

    double x, y, theta, v, w; // Initialize variables
    int choice; // Initialize choice variable

    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Please enter your choice:\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Left\n");
    printf("4. Right\n");
    printf("5. Stop\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Forward
            printf("Enter distance to move forward (in meters): ");
            scanf("%lf", &v);
            printf("Enter angular velocity (in radians/second): ");
            scanf("%lf", &w);
            x = v * cos(theta);
            y = v * sin(theta);
            theta += w;
            printf("Robot moved %.2lf meters forward at an angle of %.2lf radians.\n", v, w);
            break;
        case 2: // Backward
            printf("Enter distance to move backward (in meters): ");
            scanf("%lf", &v);
            printf("Enter angular velocity (in radians/second): ");
            scanf("%lf", &w);
            x = -v * cos(theta);
            y = -v * sin(theta);
            theta -= w;
            printf("Robot moved %.2lf meters backward at an angle of %.2lf radians.\n", v, w);
            break;
        case 3: // Left
            printf("Enter distance to move left (in meters): ");
            scanf("%lf", &v);
            printf("Enter angular velocity (in radians/second): ");
            scanf("%lf", &w);
            x = v * sin(theta);
            y = -v * cos(theta);
            theta += w;
            printf("Robot moved %.2lf meters left at an angle of %.2lf radians.\n", v, w);
            break;
        case 4: // Right
            printf("Enter distance to move right (in meters): ");
            scanf("%lf", &v);
            printf("Enter angular velocity (in radians/second): ");
            scanf("%lf", &w);
            x = -v * sin(theta);
            y = v * cos(theta);
            theta -= w;
            printf("Robot moved %.2lf meters right at an angle of %.2lf radians.\n", v, w);
            break;
        case 5: // Stop
            printf("Robot stopped.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}