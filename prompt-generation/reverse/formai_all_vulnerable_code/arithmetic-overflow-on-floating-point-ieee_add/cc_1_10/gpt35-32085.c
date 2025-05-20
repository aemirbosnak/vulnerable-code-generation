//FormAI DATASET v1.0 Category: Physics simulation ; Style: introspective
/* This is a simulation program of a mass-spring system with damping.
   The objective is to calculate the motion of a body with mass 'm' attached to
   a spring with spring constant 'k' and damping coefficient 'c'.
   In this simulation, a force is applied to the mass and the position, velocity 
   and acceleration of the mass is calculated at each time step. */

#include<stdio.h>
#include<math.h>

#define pi 3.14159265358979323846

int main()
{
    double t,dt;                // time and time increment
    double m,k,c;               // mass, spring constant and damping coefficient
    double x,v,a;               // position, velocity and acceleration
    double f;                   // applied force
    double period;              // period of oscillation
    double omega;               // angular frequency
    double amplitude;           // displacement amplitude

    // Taking input values from user
    printf("Enter mass of the body(in kg): ");
    scanf("%lf",&m);

    printf("Enter the spring constant(in N/m): ");
    scanf("%lf",&k);

    printf("Enter the damping coefficient(in Ns/m): ");
    scanf("%lf",&c);

    printf("Enter the applied force(in N): ");
    scanf("%lf",&f);

    // Initial conditions
    x=1.0;                      // Initial displacement
    v=0.0;                      // Initial velocity
    a=0.0;                      // Initial acceleration

    // Calculation of period and amplitude
    period=2*pi*sqrt(m/k);      
    amplitude=f/k;

    // Calculation of time step
    dt=period/200.0;

    // Calculation of angular frequency
    omega=sqrt(k/m);

    // Simulation loop
    for(t=0;t<=10*period;t+=dt)
    {
        // Calculation of acceleration using Newton's Second Law
        a=(-k*x-c*v+f)/m;

        // Calculation of velocity using Euler method
        v+=a*dt;

        // Calculation of position using Euler method
        x+=v*dt;

        // Printing the data at each time step
        printf("%.2lf\t%.2lf\t%.2lf\n",t,x,v);
    }

    return 0;
}