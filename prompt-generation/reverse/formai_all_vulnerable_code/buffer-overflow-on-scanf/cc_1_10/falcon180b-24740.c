//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

int main() {
    double x = 0.0, y = 0.0, theta = 0.0, v = 0.0, w = 0.0;
    int choice, i;

    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Please enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Stop\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the distance to move forward (in meters): ");
            scanf("%lf", &v);
            while (v > 0) {
                x += v * cos(theta);
                y += v * sin(theta);
                printf("%.2lf meters moved.\n", v);
                v -= 0.1;
                usleep(100000); // 100ms delay
            }
            printf("Robot has stopped.\n");
            break;
        case 2:
            printf("Enter the angle to turn left (in degrees): ");
            scanf("%lf", &theta);
            while (theta > 0) {
                x += v * cos(theta);
                y += v * sin(theta);
                printf("%.2lf degrees turned.\n", theta);
                theta -= 1;
                usleep(100000); // 100ms delay
            }
            printf("Robot has stopped.\n");
            break;
        case 3:
            printf("Enter the angle to turn right (in degrees): ");
            scanf("%lf", &theta);
            while (theta > 0) {
                x += v * cos(theta);
                y += v * sin(theta);
                printf("%.2lf degrees turned.\n", theta);
                theta -= 1;
                usleep(100000); // 100ms delay
            }
            printf("Robot has stopped.\n");
            break;
        case 4:
            printf("Robot has stopped.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}