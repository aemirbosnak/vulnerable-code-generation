//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Define the robot's initial position and orientation
double x = 0.0;
double y = 0.0;
double theta = 0.0;

// Define the robot's movement parameters
double v = 0.5; // linear velocity
double omega = 0.5; // angular velocity
double dt = 0.01; // time step

// Define the robot's movement functions
void move(double t) {
    x += v * cos(theta) * t; // update the robot's position
    y += v * sin(theta) * t;
    theta += omega * t; // update the robot's orientation
}

void turn(double t) {
    theta += omega * t; // update the robot's orientation
}

// Define the robot's sensor functions
double get_distance() {
    return sqrt(x*x + y*y); // calculate the distance from the robot's position to the origin
}

double get_bearing() {
    return atan2(y, x); // calculate the bearing from the robot's position to the origin
}

int main() {
    srand(time(NULL)); // seed the random number generator
    double t = 0.0; // initialize the time
    int choice; // initialize the user's choice

    do {
        printf("What would you like the robot to do?\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Get distance from origin\n");
        printf("5. Get bearing to origin\n");
        printf("6. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                t += dt; // move the robot forward for a time step
                move(t); // call the move function
                break;
            case 2:
                t += dt; // turn the robot left for a time step
                turn(t); // call the turn function
                break;
            case 3:
                t += dt; // turn the robot right for a time step
                turn(t); // call the turn function
                break;
            case 4:
                printf("Distance from origin: %f\n", get_distance()); // get the distance from the origin
                break;
            case 5:
                printf("Bearing to origin: %f\n", get_bearing()); // get the bearing to the origin
                break;
            case 6:
                printf("Exiting program.\n"); // exit the program
                break;
            default:
                printf("Invalid choice.\n"); // handle invalid choices
        }
    } while(choice!= 6);

    return 0;
}