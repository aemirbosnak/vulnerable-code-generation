//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int steps;
    int distance;
    int calories;
    int heart_rate;
    time_t timestamp;
} fitness_data;

void print_fitness_data(fitness_data data) {
    printf("Steps: %d\n", data.steps);
    printf("Distance: %d\n", data.distance);
    printf("Calories: %d\n", data.calories);
    printf("Heart Rate: %d\n", data.heart_rate);
    printf("Timestamp: %s\n", ctime(&data.timestamp));
}

void add_steps(fitness_data *data, int steps) {
    data->steps += steps;
    data->distance += steps * 0.8; // Assume each step is 0.8 meters
    data->calories += steps * 0.1; // Assume each step burns 0.1 calories
    data->heart_rate = (int) round(220 - (data->calories / 5));
    data->timestamp = time(NULL);
}

int main() {
    fitness_data fitness_data = {0};
    int choice;
    do {
        printf("Fitness Tracker Menu:\n");
        printf("1. Add Steps\n");
        printf("2. View Fitness Data\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int steps;
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                add_steps(&fitness_data, steps);
                break;
            }
            case 2: {
                print_fitness_data(fitness_data);
                break;
            }
            case 3: {
                printf("Exiting Fitness Tracker...\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again.\n");
            }
        }
    } while (choice!= 3);
    return 0;
}