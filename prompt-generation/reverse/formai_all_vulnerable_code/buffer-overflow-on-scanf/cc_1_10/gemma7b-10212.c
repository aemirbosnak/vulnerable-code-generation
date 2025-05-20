//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159
#define G 9.80665

int main() {

    float mass, force, velocity, acceleration;
    int choice;

    printf("Select an option:\n");
    printf("1. Mass to Force\n");
    printf("2. Force to Mass\n");
    printf("3. Velocity to Acceleration\n");
    printf("4. Acceleration to Velocity\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the mass:");
            scanf("%f", &mass);
            force = mass * G;
            printf("The force is: %.2f N\n", force);
            break;
        case 2:
            printf("Enter the force:");
            scanf("%f", &force);
            mass = force / G;
            printf("The mass is: %.2f kg\n", mass);
            break;
        case 3:
            printf("Enter the velocity:");
            scanf("%f", &velocity);
            acceleration = velocity * PI;
            printf("The acceleration is: %.2f m/s^2\n", acceleration);
            break;
        case 4:
            printf("Enter the acceleration:");
            scanf("%f", &acceleration);
            velocity = acceleration * PI;
            printf("The velocity is: %.2f m/s\n", velocity);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}