//FormAI DATASET v1.0 Category: Physics simulation ; Style: paranoid
#include <stdio.h>
#include <math.h>

#define G 9.81 //Gravitational constant

int main()
{
    double vo, theta, h, t; //Initial velocity, launch angle, height, time
    double vx, vy, x, y; //Velocity components, position components
    double range, height_max, time_max, height_fall; //Projectile characteristics

    //Input values
    printf("Enter the initial velocity (m/s) : ");
    scanf("%lf", &vo);
    printf("Enter the launch angle (degrees) : ");
    scanf("%lf", &theta);
    printf("Enter the height (m) : ");
    scanf("%lf", &h);
    printf("Enter the time interval (s) : ");
    scanf("%lf", &t);

    //Conversion of degrees to radians
    theta = theta * M_PI / 180.0;

    //Calculation of velocity components
    vx = vo * cos(theta);
    vy = vo * sin(theta);

    //Initial position
    x = 0.0;
    y = h;

    //Simulation loop
    while (y >= 0.0)
    {
        x = x + vx * t;
        y = y + vy * t - 0.5 * G * t * t;
        vy = vy - G * t;

        //Update projectile characteristics
        if (y > height_max)
            height_max = y;
        if (x > range)
            range = x;
    }

    //Calculations after impact
    time_max = vo * sin(theta) / G;
    height_fall = 0.5 * G * time_max * time_max;

    //Output values
    printf("\n***Projectile Characteristics***\n");
    printf("Range : %.2f m \n", range);
    printf("Max Height : %.2f m \n", height_max);
    printf("Time of Flight : %.2f s \n", time_max * 2.0);
    printf("Time to Max Height : %.2f s \n", time_max);
    printf("Max Height Above Starting Point : %.2f m \n", height_max - h);
    printf("Height Fallen From Max Height : %.2f m \n", height_fall);
    printf("Impact Position : (%.2f, %.2f) m \n", x, 0.0);

    return 0;
}