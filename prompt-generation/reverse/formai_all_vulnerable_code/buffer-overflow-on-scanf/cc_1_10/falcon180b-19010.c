//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60

struct workout {
    char name[50];
    int duration;
    int calories;
};

struct fitness_data {
    int steps;
    int distance;
    int calories_burned;
    struct workout workouts[DAYS_IN_WEEK];
};

void print_workout(struct workout w) {
    printf("Workout Name: %s\n", w.name);
    printf("Duration (in seconds): %d\n", w.duration);
    printf("Calories burned: %d\n", w.calories);
}

void print_fitness_data(struct fitness_data f) {
    printf("Steps taken: %d\n", f.steps);
    printf("Distance covered (in meters): %d\n", f.distance);
    printf("Calories burned: %d\n", f.calories_burned);
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        printf("Workout on day %d:\n", i+1);
        print_workout(f.workouts[i]);
    }
}

int main() {
    struct fitness_data data;
    int choice;

    // Initialize fitness data
    data.steps = 0;
    data.distance = 0;
    data.calories_burned = 0;
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        data.workouts[i].duration = 0;
        data.workouts[i].calories = 0;
        strcpy(data.workouts[i].name, "");
    }

    // Main menu
    while (1) {
        printf("\nFitness Tracker\n");
        printf("1. Enter steps taken\n");
        printf("2. Enter distance covered (in meters)\n");
        printf("3. Enter calories burned\n");
        printf("4. Add a workout\n");
        printf("5. View fitness data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter steps taken: ");
                scanf("%d", &data.steps);
                break;
            case 2:
                printf("Enter distance covered (in meters): ");
                scanf("%d", &data.distance);
                break;
            case 3:
                printf("Enter calories burned: ");
                scanf("%d", &data.calories_burned);
                break;
            case 4:
                printf("Enter workout name: ");
                scanf("%s", data.workouts[0].name);
                printf("Enter workout duration (in seconds): ");
                scanf("%d", &data.workouts[0].duration);
                printf("Enter calories burned: ");
                scanf("%d", &data.workouts[0].calories);
                break;
            case 5:
                print_fitness_data(data);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}