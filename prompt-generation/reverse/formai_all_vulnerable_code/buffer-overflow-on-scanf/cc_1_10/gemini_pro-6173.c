//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the mass, gravity, and time step
#define MASS 1.0
#define GRAVITY 9.81
#define DT 0.01

// Define the initial position and velocity
#define X0 0.0
#define Y0 0.0
#define V0X 0.0
#define V0Y 0.0

// Define the number of time steps
#define NSTEPS 1000

// Declare the global variables
double x, y, vX, vY, t;

// Main function
int main() {
    
    printf("Welcome to the Physics Simulation!\n\n");
    printf("Let's define the simulation parameters: \n");
    
    // Get the mass from the user
    double mass;
    printf("What is the mass of the object (in kilograms)? ");
    scanf("%lf", &mass);
    
    // Get the gravitational acceleration from the user
    double gravity;
    printf("What is the gravitational acceleration (in meters per second squared)? ");
    scanf("%lf", &gravity);
    
    // Get the time step from the user
    double dt;
    printf("What is the time step (in seconds)? ");
    scanf("%lf", &dt);
    
    // Get the initial position from the user
    double x0;
    printf("What is the initial x-position (in meters)? ");
    scanf("%lf", &x0);
    
    double y0;
    printf("What is the initial y-position (in meters)? ");
    scanf("%lf", &y0);
    
    // Get the initial velocity from the user
    double v0x;
    printf("What is the initial x-velocity (in meters per second)? ");
    scanf("%lf", &v0x);
    
    double v0y;
    printf("What is the initial y-velocity (in meters per second)? ");
    scanf("%lf", &v0y);
    
    // Get the number of time steps from the user
    int nsteps;
    printf("How many time steps do you want to simulate? ");
    scanf("%d", &nsteps);
    
    
    // Initialize the global variables
    x = x0;
    y = y0;
    vX = v0x;
    vY = v0y;
    t = 0.0;

    FILE * fp = fopen ("simulation_data.txt", "w");

    fprintf (fp, "t,x,y,vX,vY\n");
    
    // Simulate the motion of the object
    for (int i = 0; i < nsteps; i++) {

        // Calculate the acceleration due to gravity
        double ax = 0.0;
        double ay = -gravity;

        // Update the velocity
        vX += ax * dt;
        vY += ay * dt;

        // Update the position
        x += vX * dt;
        y += vY * dt;

        // Update the time
        t += dt;
        
        fprintf (fp, "%f,%f,%f,%f,%f\n", t,x,y,vX,vY);
    }
    
    fclose (fp);
    
    // Print the final position and velocity
    printf("\nThe final position of the object is (x, y) = (%f, %f) meters.\n", x, y);
    printf("The final velocity of the object is (vX, vY) = (%f, %f) meters per second.\n", vX, vY);

    return 0;
}