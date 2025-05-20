//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double x, y, theta, v, omega;
    int choice;

    printf("Welcome to the Robot Movement Control program!\n");

    while(1) {
        printf("\n");
        printf("Please select an option:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter distance to move forward (in meters): ");
                scanf("%lf", &v);
                x += v * cos(theta);
                y += v * sin(theta);
                break;
            case 2:
                printf("Enter angle to turn left (in degrees): ");
                scanf("%lf", &omega);
                theta -= omega * PI / 180.0;
                break;
            case 3:
                printf("Enter angle to turn right (in degrees): ");
                scanf("%lf", &omega);
                theta += omega * PI / 180.0;
                break;
            case 4:
                printf("Robot stopped.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option selected.\n");
        }
    }

    return 0;
}