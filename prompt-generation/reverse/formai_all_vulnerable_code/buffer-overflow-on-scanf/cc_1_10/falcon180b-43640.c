//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24
#define STEPS_IN_METERS 0.762
#define CALORIES_PER_STEP 0.05

struct workout {
    char *name;
    double distance;
    double duration;
    int steps;
    int calories;
};

void print_workout(struct workout *workout) {
    printf("Name: %s\n", workout->name);
    printf("Distance: %.2f meters\n", workout->distance);
    printf("Duration: %.2f minutes\n", workout->duration);
    printf("Steps: %d\n", workout->steps);
    printf("Calories burned: %.2f\n\n", workout->calories);
}

struct workout create_workout(char *name, double distance, double duration) {
    struct workout workout;
    workout.name = name;
    workout.distance = distance;
    workout.duration = duration;
    workout.steps = (int) (distance / STEPS_IN_METERS);
    workout.calories = (int) (workout.steps * CALORIES_PER_STEP);
    return workout;
}

int main() {
    struct workout *workouts = NULL;
    int num_workouts = 0;
    char input[100];

    while (1) {
        printf("Enter a workout (name distance duration): ");
        scanf("%s", input);

        char *name = strtok(input, " ");
        double distance = atof(strtok(NULL, " "));
        double duration = atof(strtok(NULL, " "));

        if (name == NULL || distance == 0 || duration == 0) {
            printf("Invalid input.\n");
            continue;
        }

        struct workout workout = create_workout(name, distance, duration);
        workouts = realloc(workouts, sizeof(struct workout) * ++num_workouts);
        workouts[num_workouts - 1] = workout;

        printf("Workout added:\n");
        print_workout(&workouts[num_workouts - 1]);
    }

    return 0;
}