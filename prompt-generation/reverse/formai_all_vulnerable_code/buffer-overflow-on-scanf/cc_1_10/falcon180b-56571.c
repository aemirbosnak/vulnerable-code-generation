//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 10000 // Maximum number of steps to track
#define MAX_DISTANCE 10000 // Maximum distance to track (in meters)
#define MAX_CALORIES 10000 // Maximum calories to track

struct step {
    int count;
    time_t timestamp;
};

struct fitness_data {
    int steps;
    int distance;
    int calories;
};

void init_fitness_data(struct fitness_data* data) {
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
}

void add_step(struct fitness_data* data) {
    data->steps++;
}

void add_distance(struct fitness_data* data, int meters) {
    data->distance += meters;
}

void add_calories(struct fitness_data* data, int calories) {
    data->calories += calories;
}

int main() {
    struct fitness_data data;
    init_fitness_data(&data);

    int choice;
    do {
        printf("Fitness Tracker Menu:\n");
        printf("1. Add step\n");
        printf("2. Add distance (in meters)\n");
        printf("3. Add calories\n");
        printf("4. View fitness data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_step(&data);
                printf("Step added.\n");
                break;
            case 2:
                printf("Enter distance (in meters): ");
                int distance;
                scanf("%d", &distance);
                add_distance(&data, distance);
                printf("Distance added.\n");
                break;
            case 3:
                printf("Enter calories: ");
                int calories;
                scanf("%d", &calories);
                add_calories(&data, calories);
                printf("Calories added.\n");
                break;
            case 4:
                printf("Steps: %d\n", data.steps);
                printf("Distance: %d meters\n", data.distance);
                printf("Calories: %d\n", data.calories);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);

    return 0;
}