//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent fitness data
typedef struct {
    int steps;
    int calories;
    double distance;
} FitnessData;

// Function to record fitness data
void recordFitnessData(FitnessData* data, int steps, int calories, double distance) {
    data->steps = steps;
    data->calories = calories;
    data->distance = distance;
}

// Function to display fitness data
void displayFitnessData(FitnessData* data) {
    printf("Steps: %d\n", data->steps);
    printf("Calories: %d\n", data->calories);
    printf("Distance: %f miles\n", data->distance);
}

int main() {
    int option = 0;
    FitnessData data;
    recordFitnessData(&data, 0, 0, 0.0); // Initialize fitness data

    do {
        // Display menu
        printf("\nFitness Tracker Menu:\n");
        printf("1. Record steps\n");
        printf("2. Record calories burned\n");
        printf("3. Record distance traveled\n");
        printf("4. Display fitness data\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                // Record steps
                printf("Enter the number of steps: ");
                int steps;
                scanf("%d", &steps);
                recordFitnessData(&data, steps, data.calories, data.distance);
                break;
            case 2:
                // Record calories burned
                printf("Enter the number of calories burned: ");
                int calories;
                scanf("%d", &calories);
                recordFitnessData(&data, data.steps, calories, data.distance);
                break;
            case 3:
                // Record distance traveled
                printf("Enter the distance traveled (in miles): ");
                double distance;
                scanf("%lf", &distance);
                recordFitnessData(&data, data.steps, data.calories, distance);
                break;
            case 4:
                // Display fitness data
                displayFitnessData(&data);
                break;
            case 5:
                // Exit program
                printf("Exiting program...\n");
                break;
            default:
                // Invalid option selected
                printf("Invalid option selected. Please try again.\n");
        }
    } while(option != 5);

    return 0;
}