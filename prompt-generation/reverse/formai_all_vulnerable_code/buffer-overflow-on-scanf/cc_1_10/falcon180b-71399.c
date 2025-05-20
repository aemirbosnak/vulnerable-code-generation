//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 1000

// Struct to hold fitness data
typedef struct {
    int steps;
    double distance;
    time_t start_time;
    time_t end_time;
} FitnessData;

// Function to initialize the fitness data
void init_fitness_data(FitnessData *data) {
    data->steps = 0;
    data->distance = 0.0;
    time(&data->start_time);
}

// Function to update the fitness data with new steps and distance
void update_fitness_data(FitnessData *data, int steps, double distance) {
    data->steps += steps;
    data->distance += distance;
    time(&data->end_time);
}

// Function to print the fitness data
void print_fitness_data(FitnessData *data) {
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2f\n", data->distance);
    printf("Time: %s", ctime(&data->start_time));
    printf(" to %s\n", ctime(&data->end_time));
}

// Function to reset the fitness data
void reset_fitness_data(FitnessData *data) {
    data->steps = 0;
    data->distance = 0.0;
    time(&data->start_time);
    time(&data->end_time);
}

int main() {
    FitnessData data;
    int choice, steps;
    double distance;

    init_fitness_data(&data);

    while(1) {
        printf("\nFitness Tracker\n");
        printf("1. Update Steps and Distance\n");
        printf("2. Print Fitness Data\n");
        printf("3. Reset Fitness Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                printf("Enter distance in meters: ");
                scanf("%lf", &distance);
                if(steps > MAX_STEPS || distance > MAX_DISTANCE) {
                    printf("Invalid input. Please enter valid values.\n");
                } else {
                    update_fitness_data(&data, steps, distance);
                    printf("Fitness data updated.\n");
                }
                break;
            case 2:
                print_fitness_data(&data);
                break;
            case 3:
                reset_fitness_data(&data);
                printf("Fitness data reset.\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}