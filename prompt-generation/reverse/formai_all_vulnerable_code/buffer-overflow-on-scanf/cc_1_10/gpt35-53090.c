//FormAI DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>

float calculateForce(float mass, float acceleration) {
    float force;
    force = mass * acceleration;
    return force;
}

float calculateAcceleration(float force, float mass) {
    float acceleration;
    acceleration = force / mass;
    return acceleration;
}

float calculateMass(float force, float acceleration) {
    float mass;
    mass = force / acceleration;
    return mass;
}

int main() {
    int option;
    float mass, acceleration, force;
    
    printf("Choose an option:\n");
    printf("1 - Calculate force\n2 - Calculate acceleration\n3 - Calculate mass\n");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("Enter the mass (kg): ");
            scanf("%f", &mass);
            printf("Enter the acceleration (m/s^2): ");
            scanf("%f", &acceleration);
            force = calculateForce(mass, acceleration);
            printf("The force is %.2f N\n", force);
            break;
        case 2:
            printf("Enter the force (N): ");
            scanf("%f", &force);
            printf("Enter the mass (kg): ");
            scanf("%f", &mass);
            acceleration = calculateAcceleration(force, mass);
            printf("The acceleration is %.2f m/s^2\n", acceleration);
            break;
        case 3:
            printf("Enter the force (N): ");
            scanf("%f", &force);
            printf("Enter the acceleration (m/s^2): ");
            scanf("%f", &acceleration);
            mass = calculateMass(force, acceleration);
            printf("The mass is %.2f kg\n", mass);
            break;
        default:
            printf("Invalid option!\n");
    }
    
    return 0;
}