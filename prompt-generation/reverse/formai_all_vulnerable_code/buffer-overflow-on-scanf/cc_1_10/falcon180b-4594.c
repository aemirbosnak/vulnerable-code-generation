//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STEPS 100000
#define MAX_HEART_RATE 200

struct step_data {
    int steps;
    double distance;
    int calories_burned;
    int heart_rate;
};

struct fitness_data {
    int steps_taken;
    double distance_traveled;
    int calories_burned_total;
    double heart_rate_average;
};

void initialize_fitness_data(struct fitness_data *data) {
    data->steps_taken = 0;
    data->distance_traveled = 0;
    data->calories_burned_total = 0;
    data->heart_rate_average = 0;
}

void add_step_data(struct fitness_data *data, struct step_data step) {
    data->steps_taken++;
    data->distance_traveled += step.distance;
    data->calories_burned_total += step.calories_burned;
    data->heart_rate_average += step.heart_rate;
}

void display_fitness_data(struct fitness_data data) {
    printf("Steps taken: %d\n", data.steps_taken);
    printf("Distance traveled: %.2f km\n", data.distance_traveled / 1000);
    printf("Calories burned: %d\n", data.calories_burned_total);
    printf("Average heart rate: %.2f bpm\n", data.heart_rate_average / data.steps_taken);
}

struct step_data get_step_data() {
    struct step_data step;
    printf("Enter number of steps: ");
    scanf("%d", &step.steps);
    printf("Enter distance in meters: ");
    scanf("%lf", &step.distance);
    printf("Enter calories burned: ");
    scanf("%d", &step.calories_burned);
    printf("Enter heart rate: ");
    scanf("%d", &step.heart_rate);
    return step;
}

int main() {
    srand(time(NULL));
    struct fitness_data data;
    initialize_fitness_data(&data);

    int i;
    for (i = 0; i < MAX_STEPS; i++) {
        struct step_data step = get_step_data();
        if (step.steps > MAX_STEPS || step.distance > 100000 || step.calories_burned > 1000 || step.heart_rate > MAX_HEART_RATE) {
            printf("Invalid input. Please try again.\n");
            i--;
            continue;
        }
        add_step_data(&data, step);
    }

    display_fitness_data(data);

    return 0;
}