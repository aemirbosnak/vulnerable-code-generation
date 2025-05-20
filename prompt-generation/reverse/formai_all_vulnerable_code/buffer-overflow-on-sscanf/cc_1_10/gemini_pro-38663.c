//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 10000
#define MAX_HEARTRATE 250
#define MAX_DISTANCE 100.0

typedef struct {
    int steps;
    int heartrate;
    double distance;
} fitness_data_t;

void print_fitness_data(fitness_data_t data) {
    printf("Steps: %d\n", data.steps);
    printf("Heartrate: %d bpm\n", data.heartrate);
    printf("Distance: %.2f km\n", data.distance);
}

int main() {
    fitness_data_t data;
    char input[100];

    printf("Welcome to the Fitness Tracker!\n");
    printf("Enter your steps, heartrate, and distance separated by commas: ");
    fgets(input, sizeof(input), stdin);

    sscanf(input, "%d,%d,%lf", &data.steps, &data.heartrate, &data.distance);

    if (data.steps > MAX_STEPS) {
        printf("Wow! You're a walking machine!\n");
    } else if (data.steps > 5000) {
        printf("Great job! You're on your way to a healthier lifestyle.\n");
    } else {
        printf("Keep up the good work! Every step counts.\n");
    }

    if (data.heartrate > MAX_HEARTRATE) {
        printf("Warning! Your heartrate is too high. Please consult a doctor.\n");
    } else if (data.heartrate > 120) {
        printf("Caution! Your heartrate is elevated. Please take a break.\n");
    } else {
        printf("Your heartrate is healthy. Keep up the good work!\n");
    }

    if (data.distance > MAX_DISTANCE) {
        printf("Amazing! You're a marathon runner in the making!\n");
    } else if (data.distance > 5.0) {
        printf("Well done! You're making great progress.\n");
    } else {
        printf("Good start! Keep up the momentum.\n");
    }

    print_fitness_data(data);

    return 0;
}