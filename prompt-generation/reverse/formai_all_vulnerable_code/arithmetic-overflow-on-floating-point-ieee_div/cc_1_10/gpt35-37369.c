//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define DELTA_T 0.1 // time interval for simulation
#define STEPS 1000 // number of simulation steps
#define MASS_EARTH 5.97e24 // mass of Earth
#define MASS_SUN 1.99e30 // mass of Sun

typedef struct {
    double xpos;
    double ypos;
    double xvel;
    double yvel;
    double mass;
} Object;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void update_position(Object *obj) {
    obj->xpos += obj->xvel * DELTA_T;
    obj->ypos += obj->yvel * DELTA_T;
}

void update_velocity(Object *obj, double fx, double fy) {
    obj->xvel += fx / obj->mass * DELTA_T;
    obj->yvel += fy / obj->mass * DELTA_T;
}

void simulate(Object *obj1, Object *obj2) {
    double dist = distance(obj1->xpos, obj1->ypos, obj2->xpos, obj2->ypos);
    double force = G * obj1->mass * obj2->mass / pow(dist, 2);
    double fx = force * (obj2->xpos - obj1->xpos) / dist;
    double fy = force * (obj2->ypos - obj1->ypos) / dist;
    
    update_velocity(obj1, fx, fy);
    update_velocity(obj2, -fx, -fy);
}

int main() {
    Object earth = {0, 0, 0, 29784, MASS_EARTH};
    Object sun = {0, 0, 0, 0, MASS_SUN};
    
    for (int i = 0; i < STEPS; i++) {
        simulate(&earth, &sun);
        update_position(&earth);
        update_position(&sun);
        printf("Earth Position: (%f, %f)\n", earth.xpos, earth.ypos);
        printf("Sun Position: (%f, %f)\n", sun.xpos, sun.ypos);
    }
    
    return 0;
}