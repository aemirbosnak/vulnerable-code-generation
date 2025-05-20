//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the fitness tracker data
typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
    int steps;
    int distance;
    int calories;
} FitnessData;

// Function to initialize the fitness tracker data
void initFitnessData(FitnessData* fitnessData) {
    strcpy(fitnessData->name, "John Doe");
    fitnessData->age = 30;
    fitnessData->weight = 80;
    fitnessData->height = 180;
    fitnessData->steps = 0;
    fitnessData->distance = 0;
    fitnessData->calories = 0;
}

// Function to update the fitness tracker data
void updateFitnessData(FitnessData* fitnessData) {
    int steps = 0;
    int distance = 0;
    int calories = 0;

    // Calculate steps, distance, and calories based on fitness activity
    // For example, walking for 30 minutes at a moderate pace
    // Steps = 3000
    // Distance = 2.5 miles
    // Calories = 150

    fitnessData->steps += steps;
    fitnessData->distance += distance;
    fitnessData->calories += calories;
}

// Function to display the fitness tracker data
void displayFitnessData(FitnessData* fitnessData) {
    printf("Name: %s\n", fitnessData->name);
    printf("Age: %d\n", fitnessData->age);
    printf("Weight: %d kg\n", fitnessData->weight);
    printf("Height: %d cm\n", fitnessData->height);
    printf("Steps: %d\n", fitnessData->steps);
    printf("Distance: %d miles\n", fitnessData->distance);
    printf("Calories: %d\n", fitnessData->calories);
}

// Main function
int main() {
    FitnessData fitnessData;
    initFitnessData(&fitnessData);

    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Update fitness data\n");
        printf("2. Display fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                updateFitnessData(&fitnessData);
                break;
            case 2:
                displayFitnessData(&fitnessData);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}