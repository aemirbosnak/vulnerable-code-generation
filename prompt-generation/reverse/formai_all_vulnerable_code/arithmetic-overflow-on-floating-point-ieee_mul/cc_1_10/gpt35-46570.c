//FormAI DATASET v1.0 Category: Physics simulation ; Style: genious
//Genius-level Physics simulation example

#include <stdio.h>
#include <math.h>

#define G 6.67430e-11  //Universal gravitational constant

//Structure for storing celestial object information
typedef struct {
    double mass;     //Mass in kg
    double radius;   //Radius in meters
    double x_pos;    //X position in meters
    double y_pos;    //Y position in meters
    double x_vel;    //X velocity in meters/second
    double y_vel;    //Y velocity in meters/second
} CelestialObject;

//Function to calculate the distance between two celestial objects
double get_distance(CelestialObject obj1, CelestialObject obj2) {
    double dx = obj1.x_pos - obj2.x_pos;
    double dy = obj1.y_pos - obj2.y_pos;
    double dist = sqrt(pow(dx,2) + pow(dy,2));
    return dist;
}

//Function to calculate the gravitational force between two celestial objects
double get_force(CelestialObject obj1, CelestialObject obj2) {
    double dist = get_distance(obj1, obj2);
    double force = G * obj1.mass * obj2.mass / pow(dist,2);
    return force;
}

//Function to update the position and velocity of a celestial object based on gravitational forces
void update_object(CelestialObject *obj, CelestialObject objects[], int num_objects, double time_step) {
    double x_acc = 0;
    double y_acc = 0;
    for (int i=0; i<num_objects; i++) {
        if (objects[i].mass != obj->mass) {
            double force = get_force(*obj, objects[i]);
            double theta = atan2(objects[i].y_pos - obj->y_pos, objects[i].x_pos - obj->x_pos);
            x_acc += force * cos(theta) / obj->mass;
            y_acc += force * sin(theta) / obj->mass;
        }
    }
    obj->x_vel += x_acc * time_step;
    obj->y_vel += y_acc * time_step;
    obj->x_pos += obj->x_vel * time_step;
    obj->y_pos += obj->y_vel * time_step;
}

int main() {
    //Initialize celestial objects
    CelestialObject sun = {1.9885e30, 6.96342e8, 0, 0, 0, 0};  //Mass, radius, x_pos, y_pos, x_vel, y_vel
    CelestialObject earth = {5.972e24, 6.371e6, 1.496e11, 0, 0, 29783};  //Mass, radius, x_pos, y_pos, x_vel, y_vel
    CelestialObject moon = {7.342e22, 1.7371e6, 1.496e11+3.844e8, 0, 0, 3073};  //Mass, radius, x_pos, y_pos, x_vel, y_vel
    
    //Simulation settings
    int num_steps = 10000;
    double time_step = 86400;  //1 day in seconds
    
    //Simulation loop
    for (int step=0; step<num_steps; step++) {
        //Update positions and velocities of celestial objects
        update_object(&sun, (CelestialObject[]){earth, moon}, 2, time_step);
        update_object(&earth, (CelestialObject[]){sun, moon}, 2, time_step);
        update_object(&moon, (CelestialObject[]){sun, earth}, 2, time_step);
        
        //Print positions of celestial objects
        printf("Step %d: Sun (%.2f,%.2f), Earth (%.2f,%.2f), Moon (%.2f,%.2f)\n", step, sun.x_pos, sun.y_pos, earth.x_pos, earth.y_pos, moon.x_pos, moon.y_pos);
    }
    
    return 0;
}