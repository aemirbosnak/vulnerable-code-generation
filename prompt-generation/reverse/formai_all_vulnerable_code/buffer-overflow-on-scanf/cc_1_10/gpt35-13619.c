//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 5

struct workout {
    char name[20];
    int duration;
    double calories;
};

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    srand(time(0));

    printf("*** Welcome to Fitness Tracker ***\n");
    printf("Enter your workout details or 'done' to finish.\n");

    while (num_workouts < MAX_WORKOUTS) {
        struct workout w;
        printf("Workout name: ");
        scanf("%19s", w.name);

        if (strcmp(w.name, "done") == 0) {
            break;
        }

        printf("Workout duration (in minutes): ");
        scanf("%d", &w.duration);

        w.calories = (double)rand() / RAND_MAX * 200;

        workouts[num_workouts] = w;
        num_workouts++;
    }

    printf("\n\n*** Your Workouts ***\n");
    printf("%-20s %-10s %-10s\n", "Name", "Duration", "Calories");

    for (int i = 0; i < num_workouts; i++) {
        struct workout w = workouts[i];
        printf("%-20s %-10d %.2lf\n", w.name, w.duration, w.calories);
    }

    printf("\n");
    return 0;
}