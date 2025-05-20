//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    int steps;
    double distance;
    double calories;
    double time;
} fitness_data;

void initialize_fitness_data(fitness_data *data) {
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
    data->time = 0;
}

void update_fitness_data(fitness_data *data, int steps, double distance, double calories, double time) {
    data->steps += steps;
    data->distance += distance;
    data->calories += calories;
    data->time += time;
}

void print_fitness_data(fitness_data *data) {
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2f km\n", data->distance / 1000);
    printf("Calories burned: %.2f\n", data->calories);
    printf("Time: %.2f minutes\n", data->time / 60);
}

int main() {
    fitness_data user_data;
    initialize_fitness_data(&user_data);

    int choice;
    do {
        printf("Fitness Tracker Menu:\n");
        printf("1. Record a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of steps taken: ");
                int steps;
                scanf("%d", &steps);

                printf("Enter the distance covered in km: ");
                double distance;
                scanf("%lf", &distance);

                printf("Enter the number of calories burned: ");
                double calories;
                scanf("%lf", &calories);

                printf("Enter the duration of the workout in minutes: ");
                double time;
                scanf("%lf", &time);

                update_fitness_data(&user_data, steps, distance, calories, time);
                break;

            case 2:
                print_fitness_data(&user_data);
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