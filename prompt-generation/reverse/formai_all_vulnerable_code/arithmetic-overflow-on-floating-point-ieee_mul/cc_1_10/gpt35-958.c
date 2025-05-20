//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
} Object;

void update_velocity(Object* obj, double force[3], double time_step) {
    int i;
    double acceleration[3];
    for (i = 0; i < 3; i++) {
        acceleration[i] = force[i] / obj->mass;
        obj->velocity[i] += acceleration[i] * time_step;
    }
}

void update_position(Object* obj, double time_step) {
    int i;
    for (i = 0; i < 3; i++) {
        obj->position[i] += obj->velocity[i] * time_step;
    }
}

double distance(double pos1[3], double pos2[3]) {
    int i;
    double sum = 0.0;
    for (i = 0; i < 3; i++) {
        sum += pow(pos1[i] - pos2[i], 2);
    }
    return sqrt(sum);
}

void grav_force(Object* obj1, Object* obj2, double force[3]) {
    int i;
    double dist_vec[3];
    double dist = distance(obj1->position, obj2->position);
    for (i = 0; i < 3; i++) {
        dist_vec[i] = obj2->position[i] - obj1->position[i];
    }
    double force_scalar = G * obj1->mass * obj2->mass / pow(dist, 2);
    for (i = 0; i < 3; i++) {
        force[i] = force_scalar * dist_vec[i] / dist;
    }
}

int main() {
    int i, t;
    double time_step = 1.0;
    int num_objects = 3;
    Object objects[3] = {
        {1.0 /* mass */, {0.0, 0.0, 0.0} /* position */, {0.0, 0.0, 0.0} /* velocity */},
        {2.0 /* mass */, {1.0e9, 0.0, 0.0} /* position */, {0.0, 30.0, 0.0} /* velocity */},
        {3.0 /* mass */, {0.0, 1.0e9, 0.0} /* position */, {30.0, 0.0, 0.0} /* velocity */}
    };
    double forces[num_objects][3];
    for (t = 0; t < 1000; t++) { // run simulation for 1000 time steps
        for (i = 0; i < num_objects; i++) { // calculate forces acting on each object
            int j;
            forces[i][0] = forces[i][1] = forces[i][2] = 0.0;
            for (j = 0; j < num_objects; j++) {
                if (i != j) {
                    double force[3];
                    grav_force(&objects[i], &objects[j], force);
                    forces[i][0] += force[0];
                    forces[i][1] += force[1];
                    forces[i][2] += force[2];
                }
            }
        }
        for (i = 0; i < num_objects; i++) { // update positions and velocities of each object
            update_velocity(&objects[i], forces[i], time_step);
            update_position(&objects[i], time_step);
        }
    }
    for (i = 0; i < num_objects; i++) { // print final positions and velocities of each object
        printf("Object %d:\n", i);
        printf(" Position: (%.3f, %.3f, %.3f)\n", objects[i].position[0], objects[i].position[1], objects[i].position[2]);
        printf(" Velocity: (%.3f, %.3f, %.3f)\n", objects[i].velocity[0], objects[i].velocity[1], objects[i].velocity[2]);
    }
    return 0;
}