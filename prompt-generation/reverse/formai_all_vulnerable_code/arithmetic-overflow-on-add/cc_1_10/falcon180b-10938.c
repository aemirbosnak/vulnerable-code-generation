//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int steps;
    int calories;
    int distance;
    struct tm last_updated;
} fitness_data;

void add_step(fitness_data *data) {
    data->steps++;
    data->calories += 10;
    data->distance += 0.1;
    time_t now = time(NULL);
    localtime_r(&now, &data->last_updated);
}

void print_data(fitness_data *data) {
    printf("Name: %s\n", data->name);
    printf("Steps: %d\n", data->steps);
    printf("Calories burned: %d\n", data->calories);
    printf("Distance traveled: %.2f km\n", data->distance);
    printf("Last updated: %s", asctime(&data->last_updated));
}

int main() {
    fitness_data user_data;

    printf("Enter your name: ");
    scanf("%s", user_data.name);

    while(1) {
        int choice;
        printf("\n1. Add step\n2. Print data\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_step(&user_data);
                break;
            case 2:
                print_data(&user_data);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}