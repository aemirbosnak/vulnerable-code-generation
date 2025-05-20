//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000

struct {
    int steps;
    double distance;
    int calories;
} fitness_data;

void init() {
    fitness_data.steps = 0;
    fitness_data.distance = 0;
    fitness_data.calories = 0;
}

void step() {
    fitness_data.steps++;
    fitness_data.distance += 1;
    fitness_data.calories += 1;
}

void display() {
    printf("Steps: %d\n", fitness_data.steps);
    printf("Distance: %.2f\n", fitness_data.distance);
    printf("Calories: %d\n", fitness_data.calories);
}

int main() {
    init();

    int choice;
    do {
        printf("\n");
        printf("Fitness Tracker\n");
        printf("1. Step\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                step();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);

    return 0;
}