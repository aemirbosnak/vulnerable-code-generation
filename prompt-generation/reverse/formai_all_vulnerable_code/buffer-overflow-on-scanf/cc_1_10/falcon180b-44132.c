//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STEPS 5000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 5000
#define MAX_TIME 86400

typedef struct {
    int steps;
    double distance;
    int calories;
    int time;
} fitness_data;

void init_fitness_data(fitness_data *data) {
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
    data->time = 0;
}

void update_fitness_data(fitness_data *data, int steps, double distance, int calories, int time) {
    data->steps += steps;
    data->distance += distance;
    data->calories += calories;
    data->time += time;
}

void print_fitness_data(fitness_data *data) {
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2f km\n", data->distance / 1000);
    printf("Calories: %d\n", data->calories);
    printf("Time: %d seconds\n", data->time);
}

int main() {
    fitness_data user_data;
    init_fitness_data(&user_data);

    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Add steps\n");
        printf("2. Add distance\n");
        printf("3. Add calories\n");
        printf("4. Add time\n");
        printf("5. Print fitness data\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of steps: ");
            scanf("%d", &user_data.steps);
            break;
        case 2:
            printf("Enter distance in meters: ");
            scanf("%lf", &user_data.distance);
            break;
        case 3:
            printf("Enter calories burned: ");
            scanf("%d", &user_data.calories);
            break;
        case 4:
            printf("Enter time in seconds: ");
            scanf("%d", &user_data.time);
            break;
        case 5:
            print_fitness_data(&user_data);
            break;
        case 6:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}