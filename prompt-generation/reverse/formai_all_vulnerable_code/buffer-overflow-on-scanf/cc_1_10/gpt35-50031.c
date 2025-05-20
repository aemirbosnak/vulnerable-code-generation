//FormAI DATASET v1.0 Category: Physics simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the exciting world of physics simulations!\n");
    printf("In this program, we will be simulating the trajectory of a projectile.\n");
    printf("First, we need to gather some initial information from the user.\n");

    float angle, velocity, distance, g = 9.8;
    printf("What is the launch angle in degrees?\n");
    scanf("%f", &angle);

    printf("What is the launch velocity in m/s?\n");
    scanf("%f", &velocity);

    printf("What is the distance to the target in meters?\n");
    scanf("%f", &distance);

    // Convert angle to radians
    float radians = angle * (M_PI / 180.0);

    // Determine the initial horizontal and vertical velocities
    float v_x = velocity * cos(radians);
    float v_y = velocity * sin(radians);

    // Calculate the time of flight
    float t = (2 * v_y) / g;

    // Calculate the range of the projectile
    float r = v_x * t;

    printf("Calculating trajectory...\n\n");

    // Loop through each quarter second of flight
    for (float i = 0; i <= t; i += 0.25)
    {
        float x = v_x * i;
        float y = (v_y * i) - (0.5 * g * pow(i, 2));

        // Check if the projectile has hit the target
        if (x >= distance)
        {
            printf("Target Hit! Distance: %.2f meters, Time: %.2f seconds\n", x, i);
            return 0;
        }

        // Print the position and time of the projectile
        printf("Time: %.2f seconds, Position: %.2f meters (x), %.2f meters (y)\n", i, x, y);
    }

    printf("The projectile fell short of the target. Distance: %.2f meters, Time: %.2f seconds\n", r, t);
    return 0;
}