//FormAI DATASET v1.0 Category: Physics simulation ; Style: authentic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define G 6.67408E-11

struct Vector {
    double x;
    double y;
    double z;
};

struct Object {
    double mass;
    struct Vector position;
    struct Vector velocity;
    struct Vector acceleration;
};

double distance(struct Object obj1, struct Object obj2) {
    double dx = obj1.position.x - obj2.position.x;
    double dy = obj1.position.y - obj2.position.y;
    double dz = obj1.position.z - obj2.position.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

struct Vector gravitationalForce(struct Object obj1, struct Object obj2) {
    double dist = distance(obj1, obj2);
    double forceMagnitude = (G * obj1.mass * obj2.mass) / (dist * dist);
    struct Vector force = {
        .x = forceMagnitude * (obj2.position.x - obj1.position.x) / dist,
        .y = forceMagnitude * (obj2.position.y - obj1.position.y) / dist,
        .z = forceMagnitude * (obj2.position.z - obj1.position.z) / dist
    };
    return force;
}

struct Vector netForce(struct Object obj, struct Object objects[], int numObjects) {
    struct Vector force = {
        .x = 0,
        .y = 0,
        .z = 0
    };
    for (int i = 0; i < numObjects; i++) {
        if (obj.mass != objects[i].mass) {
            struct Vector f = gravitationalForce(obj, objects[i]);
            force.x += f.x;
            force.y += f.y;
            force.z += f.z;
        }
    }
    return force;
}

void updateObject(struct Object *obj, struct Object objects[], int numObjects, double timeStep) {
    struct Vector force = netForce(*obj, objects, numObjects);
    obj->acceleration.x = force.x / obj->mass;
    obj->acceleration.y = force.y / obj->mass;
    obj->acceleration.z = force.z / obj->mass;
    obj->velocity.x += obj->acceleration.x * timeStep;
    obj->velocity.y += obj->acceleration.y * timeStep;
    obj->velocity.z += obj->acceleration.z * timeStep;
    obj->position.x += obj->velocity.x * timeStep;
    obj->position.y += obj->velocity.y * timeStep;
    obj->position.z += obj->velocity.z * timeStep;
}

void simulate(struct Object objects[], int numObjects, double totalTime, double timeStep) {
    printf("Starting simulation...\n");
    int numSteps = (int) (totalTime / timeStep);
    for (int i = 0; i < numSteps; i++) {
        printf("Step %d\n", i+1);
        for (int j = 0; j < numObjects; j++) {
            updateObject(&objects[j], objects, numObjects, timeStep);
            printf("Object %d\n", j+1);
            printf("\tPosition: (%.2f, %.2f, %.2f)\n", objects[j].position.x, objects[j].position.y, objects[j].position.z);
            printf("\tVelocity: (%.2f, %.2f, %.2f)\n", objects[j].velocity.x, objects[j].velocity.y, objects[j].velocity.z);
            printf("\tAcceleration: (%.2f, %.2f, %.2f)\n", objects[j].acceleration.x, objects[j].acceleration.y, objects[j].acceleration.z);
        }
    }
    printf("Simulation complete.\n");
}

int main() {
    struct Object objects[] = {
        {
            .mass = 5.97E24,
            .position = {
                .x = 0,
                .y = 0,
                .z = 0
            },
            .velocity = {
                .x = 0,
                .y = 0,
                .z = 0
            }
        },
        {
            .mass = 7.34E22,
            .position = {
                .x = 384400000,
                .y = 0,
                .z = 0
            },
            .velocity = {
                .x = 0,
                .y = 1022,
                .z = 0
            }
        }
    };
    int numObjects = sizeof(objects) / sizeof(objects[0]);
    double totalTime = 5000000; // seconds
    double timeStep = 1000; // seconds
    simulate(objects, numObjects, totalTime, timeStep);
    return 0;
}