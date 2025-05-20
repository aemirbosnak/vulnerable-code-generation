//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    char name[20];
    int steps;
    int calories;
    int distance;
} fitness_data;

void init_fitness_data(fitness_data* fit) {
    strcpy(fit->name, "unknown");
    fit->steps = 0;
    fit->calories = 0;
    fit->distance = 0;
}

void print_fitness_data(fitness_data* fit) {
    printf("name: %s\n", fit->name);
    printf("steps: %d\n", fit->steps);
    printf("calories: %d\n", fit->calories);
    printf("distance: %d\n", fit->distance);
}

void update_fitness_data(fitness_data* fit, int steps, int calories, int distance) {
    fit->steps += steps;
    fit->calories += calories;
    fit->distance += distance;
}

int main() {
    fitness_data fit;
    init_fitness_data(&fit);

    int choice;
    while(1) {
        printf("fitness tracker\n");
        printf("1. update fitness data\n");
        printf("2. print fitness data\n");
        printf("3. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("enter number of steps: ");
                scanf("%d", &fit.steps);
                printf("enter number of calories burned: ");
                scanf("%d", &fit.calories);
                printf("enter distance covered in kilometers: ");
                scanf("%d", &fit.distance);
                printf("fitness data updated!\n");
                break;
            case 2:
                print_fitness_data(&fit);
                break;
            case 3:
                exit(0);
            default:
                printf("invalid choice. please try again.\n");
        }
    }

    return 0;
}