//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: cheerful
#include <stdio.h>
#include <math.h>

#define SIZE 3 //number of planets in simulation

struct planet {
    char name[15];
    double mass;
    double position[2];
    double velocity[2];
    double acceleration[2];
};

int main() {
    struct planet planets[SIZE] = { //initialize planets
        {"Planet A", 5.97e24, {0, 0}, {0, 0}, {0, 0}},
        {"Planet B", 3.29e23, {100, 0}, {0, 29.3}, {0, 0}},
        {"Planet C", 1.898e27, {-150, 0}, {0, -13.1}, {0, 0}},
    };

    double time = 0; //initialize time
    double dt = 0.1; //time step
    double G = 6.672e-11; //gravitational constant
    double distance, force;

    printf("Let's simulate the gravitational interaction of some planets!\n");
    printf("Press Ctrl + C to stop simulating.\n");

    while(1) { //infinite loop until user stops simulation
        for(int i = 0; i < SIZE; i++) { //update acceleration for each planet
            planets[i].acceleration[0] = 0; //reset acceleration
            planets[i].acceleration[1] = 0;

            for(int j = 0; j < SIZE; j++) { //calculate gravitational force from other planets
                if(j != i) { //skip calculation for same planet
                    distance = sqrt(pow(planets[i].position[0] - planets[j].position[0], 2) + pow(planets[i].position[1] - planets[j].position[1], 2));
                    force = G * planets[i].mass * planets[j].mass / pow(distance, 2);

                    planets[i].acceleration[0] += force * (planets[j].position[0] - planets[i].position[0]) / (distance * planets[i].mass);
                    planets[i].acceleration[1] += force * (planets[j].position[1] - planets[i].position[1]) / (distance * planets[i].mass);
                }
            }
        }

        for(int i = 0; i < SIZE; i++) { //update velocity and position for each planet
            planets[i].velocity[0] += planets[i].acceleration[0] * dt;
            planets[i].velocity[1] += planets[i].acceleration[1] * dt;

            planets[i].position[0] += planets[i].velocity[0] * dt;
            planets[i].position[1] += planets[i].velocity[1] * dt;

            printf("%s: (%.2f, %.2f)\n", planets[i].name, planets[i].position[0], planets[i].position[1]);
        }

        time += dt; //update time
        printf("Time: %.2f\n\n", time);

        //add some flair
        printf("Wow! These planets are really moving!\n");
        printf("I wonder if there are any space aliens out there watching.\n");
        printf("Let's keep going and see if we can skip a planet across the galaxy!\n");
        printf("3...\n");
        printf("2...\n");
        printf("1...\n");
        printf("Blast off!!!\n\n");

        //sleep for a little bit
        for(int i = 0; i < 100000000; i++) {}
    }

    return 0;
}