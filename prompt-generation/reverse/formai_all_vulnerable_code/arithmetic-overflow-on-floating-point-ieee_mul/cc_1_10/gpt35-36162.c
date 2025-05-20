//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159

//Structure to store planet information
typedef struct planet{
    char name[20];
    float mass;
    float radius;
    float x_pos;
    float y_pos;
    float x_velocity;
    float y_velocity;
}Planet;

//Function to calculate distance between two planets
float calc_distance(float x1, float y1, float x2, float y2){
    float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

//Function to calculate gravitational force between two planets
float calc_gravity_force(float mass1, float mass2, float distance){
    float force = (6.67e-11 * mass1 * mass2) / pow(distance, 2);
    return force;
}

//Function to calculate gravitational acceleration on a planet
float calc_gravity_acceleration(float force, float mass){
    float acceleration = force / mass;
    return acceleration;
}

//Function to update velocities and positions of planets after a time step
void update_planet(Planet *p1, Planet *p2, float time_step){
    float distance = calc_distance(p1->x_pos, p1->y_pos, p2->x_pos, p2->y_pos);
    float force = calc_gravity_force(p1->mass, p2->mass, distance);
    float acceleration = calc_gravity_acceleration(force, p1->mass);
    float angle = atan2((p2->y_pos - p1->y_pos), (p2->x_pos - p1->x_pos));
    p1->x_velocity += acceleration * cos(angle) * time_step;
    p1->y_velocity += acceleration * sin(angle) * time_step;
    p1->x_pos += p1->x_velocity * time_step;
    p1->y_pos += p1->y_velocity * time_step;
}

int main(){
    //Create planet objects
    Planet p1 = {"Earth", 5.97e24, 6.38e6, 0, 0, 0, 0};
    Planet p2 = {"Mars", 6.39e23, 3.39e6, 2.07e11, 0, 0, 24000};
    Planet p3 = {"Jupiter", 1.90e27, 6.99e7, 7.79e11, 0, 0, 13000};
    Planet p4 = {"Saturn", 5.68e26, 5.82e7, 1.43e12, 0, 0, 9000};

    float time_step = 86400; //one day in seconds

    printf("Planet Gravity Simulation\n");

    int i;
    for(i=0;i<365;i++){
        //Update positions and velocities of Earth based on gravitational force from other planets
        update_planet(&p1, &p2, time_step);
        update_planet(&p1, &p3, time_step);
        update_planet(&p1, &p4, time_step);

        //Update positions and velocities of other planets in same way
        update_planet(&p2, &p1, time_step);
        update_planet(&p2, &p3, time_step);
        update_planet(&p2, &p4, time_step);

        update_planet(&p3, &p1, time_step);
        update_planet(&p3, &p2, time_step);
        update_planet(&p3, &p4, time_step);

        update_planet(&p4, &p1, time_step);
        update_planet(&p4, &p2, time_step);
        update_planet(&p4, &p3, time_step);

        //Print positions after each day
        printf("Day %d: Earth(%0.1f, %0.1f), Mars(%0.1f, %0.1f), Jupiter(%0.1f, %0.1f), Saturn(%0.1f, %0.1f)\n", i+1, p1.x_pos, p1.y_pos, p2.x_pos, p2.y_pos, p3.x_pos, p3.y_pos, p4.x_pos, p4.y_pos);
    }

    return 0;
}