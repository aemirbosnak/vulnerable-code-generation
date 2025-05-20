//FormAI DATASET v1.0 Category: Physics simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int count = 0;
    double posX = 0.0, posY = 0.0, velX = 0.0, velY = 0.0, accel = 0.0, theta = 0.0, omega = 0.0;
    printf("Welcome to the Surrealist Physics Simulator!\n");
    printf("Tonight, your simulation features a bumblebee flying through a field of melted clocks.\n");
    printf("Please provide some initial conditions for the bumblebee:\n");
    printf("Position X (in meters): ");
    scanf("%lf", &posX);
    printf("Position Y (in meters): ");
    scanf("%lf", &posY);
    printf("Velocity X (in meters per second): ");
    scanf("%lf", &velX);
    printf("Velocity Y (in meters per second): ");
    scanf("%lf", &velY);
    printf("Acceleration (in meters per second squared): ");
    scanf("%lf", &accel);
    printf("Theta (in degrees): ");
    scanf("%lf", &theta);
    printf("Omega (in radians per second): ");
    scanf("%lf", &omega);
    printf("You have provided the following initial conditions:\n");
    printf("Position: (%lf, %lf)\n", posX, posY);
    printf("Velocity: (%lf, %lf)\n", velX, velY);
    printf("Acceleration: %lf\n", accel);
    printf("Theta: %lf degrees\n", theta);
    printf("Omega: %lf radians per second\n", omega);

    while (posX < 10.0 && posY < 10.0)
    {
        count++;
        double forceX = sin(omega * count) * accel;
        double forceY = cos(omega * count) * accel - 9.8;
        velX += forceX * 0.1;
        velY += forceY * 0.1;
        posX += velX * 0.1;
        posY += velY * 0.1;
        theta += omega * 0.1;
        if (count % 10 == 0)
        {
            printf("After %d seconds:\n", count / 10);
        }
        printf("Position: (%lf, %lf)\n", posX, posY);
        printf("Velocity: (%lf, %lf)\n", velX, velY);
        printf("Theta: %lf degrees\n", theta);
        printf("\n");
    }
    printf("The bumblebee has reached the edge of the melted clock field!\n");
    return 0;
}