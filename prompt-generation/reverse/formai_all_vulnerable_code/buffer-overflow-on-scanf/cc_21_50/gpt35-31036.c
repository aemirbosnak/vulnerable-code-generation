//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program simulates a puzzle in which a ball is released from a starting position and must reach a target position by navigating through a series of obstacles. 
   The ball is subject to gravitational forces and can be launched in any direction at a given speed. */

int main()
{
    // Set up variables for starting position, target position, and the angles at which the ball can be launched.
    int startX = 10;
    int startY = 10;
    int targetX = 50;
    int targetY = 50;
    double angle1 = 30.0 * (M_PI / 180.0);
    double angle2 = 45.0 * (M_PI / 180.0);
    double angle3 = 60.0 * (M_PI / 180.0);
    
    // Set up variables for the obstacles.
    int numObstacles = 3;
    int obstacleX[numObstacles];
    int obstacleY[numObstacles];
    int obstacleSize[numObstacles];
    
    // Set the obstacle positions and sizes.
    obstacleX[0] = 20;
    obstacleY[0] = 30;
    obstacleSize[0] = 10;
    
    obstacleX[1] = 40;
    obstacleY[1] = 20;
    obstacleSize[1] = 15;
    
    obstacleX[2] = 35;
    obstacleY[2] = 45;
    obstacleSize[2] = 8;
    
    // Set up variables for the ball's launch speed and angle.
    double launchSpeed;
    double launchAngle;
    
    // Prompt the user for the launch speed and angle.
    printf("Welcome to the ball puzzle!\n");
    printf("Please enter the launch speed (in meters per second): ");
    scanf("%lf", &launchSpeed);
    printf("Please enter the launch angle (in degrees): ");
    scanf("%lf", &launchAngle);
    launchAngle = launchAngle * (M_PI / 180.0); // Convert the angle from degrees to radians.
    
    // Set up variables for the ball's position and velocity.
    double x = startX;
    double y = startY;
    double vx = launchSpeed * cos(launchAngle);
    double vy = launchSpeed * sin(launchAngle);
    
    // Set up a variable for the time step.
    double dt = 0.01;
    
    // Set up variables for the gravitational force and initial velocity.
    double g = -9.8;
    double v0 = sqrt(pow(vx, 2) + pow(vy, 2));
    
    // Create a loop that updates the ball's position and velocity at each time step.
    while (1) {
        // Update the ball's position and velocity.
        x = x + vx * dt;
        y = y + vy * dt;
        vy = vy + g * dt;
    
        // Check if the ball has reached the target.
        if (sqrt(pow(x - targetX, 2) + pow(y - targetY, 2)) <= 0.5) {
            printf("Congratulations! You have reached the target!\n");
            break;
        }
    
        // Check if the ball has hit an obstacle.
        int hitObstacle = 0;
        for (int i = 0; i < numObstacles; i++) {
            if (sqrt(pow(x - obstacleX[i], 2) + pow(y - obstacleY[i], 2)) <= obstacleSize[i] / 2.0) {
                printf("Oh no! You hit an obstacle.\n");
                hitObstacle = 1;
                break;
            }
        }
        if (hitObstacle == 1) {
            break;
        }
    
        // Check if the ball has gone out of bounds.
        if (x < 0 || x > 100 || y < 0 || y > 100) {
            printf("Oh no! You went out of bounds.\n");
            break;
        }
    }
    
    // Prompt the user to try again with a different launch angle.
    printf("Would you like to try again with a different launch angle? (y/n): ");
    char input;
    scanf(" %c", &input);
    if (input == 'y') {
        printf("Please select a new launch angle from the following options:\n");
        printf("1. %d degrees\n", (int)(angle1 * (180 / M_PI)));
        printf("2. %d degrees\n", (int)(angle2 * (180 / M_PI)));
        printf("3. %d degrees\n", (int)(angle3 * (180 / M_PI)));
        printf("Enter 1, 2, or 3: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            launchAngle = angle1;
        } else if (choice == 2) {
            launchAngle = angle2;
        } else if (choice == 3) {
            launchAngle = angle3;
        } else {
            printf("Invalid choice. Exiting.\n");
            return 0;
        }
        x = startX;
        y = startY;
        vx = launchSpeed * cos(launchAngle);
        vy = launchSpeed * sin(launchAngle);
        printf("Launching with new angle of %d degrees.\n", (int)(launchAngle * (180 / M_PI)));
        for (int i = 0; i < 3; i++) {
            printf("Obstacle %d located at (%d, %d).\n", i+1, obstacleX[i], obstacleY[i]);
        }
        printf("Target located at (%d, %d).\n", targetX, targetY);
        printf("Good luck!\n");
        while (1) {
            x = x + vx * dt;
            y = y + vy * dt;
            vy = vy + g * dt;
            if (sqrt(pow(x - targetX, 2) + pow(y - targetY, 2)) <= 0.5) {
                printf("Congratulations! You have reached the target!\n");
                break;
            }
            int hitObstacle = 0;
            for (int i = 0; i < numObstacles; i++) {
                if (sqrt(pow(x - obstacleX[i], 2) + pow(y - obstacleY[i], 2)) <= obstacleSize[i] / 2.0) {
                    printf("Oh no! You hit an obstacle.\n");
                    hitObstacle = 1;
                    break;
                }
            }
            if (hitObstacle == 1) {
                break;
            }
            if (x < 0 || x > 100 || y < 0 || y > 100) {
                printf("Oh no! You went out of bounds.\n");
                break;
            }
        }
    }
    printf("Thank you for playing!\n");
    return 0;
}