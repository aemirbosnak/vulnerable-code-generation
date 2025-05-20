//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

struct fitness_data {
    int heart_rate;
    int steps;
    int calories_burned;
    int distance_traveled;
    int sleep_duration;
};

void print_fitness_data(struct fitness_data data) {
    printf("Heart Rate: %d\n", data.heart_rate);
    printf("Steps: %d\n", data.steps);
    printf("Calories Burned: %d\n", data.calories_burned);
    printf("Distance Traveled: %d meters\n", data.distance_traveled);
    printf("Sleep Duration: %d hours\n", data.sleep_duration);
}

void calculate_fitness_data(struct fitness_data *data) {
    data->heart_rate = rand() % 100;
    data->steps = rand() % 10000;
    data->calories_burned = (data->steps / 100) * (data->heart_rate / 100);
    data->distance_traveled = data->steps * 0.762;
    data->sleep_duration = rand() % 12;
}

int main() {
    srand(time(NULL));
    struct fitness_data fitness_data;
    int choice;

    do {
        printf("Fitness Tracker\n");
        printf("1. View Fitness Data\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_fitness_data(&fitness_data);
                print_fitness_data(fitness_data);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}