//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MIN_VALUE 0.0

struct point {
    double x;
    double y;
};

struct fitness_data {
    int steps;
    double distance;
    double speed;
    double calories;
};

void get_steps(struct fitness_data *data) {
    printf("Enter number of steps: ");
    scanf("%d", &data->steps);
}

void calculate_distance(struct fitness_data *data) {
    data->distance = data->steps * 0.762;
}

void calculate_speed(struct fitness_data *data) {
    data->speed = data->distance / (double)data->steps;
}

void calculate_calories(struct fitness_data *data) {
    data->calories = (data->steps * 0.0175) * data->distance;
}

void display_fitness_data(struct fitness_data *data) {
    printf("\nFitness Data:\n");
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2f km\n", data->distance);
    printf("Speed: %.2f km/h\n", data->speed);
    printf("Calories burned: %.2f kcal\n", data->calories);
}

int main() {
    struct fitness_data data;
    get_steps(&data);
    calculate_distance(&data);
    calculate_speed(&data);
    calculate_calories(&data);
    display_fitness_data(&data);
    return 0;
}