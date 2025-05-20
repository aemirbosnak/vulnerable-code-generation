//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define MAX_POINTS 10 // maximum number of celestial bodies

struct Point {
    double x, y, mass;
    double vx, vy;
};

typedef struct Point Point;

// function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

// function to calculate the gravitational force between two points
double force(double m1, double m2, double dist) {
    return G * ((m1 * m2) / pow(dist, 2));
}

int main() {
    Point points[MAX_POINTS];
    int n; // number of celestial bodies
    printf("Enter number of celestial bodies (max %d): ", MAX_POINTS);
    scanf("%d", &n);

    // prompt user to enter the coordinates and mass of each celestial body
    for (int i=0; i<n; i++) {
        printf("\nEnter coordinates and mass of celestial body %d:\n", i+1);
        printf("x = ");
        scanf("%lf", &points[i].x);
        printf("y = ");
        scanf("%lf", &points[i].y);
        printf("mass = ");
        scanf("%lf", &points[i].mass);

        // set initial velocity to zero
        points[i].vx = 0.0;
        points[i].vy = 0.0;
    }

    // prompt user to enter the simulation time step
    double dt;
    printf("\nEnter time step duration in seconds: ");
    scanf("%lf", &dt);

    // prompt user to enter the total simulation time
    double total_time;
    printf("\nEnter total simulation time in seconds: ");
    scanf("%lf", &total_time);

    // main simulation loop
    for (double t=0.0; t<total_time; t+=dt) {
        // loop through each celestial body to calculate net force on it
        for (int i=0; i<n; i++) {
            double fx = 0.0;
            double fy = 0.0;

            // loop through every other celestial body to calculate the force on i
            for (int j=0; j<n; j++) {
                if (i != j) {
                    double dist = distance(points[i].x, points[i].y, points[j].x, points[j].y);
                    double f = force(points[i].mass, points[j].mass, dist);

                    // calculate x and y components of the force
                    fx += f * (points[j].x - points[i].x) / dist;
                    fy += f * (points[j].y - points[i].y) / dist;
                }
            }

            // calculate the acceleration of i
            double ax = fx / points[i].mass;
            double ay = fy / points[i].mass;

            // update the velocity of i
            points[i].vx += ax * dt;
            points[i].vy += ay * dt;

            // update the position of i
            points[i].x += points[i].vx * dt;
            points[i].y += points[i].vy * dt;
        }

        // print the current positions of each celestial body
        printf("\nTime: %f seconds\n", t);
        for (int i=0; i<n; i++) {
            printf("Celestial body %d position: (%f, %f)\n", i+1, points[i].x, points[i].y);
        }
    }

    return 0;
}