//FormAI DATASET v1.0 Category: Physics simulation ; Style: real-life
#include <stdio.h>
#include <math.h>

int main()
{
    float mass, velocity, angle, height, distance, time, force, acceleration;
    const float GRAVITY = 9.81;

    printf("Enter the mass of the bullet in grams: ");
    scanf("%f", &mass);

    printf("Enter the initial velocity of the bullet in meters per second: ");
    scanf("%f", &velocity);

    printf("Enter the angle of inclination in degrees: ");
    scanf("%f", &angle);

    printf("Enter the height of the shooting point in meters: ");
    scanf("%f", &height);

    // Calculation of distance
    angle = angle * (M_PI / 180);
    distance = ((velocity * velocity) * sin(2 * angle)) / GRAVITY;

    // Calculation of time
    time = (2 * velocity * sin(angle)) / GRAVITY;

    // Calculation of force
    force = (mass * pow(velocity, 2)) / distance;

    // Calculation of the horizontal and vertical components of velocity
    float v_horizontal = velocity * cos(angle);
    float v_vertical = velocity * sin(angle);

    // Calculation of the height of the bullet at any time t
    printf("Enter the time at which you want to find the height: ");
    scanf("%f", &time);

    float height_at_time = height + (v_vertical * time) - (0.5 * GRAVITY * pow(time, 2));
    printf("The height of the bullet at %.2f seconds is: %.2f meters\n", time, height_at_time);

    // Calculation of acceleration of bullet
    acceleration = force / mass;

    printf("\n");
    printf("Distance travelled by bullet: %.2f meters\n", distance);
    printf("Time taken by bullet to reach the ground: %.2f seconds\n", time);
    printf("Force experienced by bullet: %.2f N\n", force);
    printf("Acceleration of bullet: %.2f m/s^2\n", acceleration);
    printf("Horizontal velocity of bullet: %.2f m/s\n", v_horizontal);
    printf("Vertical velocity of bullet: %.2f m/s\n", v_vertical);

    return 0;
}