//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Define the number of planets
#define NUM_PLANETS 8

// Define the planets
typedef struct {
    char name[20];
    int radius;
    float distance;
    float speed;
} planet;

// Define the solar system
planet solarSystem[NUM_PLANETS] = {
    {"Mercury", 10, 57.9, 48.331},
    {"Venus", 20, 108.2, 35.02},
    {"Earth", 30, 149.6, 29.78},
    {"Mars", 40, 227.9, 24.13},
    {"Jupiter", 80, 778.3, 13.07},
    {"Saturn", 90, 1427, 9.58},
    {"Uranus", 50, 2871, 6.81},
    {"Neptune", 40, 4498, 5.43}
};

// Define the functions
void init() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLANETS; i++) {
        solarSystem[i].speed = (float)rand() / RAND_MAX * 10;
    }
}

void update() {
    for (int i = 0; i < NUM_PLANETS; i++) {
        solarSystem[i].distance += solarSystem[i].speed;
    }
}

void print() {
    printf("Solar System:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Name: %s\n", solarSystem[i].name);
        printf("Radius: %d\n", solarSystem[i].radius);
        printf("Distance: %f\n", solarSystem[i].distance);
        printf("Speed: %f\n\n", solarSystem[i].speed);
    }
}

// Define the main function
int main() {
    init();
    int choice;
    while (1) {
        printf("1. Print Solar System\n");
        printf("2. Update Solar System\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print();
                break;
            case 2:
                update();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}