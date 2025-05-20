//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main()
{
    // Constants
    const double PI = 3.141592653589793238;
    const double g = 9.81; // Acceleration due to gravity in m/s^2
    const double radius = 0.05; // Radius of the ball in meters
    const double mass = 0.1; // Mass of the ball in kg
    
    // Variables
    double angle, velocity, height, time, x, y, vx, vy, ax, ay;
    
    // User input
    printf("Enter the initial angle in degrees: ");
    scanf("%lf", &angle);
    printf("Enter the initial velocity in m/s: ");
    scanf("%lf", &velocity);
    printf("Enter the initial height in meters: ");
    scanf("%lf", &height);
    
    // Convert angle to radians
    angle = angle * PI / 180;
    
    // Initial conditions
    time = 0;
    x = 0;
    y = height;
    vx = velocity * cos(angle);
    vy = velocity * sin(angle);
    ax = 0;
    ay = -g;
    
    // Simulation loop
    while (y >= 0)
    {
        // Update time
        time = time + 0.01;
        
        // Update position
        x = x + vx * 0.01;
        y = y + vy * 0.01 + 0.5 * ay * pow(0.01, 2);
        
        // Update velocity
        vx = vx + ax * 0.01;
        vy = vy + ay * 0.01;
        
        // Update acceleration
        ax = -g * sin(angle);
        ay = -g * cos(angle);
        
        // Check for collision with ground
        if (y < 0)
        {
            // Calculate final position and velocity
            double t = -vy / ay;
            x = x + vx * t;
            y = 0;
            vy = -vy * 0.8;
            vx = vx * 0.8;
            time = time + t;
        }
        
        // Output position
        printf("Time: %lf s, Position: (%lf, %lf)\n", time, x, y);
    }
    
    return 0;
}