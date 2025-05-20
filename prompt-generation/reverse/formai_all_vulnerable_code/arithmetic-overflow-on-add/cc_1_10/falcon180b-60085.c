//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for tracking fitness data
typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    time_t last_update;
} FitnessData;

// Function to initialize fitness data
void init_fitness_data(FitnessData *data) {
    strcpy(data->name, "Unknown");
    data->age = 0;
    data->weight = 0;
    data->height = 0;
    data->steps = 0;
    data->calories = 0;
    data->last_update = 0;
}

// Function to update fitness data
void update_fitness_data(FitnessData *data, int steps) {
    data->steps += steps;
    data->calories += (int) ((double) steps * 0.1 * (double) data->weight);
    time_t current_time = time(NULL);
    if (current_time - data->last_update >= 60) {
        data->last_update = current_time;
    }
}

// Function to print fitness data
void print_fitness_data(FitnessData *data) {
    printf("Name: %s\n", data->name);
    printf("Age: %d\n", data->age);
    printf("Weight: %d kg\n", data->weight);
    printf("Height: %d cm\n", data->height);
    printf("Steps: %d\n", data->steps);
    printf("Calories burned: %d\n", data->calories);
    printf("Last update: %s", ctime(&data->last_update));
}

// Main function
int main() {
    FitnessData data;
    init_fitness_data(&data);

    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Update fitness data\n");
        printf("2. Print fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of steps taken: ");
            int steps;
            scanf("%d", &steps);
            update_fitness_data(&data, steps);
            break;
        case 2:
            print_fitness_data(&data);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}