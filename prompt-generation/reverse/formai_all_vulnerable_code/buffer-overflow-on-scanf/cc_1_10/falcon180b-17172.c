//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000
#define MAX_HEARTRATE 200

struct fitness_data {
    int steps;
    double distance;
    int calories;
    int heartrate;
};

void init_fitness_data(struct fitness_data *data) {
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
    data->heartrate = 0;
}

void track_step(struct fitness_data *data) {
    data->steps++;
}

void track_distance(struct fitness_data *data, double distance) {
    data->distance += distance;
}

void track_calories(struct fitness_data *data, int calories) {
    data->calories += calories;
}

void track_heartrate(struct fitness_data *data, int heartrate) {
    data->heartrate = heartrate;
}

void print_fitness_data(struct fitness_data *data) {
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2f km\n", data->distance / 100);
    printf("Calories burned: %d\n", data->calories);
    printf("Average heart rate: %d bpm\n", data->heartrate);
}

int main() {
    struct fitness_data data;
    init_fitness_data(&data);

    int choice;
    do {
        printf("Fitness Tracker Menu:\n");
        printf("1. Track steps\n");
        printf("2. Track distance\n");
        printf("3. Track calories burned\n");
        printf("4. Track heart rate\n");
        printf("5. Print fitness data\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                track_step(&data);
                break;
            case 2:
                printf("Enter distance in meters: ");
                double distance;
                scanf("%lf", &distance);
                track_distance(&data, distance);
                break;
            case 3:
                printf("Enter calories burned: ");
                int calories;
                scanf("%d", &calories);
                track_calories(&data, calories);
                break;
            case 4:
                printf("Enter heart rate: ");
                int heartrate;
                scanf("%d", &heartrate);
                track_heartrate(&data, heartrate);
                break;
            case 5:
                print_fitness_data(&data);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 6);

    return 0;
}