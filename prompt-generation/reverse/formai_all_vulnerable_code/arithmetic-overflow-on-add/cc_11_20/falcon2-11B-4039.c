//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
    // Initialize variables
    int x, y, theta;
    double x_speed, y_speed, theta_speed;
    int MAX_X = 10;
    int MAX_Y = 10;
    int MAX_THETA = 360;
    int MIN_X = 0;
    int MIN_Y = 0;
    int MIN_THETA = 0;
    
    // Get user input for starting position and speed
    printf("Enter starting position (x, y): ");
    scanf("%d%d", &x, &y);
    printf("Enter starting speed (x, y, theta): ");
    scanf("%lf%lf%lf", &x_speed, &y_speed, &theta_speed);
    
    // Initialize robot's position and speed
    x = x - x_speed;
    y = y - y_speed;
    theta = theta_speed;
    
    // Loop to simulate robot movement
    while (x >= MAX_X || x <= MIN_X || y >= MAX_Y || y <= MIN_Y || theta >= MAX_THETA || theta <= MIN_THETA) {
        // Update position based on speed and direction
        x += x_speed;
        y += y_speed;
        theta += theta_speed;
        
        // Adjust speed and direction based on position limits
        if (x >= MAX_X) {
            x -= MAX_X;
            x_speed *= -1;
        }
        if (x <= MIN_X) {
            x += MIN_X;
            x_speed *= -1;
        }
        if (y >= MAX_Y) {
            y -= MAX_Y;
            y_speed *= -1;
        }
        if (y <= MIN_Y) {
            y += MIN_Y;
            y_speed *= -1;
        }
        if (theta >= MAX_THETA) {
            theta -= MAX_THETA;
            theta_speed *= -1;
        }
        if (theta <= MIN_THETA) {
            theta += MIN_THETA;
            theta_speed *= -1;
        }
    }
    
    // Output final position and speed
    printf("Final position: (%d, %d)\n", x, y);
    printf("Final speed: (%lf, %lf, %lf)\n", x_speed, y_speed, theta_speed);
    
    return 0;
}