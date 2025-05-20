//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
    double x, y, theta, v, omega;
    int choice;
    char input[10];

    printf("Enter the initial position of the robot (x y): ");
    scanf("%lf %lf", &x, &y);

    printf("Enter the initial orientation of the robot (theta): ");
    scanf("%lf", &theta);

    printf("Enter the initial velocity of the robot (v): ");
    scanf("%lf", &v);

    printf("Enter the initial angular velocity of the robot (omega): ");
    scanf("%lf", &omega);

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        printf("5. Exit\n");

        scanf("%s", input);

        switch (input[0]) {
        case '1': // Move forward
            printf("Enter the distance to move forward (in meters): ");
            scanf("%lf", &v);
            x += v * cos(theta);
            y += v * sin(theta);
            break;
        case '2': // Turn left
            omega -= 0.1;
            break;
        case '3': // Turn right
            omega += 0.1;
            break;
        case '4': // Stop
            v = 0;
            omega = 0;
            break;
        case '5': // Exit
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }

        printf("Current position: (%lf, %lf)\n", x, y);
        printf("Current orientation: %lf\n", theta);
        printf("Current velocity: %lf\n", v);
        printf("Current angular velocity: %lf\n", omega);
    }

    return 0;
}