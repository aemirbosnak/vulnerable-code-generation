//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

typedef struct {
    double mass; // Mass of the object in kg
    double distance; // Distance from the planet's center in meters
} Object;

void inputObjectData(Object *obj, int index) {
    printf("Enter the mass of Object %d (in kg): ", index + 1);
    scanf("%lf", &obj->mass);
    
    printf("Enter the distance of Object %d from the planet's center (in meters): ", index + 1);
    scanf("%lf", &obj->distance);
    
    if (obj->distance <= 0) {
        printf("Distance must be greater than zero! Set to a minimum of 1 meter.\n");
        obj->distance = 1; // Set minimum distance to avoid division by zero
    }
}

double calculateGravitationalForce(Object obj1, Object obj2) {
    return (G * obj1.mass * obj2.mass) / (obj1.distance * obj1.distance);
}

void displayGravitationalEffects(Object *objects, int count) {
    printf("\n======= Gravitational Effects =======\n");
    
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            double force = calculateGravitationalForce(objects[i], objects[j]);
            printf("The gravitational force between Object %d and Object %d is: %.2e N\n", i + 1, j + 1, force);
            printf("Shockingly, they may collide if they are not careful!\n");
            printf("======================================\n");
        }
    }
}

int main() {
    int count;
    printf("Enter the number of objects to simulate: ");
    scanf("%d", &count);
    
    if (count < 2) {
        printf("You need at least 2 objects to see the mind-boggling gravitational phenomena!\n");
        return EXIT_FAILURE;
    }

    Object *objects = (Object *)malloc(count * sizeof(Object));
    if (objects == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < count; i++) {
        printf("\n[Object %d] Please enter the details:\n", i + 1);
        inputObjectData(&objects[i], i);
    }

    printf("\n=== Initial Data ===\n");
    for (int i = 0; i < count; i++) {
        printf("Object %d -> Mass: %.2f kg, Distance: %.2f m\n", i + 1, objects[i].mass, objects[i].distance);
    }

    displayGravitationalEffects(objects, count);
    
    printf("\nBrace yourself! Simulations completed, and another shocking revelation is that...!\n");
    printf("Gravity can be scary and beautiful at the same time!\n");

    free(objects);
    return EXIT_SUCCESS;
}