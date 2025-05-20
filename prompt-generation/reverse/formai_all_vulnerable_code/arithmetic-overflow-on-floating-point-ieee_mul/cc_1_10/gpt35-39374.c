//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define G   6.6726e-11   // gravitational constant G
#define dt  0.02         // time step
#define N   100          // number of steps
#define M1   2.0e30      // mass of planet 1 (in kg)
#define M2   6.0e24      // mass of planet 2 (in kg)
#define r0   1.5e11      // initial planet separation (in m)
#define V0   3.0e4       // initial velocity of planet 2 (in m/s)
#define R    6.38e6      // radius of planet 2 (in m)
#define XMAX 2.0e11      // maximum x-coordinate for plotting
#define YMAX 2.0e11      // maximum y-coordinate for plotting

int main()
{
    double x1,y1,x2,y2,vx1,vy1,vx2,vy2,ax1,ay1,ax2,ay2,f1,f2,r;
    double t;
    int i;

    x1 = 0.0;             // initial coordinates of planet 1
    y1 = 0.0;
    x2 = r0;              // initial coordinates of planet 2
    y2 = 0.0;
    vx2 = 0.0;            // initial velocity of planet 2
    vy2 = V0;

    for(i=0; i<=N; i++)
    {
        t = i*dt;         // current time
        r = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));  // distance between planets
        f1 = G*M1*M2/(r*r);   // force on planet 1
        f2 = -f1;             // force on planet 2
        ax1 = f1/M1;          // acceleration of planet 1
        ay1 = f1/M1;
        ax2 = f2/M2;          // acceleration of planet 2
        ay2 = f2/M2;

        vx1 += ax1*dt;       // update velocity of planet 1
        vy1 += ay1*dt;
        vx2 += ax2*dt;       // update velocity of planet 2
        vy2 += ay2*dt;

        x1 += vx1*dt;        // update coordinates of planet 1
        y1 += vy1*dt;
        x2 += vx2*dt;        // update coordinates of planet 2
        y2 += vy2*dt;

        if(y2<=R && vy2<0)   // surface impact check of planet 2
        {
            printf("Planet 2 collided with the surface at x = %lf m \n",x2-R);
            break;
        }

        if(x2>=XMAX || y2>=YMAX || x2<=0 || y2<=0)  // out-of-bound check of planet 2
        {
            printf("Planet 2 went out of bounds at time t = %lf s \n",t);
            break;
        }
    }

    return 0;
}