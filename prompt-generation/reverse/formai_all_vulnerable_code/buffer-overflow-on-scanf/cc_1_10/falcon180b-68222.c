//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FITNESS_ACTIVITIES 10

typedef struct {
    char name[50];
    int duration;
    int calories_burned;
} fitness_activity;

void add_fitness_activity(fitness_activity* activities, int count, char name[], int duration, int calories_burned) {
    if (count >= MAX_FITNESS_ACTIVITIES) {
        printf("Error: Maximum fitness activities reached.\n");
        return;
    }

    strcpy(activities[count].name, name);
    activities[count].duration = duration;
    activities[count].calories_burned = calories_burned;

    printf("Fitness activity added successfully.\n");
}

void display_fitness_activities(fitness_activity* activities, int count) {
    printf("Fitness activities:\n");

    for (int i = 0; i < count; i++) {
        printf("%s - Duration: %d minutes - Calories burned: %d\n", activities[i].name, activities[i].duration, activities[i].calories_burned);
    }
}

int main() {
    fitness_activity activities[MAX_FITNESS_ACTIVITIES];
    int count = 0;

    while (count < MAX_FITNESS_ACTIVITIES) {
        printf("Enter fitness activity name: ");
        scanf("%s", activities[count].name);

        printf("Enter duration (in minutes): ");
        scanf("%d", &activities[count].duration);

        printf("Enter calories burned: ");
        scanf("%d", &activities[count].calories_burned);

        count++;
    }

    printf("\nFitness activities added successfully.\n");

    printf("Fitness activities:\n");
    display_fitness_activities(activities, count);

    return 0;
}