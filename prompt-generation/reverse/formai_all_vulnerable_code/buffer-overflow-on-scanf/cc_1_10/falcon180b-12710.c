//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int steps;
    int distance;
    int calories;
    struct tm last_update;
} fitness_data;

fitness_data *create_fitness_data(char *name) {
    fitness_data *data = (fitness_data *)malloc(sizeof(fitness_data));
    data->name = name;
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
    time_t now = time(NULL);
    localtime_r(&now, &data->last_update);
    return data;
}

void update_fitness_data(fitness_data *data, int steps, int distance, int calories) {
    data->steps += steps;
    data->distance += distance;
    data->calories += calories;
    time_t now = time(NULL);
    localtime_r(&now, &data->last_update);
}

void print_fitness_data(fitness_data *data) {
    printf("Name: %s\n", data->name);
    printf("Steps: %d\n", data->steps);
    printf("Distance: %d\n", data->distance);
    printf("Calories: %d\n", data->calories);
    printf("Last Update: %s", asctime(&data->last_update));
}

int main() {
    fitness_data *user_data = create_fitness_data("John Doe");
    int steps, distance, calories;

    while (1) {
        printf("Enter steps taken: ");
        scanf("%d", &steps);
        printf("Enter distance traveled (in meters): ");
        scanf("%d", &distance);
        printf("Enter calories burned: ");
        scanf("%d", &calories);

        update_fitness_data(user_data, steps, distance, calories);

        printf("\nCurrent Fitness Data:\n");
        print_fitness_data(user_data);
        printf("\n");
    }

    return 0;
}