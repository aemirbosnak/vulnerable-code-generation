//FormAI DATASET v1.0 Category: Physics simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define M 5.97e24 // mass of the Earth
#define R 6371000 // radius of the Earth

int main(){

    double h, v, a, t, r, x, y;
    double x0 = 0.0, y0 = R;
    double vx0, vy0, ax, ay, Fx, Fy;
    int i;

    // initial velocity
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &v);

    // initial angle
    printf("Enter initial angle (degrees): ");
    scanf("%lf", &a);

    // convert angle to radians
    a *= M_PI / 180.0;

    // initial height
    printf("Enter initial height (meters): ");
    scanf("%lf", &h);

    // initial position
    x = x0;
    y = y0 + h;

    // initial velocity components
    vx0 = v * cos(a);
    vy0 = v * sin(a);

    // initialize acceleration components to zero
    ax = 0.0;
    ay = 0.0;

    // loop until impact or escape
    for(i = 0; i < 50000; i++){

        // calculate distance from center of the Earth
        r = sqrt(x*x + y*y);

        // calculate x and y components of gravitational force
        Fx = -G * M * x / pow(r, 3);
        Fy = -G * M * y / pow(r, 3);

        // calculate x and y components of acceleration
        ax = Fx;
        ay = Fy;

        // update velocity components
        vx0 += ax * 0.1;
        vy0 += ay * 0.1;

        // update position components
        x += vx0 * 0.1;
        y += vy0 * 0.1;

        // check for impact or escape
        if(r <= R){
            printf("Impact at time %lf seconds.\n", t);
            break;
        }
        else if(r >= 42164000){
            printf("Escape at time %lf seconds.\n", t);
            break;
        }

        t += 0.1; // increment time

    }

    return 0;
}