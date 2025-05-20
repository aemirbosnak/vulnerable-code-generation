//FormAI DATASET v1.0 Category: Physics simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.8

float projectileMotion(float angle, float velocity) {
    float time = (2 * velocity * sin(angle)) / GRAVITY;
    float distance = (pow(velocity, 2) * sin(2 * angle)) / GRAVITY;

    return distance;
}

float uniformAcceleration(float distance) {
    float u = 0;
    float a = 2;
    float v = sqrt(pow(u, 2) + (2 * a * distance));

    return v;
}

float rollingFriction(float mass, float velocity, float radius) {
    float g = 9.8;
    float mu = 0.2;
    float Ff = mu * mass * g;

    float Ke = (0.5 * mass * pow(velocity, 2)) + (0.5 * pow(radius, 2) * (2 * Ff * radius));

    return Ke;
}

int main() {
    float angle, velocity, distance, v;
    float mass = 5;
    float radius = 0.2;

    printf("Welcome to the Physics Simulation!\n\n");

    printf("Projectile Motion\n");
    printf("Enter the angle (in degrees): ");
    scanf("%f", &angle);
    printf("Enter the velocity (in m/s): ");
    scanf("%f", &velocity);
    distance = projectileMotion((angle * M_PI / 180), velocity);
    printf("The distance is: %f\n\n", distance);

    printf("Uniform Acceleration\n");
    printf("Enter the distance (in m): ");
    scanf("%f", &distance);
    v = uniformAcceleration(distance);
    printf("The velocity is: %f\n\n", v);

    printf("Rolling Friction\n");
    printf("Enter the velocity (in m/s): ");
    scanf("%f", &velocity);
    float Ke = rollingFriction(mass, velocity, radius);
    printf("The kinetic energy is: %f\n\n", Ke);

    printf("Thank you for using the Physics Simulation!\n");

    return 0;
}