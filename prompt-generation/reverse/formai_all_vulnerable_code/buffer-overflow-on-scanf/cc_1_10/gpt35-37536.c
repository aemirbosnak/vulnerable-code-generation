//FormAI DATASET v1.0 Category: Physics simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

//function to calculate velocity
float velocity(float theta, float angle)
{
    float velocity_x, velocity_y;
    float speed;

    //calculate x-component of velocity
    velocity_x = angle * cos(theta * PI / 180);

    //calculate y-component of velocity
    velocity_y = angle * sin(theta * PI / 180);

    //calculate speed
    speed = sqrt(pow(velocity_x, 2) + pow(velocity_y, 2));

    return speed;
}

int main()
{
    float angle, theta, speed;
    float TIME_STEP = 0.1;
    float x = 0, y = 0;
    float x_vel, y_vel;

    printf("Welcome to the Surrealist Physics Simulation!\n\n");

    printf("Please enter the angle of launch in degrees: ");
    scanf("%f", &angle);

    printf("Please enter the velocity of launch in meters per second: ");
    scanf("%f", &theta);

    //convert angle to radians
    theta = theta * PI / 180;

    //calculate velocity
    speed = velocity(angle, theta);

    printf("\nLaunching!\n\n");

    while(y >= 0)
    {
        //calculate x and y coordinates
        x_vel = speed * cos(theta);
        y_vel = speed * sin(theta);

        x += x_vel * TIME_STEP;
        y += y_vel * TIME_STEP - 0.5 * 9.8 * pow(TIME_STEP, 2);

        //print the current coordinates
        printf("x = %f, y = %f\n", x, y);

        //change direction randomly every 10 seconds
        if(fmod(x, 10) == 0)
        {
            theta += ((float) rand() / RAND_MAX) - 0.5;
        }
    }

    printf("\nLanded on a giant mushroom! Congratulations!\n");

    return 0;
}