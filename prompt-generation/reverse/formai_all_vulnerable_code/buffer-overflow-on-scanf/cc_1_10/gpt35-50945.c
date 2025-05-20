//FormAI DATASET v1.0 Category: Physics simulation ; Style: systematic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    double length, width, height, density, angle, velocity, acceleration;
    double g = 9.8; // acceleration due to gravity in m/s^2
    double force_gravity, force_normal, force_friction, force_resultant;
    double friction_coefficient;
    double mass, moment_of_inertia, angular_velocity, torque;

    printf("Enter length of the box: ");
    scanf("%lf", &length);

    printf("Enter width of the box: ");
    scanf("%lf", &width);

    printf("Enter height of the box: ");
    scanf("%lf", &height);

    printf("Enter density of the box (in kg/m^3): ");
    scanf("%lf", &density);

    printf("Enter angle of the inclined plane (in degrees): ");
    scanf("%lf", &angle);

    printf("Enter velocity of the box (in m/s): ");
    scanf("%lf", &velocity);

    printf("Enter friction coefficient of the surface: ");
    scanf("%lf", &friction_coefficient);

    printf("Enter mass of the wheel: ");
    scanf("%lf", &mass);

    // Calculate the force of gravity
    force_gravity = mass * g;

    // Calculate the force normal
    force_normal = force_gravity * cos(angle * PI / 180.0);

    // Calculate the force of friction
    force_friction = friction_coefficient * force_normal;

    // Calculate the resultant force
    force_resultant = force_normal * sin(angle * PI / 180.0) - force_friction;

    // Calculate the acceleration of the box
    acceleration = force_resultant / mass;

    // Calculate the moment of inertia of the wheel
    moment_of_inertia = 0.5 * mass * pow(length, 2);

    // Calculate the torque required to accelerate the wheel
    torque = moment_of_inertia * acceleration;

    // Calculate the angular velocity of the wheel
    angular_velocity = velocity / (0.5 * length);

    // Print the results
    printf("\nForce of gravity          : %.2lf N\n", force_gravity);
    printf("Force normal              : %.2lf N\n", force_normal);
    printf("Force of friction         : %.2lf N\n", force_friction);
    printf("Resultant force           : %.2lf N\n", force_resultant);
    printf("Acceleration of the box   : %.2lf m/s^2\n", acceleration);
    printf("Moment of inertia         : %.2lf kg.m^2\n", moment_of_inertia);
    printf("Torque required           : %.2lf N.m\n", torque);
    printf("Angular velocity of wheel : %.2lf rad/s\n", angular_velocity);

    return 0;
}