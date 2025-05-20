//FormAI DATASET v1.0 Category: Physics simulation ; Style: visionary
#include<stdio.h>
#include<math.h>

// Constants
#define G 6.674e-11 // Gravitational constant
#define T 3600 // Simulation time
#define delta_t 60 // Time step
#define n_bodies 3 // Number of bodies

// Structure for storing body information
typedef struct{
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
} Body;

// Function to calculate distance between two bodies
double distance(Body b1, Body b2){
    double dist = sqrt(pow((b2.position[0] - b1.position[0]),2) + pow((b2.position[1] - b1.position[1]),2) + pow((b2.position[2] - b1.position[2]),2));
    return dist;
}

int main(){

    // Define the initial state of the bodies
    Body bodies[n_bodies] = {
        {5.97e24, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, // Earth
        {7.34e22, {384400000, 0, 0}, {0, 1022, 0}, {0, 0, 0}}, // Moon
        {1000, {-10000000, 0, 0}, {0, -20, 0}, {0, 0, 0}} // Asteroid
    };

    // Simulate the motion of the bodies
    for(int t=0; t<T; t+=delta_t){
        // Calculate the acceleration of each body
        for(int i=0; i<n_bodies; i++){
            Body b1 = bodies[i];
            double ax = 0;
            double ay = 0;
            double az = 0;
            for(int j=0; j<n_bodies; j++){
                if(j!=i){
                    Body b2 = bodies[j];
                    double dist = distance(b1, b2);
                    double force = G*b1.mass*b2.mass/(pow(dist,2));
                    ax += force*(b2.position[0] - b1.position[0])/dist;
                    ay += force*(b2.position[1] - b1.position[1])/dist;
                    az += force*(b2.position[2] - b1.position[2])/dist;
                }
            }
            bodies[i].acceleration[0] = ax/b1.mass;
            bodies[i].acceleration[1] = ay/b1.mass;
            bodies[i].acceleration[2] = az/b1.mass;
        }

        // Update the velocity and position of each body
        for(int i=0; i<n_bodies; i++){
            Body b = bodies[i];
            b.velocity[0] += b.acceleration[0]*delta_t;
            b.velocity[1] += b.acceleration[1]*delta_t;
            b.velocity[2] += b.acceleration[2]*delta_t;
            b.position[0] += b.velocity[0]*delta_t;
            b.position[1] += b.velocity[1]*delta_t;
            b.position[2] += b.velocity[2]*delta_t;
            bodies[i] = b;
        }

        // Print the positions of the bodies
        for(int i=0; i<n_bodies; i++){
            printf("Body %d position: (%f, %f, %f)\n", i+1, bodies[i].position[0], bodies[i].position[1], bodies[i].position[2]);
        }
    }

    return 0;
}