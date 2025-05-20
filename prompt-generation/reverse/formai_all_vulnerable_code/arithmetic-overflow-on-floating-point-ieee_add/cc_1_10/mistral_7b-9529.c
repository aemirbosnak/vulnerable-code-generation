//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DAYS 30

typedef struct {
    int steps;
    double calories;
    double distance;
    double weight;
} Data;

void display_data(const Data *data) {
    printf("Steps: %d\n", data->steps);
    printf("Calories: %.2f\n", data->calories);
    printf("Distance: %.2f km\n", data->distance);
    printf("Weight: %.1f kg\n", data->weight);
}

int main() {
    Data data[MAX_DAYS];
    int current_day = 0;
    double base_calories = 1000.0;

    while (1) {
        printf("Day %d:\n", current_day + 1);
        Data *day_data = &data[current_day];

        printf("Enter number of steps: ");
        scanf("%d", &day_data->steps);

        day_data->calories = day_data->steps * 0.2;
        day_data->calories += base_calories;

        printf("Enter distance in km: ");
        scanf("%lf", &day_data->distance);
        day_data->distance *= 1000.0; // convert to meters
        day_data->distance = sqrt(day_data->steps * 0.000685); // convert to km

        printf("Enter weight in kg: ");
        scanf("%lf", &day_data->weight);
        day_data->calories += day_data->weight * 5; // calculate additional calories burned based on weight

        printf("\nDisplaying data for Day %d:\n", current_day + 1);
        display_data(day_data);

        printf("\nPress 's' to save and view past data, 'q' to quit: ");
        char option;
        scanf(" %c", &option);

        if (option == 's') {
            printf("Displaying past data:\n");
            for (int i = 0; i <= current_day; i++) {
                display_data(&data[i]);
                printf("\n");
            }
        } else if (option == 'q') {
            break;
        }

        current_day++;

        if (current_day >= MAX_DAYS) {
            printf("Error: Reached maximum number of days (%d).\n", MAX_DAYS);
            break;
        }
    }

    return 0;
}