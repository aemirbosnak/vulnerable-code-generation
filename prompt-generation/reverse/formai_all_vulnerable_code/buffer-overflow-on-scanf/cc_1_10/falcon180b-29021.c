//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 10000

typedef struct {
    char name[50];
    int steps;
    int calories;
    time_t start_time;
    time_t end_time;
} fitness_data;

void add_data(fitness_data *data) {
    printf("Enter your name: ");
    scanf("%s", data->name);
    printf("Enter the number of steps: ");
    scanf("%d", &data->steps);
    printf("Enter the number of calories burned: ");
    scanf("%d", &data->calories);
    time(&data->start_time);
}

void display_data(fitness_data *data) {
    printf("%s took %d steps and burned %d calories in %ld seconds.\n", data->name, data->steps, data->calories, time(NULL) - data->start_time);
}

int main() {
    fitness_data data[MAX_STEPS];
    int num_entries = 0;

    while (num_entries < MAX_STEPS) {
        printf("Enter fitness data (or type 'quit' to exit):\n");
        if (scanf("%s", data[num_entries].name) == EOF) {
            break;
        }

        if (strcmp(data[num_entries].name, "quit") == 0) {
            break;
        }

        add_data(&data[num_entries]);
        num_entries++;
    }

    printf("Fitness data:\n");
    for (int i = 0; i < num_entries; i++) {
        display_data(&data[i]);
    }

    return 0;
}