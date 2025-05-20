//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define GRAVITATIONAL_CONSTANT 6.67e-11

typedef struct {
    double mass;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double force_x;
    double force_y;
}planet;

planet new_planet(double mass, double pos_x, double pos_y, double vel_x, double vel_y){
    planet p = {mass, pos_x, pos_y, vel_x, vel_y};
    return p;
}

void calculate_force(planet* p1, planet* p2, double* force_x, double* force_y){
    double distance = sqrt(pow(p2->pos_x - p1->pos_x, 2) + pow(p2->pos_y - p1->pos_y, 2));
    double force = GRAVITATIONAL_CONSTANT * p1->mass * p2->mass / pow(distance, 2);
    *force_x = force * (p2->pos_x - p1->pos_x) / distance;
    *force_y = force * (p2->pos_y - p1->pos_y) / distance;
}

void update_acceleration(planet* p1, planet* p2){
    double force_x, force_y;
    calculate_force(p1, p2, &force_x, &force_y);
    p1->force_x += force_x;
    p1->force_y += force_y;
}

void simulate_gravity(planet* planets, int num_planets, double time_step, int num_steps){
    for(int i = 0; i < num_steps; i++){
        for(int j = 0; j < num_planets; j++){
            planets[j].force_x = 0;
            planets[j].force_y = 0;
            for(int k = 0; k < num_planets; k++){
                if(j == k){
                    continue;
                }
                update_acceleration(&planets[j], &planets[k]);
            }
            planets[j].vel_x += planets[j].force_x / planets[j].mass * time_step;
            planets[j].vel_y += planets[j].force_y / planets[j].mass * time_step;
            planets[j].pos_x += planets[j].vel_x * time_step;
            planets[j].pos_y += planets[j].vel_y * time_step;
        }
    }
}

int main(){
    planet earth = new_planet(5.97e24, 0, 0, 0, 0);
    planet moon = new_planet(7.342e22, 384400000, 0, 0, 1000);
    planet Jupiter = new_planet(1.898e27, 778500000, 0, 0, 10000);

    planet planets[] = {earth, moon, Jupiter};
    int num_planets = sizeof(planets) / sizeof(planet);
    double time_step = 1;
    int num_steps = 1000;

    simulate_gravity(planets, num_planets, time_step, num_steps);
    
    for(int i = 0; i < num_planets; i++){
        printf("Planet %d: pos_x=%f, pos_y=%f\n", i, planets[i].pos_x, planets[i].pos_y);
    }

    return 0;
}