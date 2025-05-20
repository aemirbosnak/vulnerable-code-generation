//FormAI DATASET v1.0 Category: Physics simulation ; Style: innovative
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81
#define PHYSICS_LOOP_ITERATIONS_PER_SECOND 60
#define TIME_STEP (1.0 / PHYSICS_LOOP_ITERATIONS_PER_SECOND)

typedef struct Vector {
    double x, y, z;
} Vector;

typedef struct Object {
    Vector position, velocity, acceleration;
    double mass, radius;
} Object;

void update_acceleration(Object* object) {
    double magnitude = sqrt(pow(object->acceleration.x, 2) + pow(object->acceleration.y, 2) + pow(object->acceleration.z, 2));
    double max_acceleration = object->mass * GRAVITY;
    if (magnitude > max_acceleration) {
        object->acceleration.x *= max_acceleration / magnitude;
        object->acceleration.y *= max_acceleration / magnitude;
        object->acceleration.z *= max_acceleration / magnitude;
    }
}

void update_velocity(Object* object) {
    object->velocity.x += object->acceleration.x * TIME_STEP;
    object->velocity.y += object->acceleration.y * TIME_STEP;
    object->velocity.z += object->acceleration.z * TIME_STEP;
}

void update_position(Object* object) {
    object->position.x += object->velocity.x * TIME_STEP;
    object->position.y += object->velocity.y * TIME_STEP;
    object->position.z += object->velocity.z * TIME_STEP;
}

void simulate_physics_loop(Object* objects, int object_count) {
    while (1) {
        for (int i = 0; i < object_count; i++) {
            update_acceleration(&objects[i]);
        }
        for (int i = 0; i < object_count; i++) {
            update_velocity(&objects[i]);
        }
        for (int i = 0; i < object_count; i++) {
            update_position(&objects[i]);
        }
        // ... render objects ...
        // ... handle user input ...
        // ... wait for next loop iteration ...
    }
}

int main() {
    Object objects[2] = {
        {
            .position = { .x = 0, .y = 0, .z = 0 },
            .velocity = { .x = 0, .y = 0, .z = 0 },
            .acceleration = { .x = 0, .y = -GRAVITY, .z = 0 },
            .mass = 10,
            .radius = 1.0
        },
        {
            .position = { .x = 0, .y = 10, .z = 0 },
            .velocity = { .x = 0, .y = 0, .z = 0 },
            .acceleration = { .x = 0, .y = -GRAVITY, .z = 0 },
            .mass = 1,
            .radius = 0.5
        }
    };
    simulate_physics_loop(objects, 2);
    return 0;
}