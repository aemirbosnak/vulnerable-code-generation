//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double x, y, theta, v, w, dt;
    int choice;

    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Please enter the initial position (x y theta): ");
    scanf("%lf %lf %lf", &x, &y, &theta);

    printf("Please enter the initial velocity (v w): ");
    scanf("%lf %lf", &v, &w);

    printf("Please enter the time step (dt): ");
    scanf("%lf", &dt);

    while(1) {
        printf("\n");
        printf("1. Move Forward\n");
        printf("2. Turn Left\n");
        printf("3. Turn Right\n");
        printf("4. Stop\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                x += v*cos(theta)*dt;
                y += v*sin(theta)*dt;
                printf("Robot moved forward by %.2lf units.\n", v*dt);
                break;

            case 2:
                w -= 0.1;
                if(w < -PI/2)
                    w = -PI/2;
                theta += w*dt;
                printf("Robot turned left by %.2lf radians.\n", w*dt);
                break;

            case 3:
                w += 0.1;
                if(w > PI/2)
                    w = PI/2;
                theta -= w*dt;
                printf("Robot turned right by %.2lf radians.\n", w*dt);
                break;

            case 4:
                v = 0;
                w = 0;
                printf("Robot stopped.\n");
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

        printf("Current position: (%.2lf, %.2lf, %.2lf)\n", x, y, theta);
        printf("Current velocity: (%.2lf, %.2lf)\n", v, w);
        printf("\n");
    }

    return 0;
}