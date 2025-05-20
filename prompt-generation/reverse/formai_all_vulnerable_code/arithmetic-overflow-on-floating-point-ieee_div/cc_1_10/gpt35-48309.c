//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct {
    char name[20];
    double mass; //in kg
    double radius; //in m
    double distance; //in m
    double angle;   //in radians
    double angular_velocity; //in radians/sec
    double orbital_period; //in days
} Planet;

void update_planet_position(Planet* planet, double time_elapsed);

int main() {
    //creating an array of 8 planets
    Planet planets[8] = {
        {"Sun", 1.9885e30, 696340000, 0, 0, 0, 0}, //the sun is in the center
        {"Mercury", 3.3011e23, 2439700, 57909227000, -PI/4, -2.0976e-7, 87.969}, 
        {"Venus", 4.8675e24, 6051800, 108209475000, PI/3, 2.9997e-7, 224.701},
        {"Earth", 5.9724e24, 6371000, 149600000000, PI/6, 1.991e-7, 365.256},
        {"Mars", 6.4171e23, 3389500, 227939200000, -PI/8, -1.0588e-7, 686.971},
        {"Jupiter", 1.8982e27, 69911000, 778299000000, PI/4, 7.118e-8, 4332.59}, 
        {"Saturn", 5.6834e26, 58232000, 1429400000000, -2*PI/5, -4.669e-8, 10759.22},
        {"Uranus", 8.6810e25, 25362000, 2870990000000, PI/2, 3.502e-8, 30688.5} 
    };
    
    const double time_step = 86400.0; //time step is one day
    double current_time = 0.0;
    const double simulation_duration = 365.2425*100;
        
    //running the simulation
    int i;
    while (current_time < simulation_duration) {
        for (i = 0; i < 8; i++) {
            update_planet_position(&planets[i], time_step);
        }
        
        current_time += time_step;
    }
    
    //printing the final positions of the planets
    printf("Final positions of the planets after %lf days:\n", simulation_duration);
    for (i = 0; i < 8; i++) {
        printf("%s is at (%lf, %lf)\n", planets[i].name, planets[i].distance*cos(planets[i].angle), planets[i].distance*sin(planets[i].angle));
    }
    
    return 0;
}

void update_planet_position(Planet* planet, double time_elapsed) {
    double angle_change = time_elapsed*2*PI/(planet->orbital_period*86400.0); //2*PI is one full revolution
    planet->angle += angle_change;
    if (planet->angle >= 2*PI) {
        planet->angle -= 2*PI;
    }
    else if (planet->angle < 0) {
        planet->angle += 2*PI;
    }
}