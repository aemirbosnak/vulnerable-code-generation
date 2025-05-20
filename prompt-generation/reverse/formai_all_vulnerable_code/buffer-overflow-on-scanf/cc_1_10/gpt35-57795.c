//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <string.h>

struct workout {
    char name[50];
    float calories_burnt;
    int duration;
};

int main() {
    struct workout workouts[5];
    int i;

    // User input for each workout
    for (i = 0; i < 5; i++) {
        printf("Enter workout name: ");
        fgets(workouts[i].name, sizeof(workouts[i].name), stdin);

        printf("Enter calories burnt: ");
        scanf("%f", &workouts[i].calories_burnt);

        printf("Enter duration: ");
        scanf("%d", &workouts[i].duration);

        // Clear input buffer to avoid any issues with fgets
        while ((getchar()) != '\n');
    }

    // Calculate total calories burnt and total duration
    float total_calories = 0;
    int total_duration = 0;

    for (i = 0; i < 5; i++) {
        total_calories += workouts[i].calories_burnt;
        total_duration += workouts[i].duration;
    }

    // Calculate average calories burnt and average duration
    float average_calories = total_calories / 5;
    float average_duration = (float) total_duration / 5;

    // Print summary
    printf("\nYour workout summary:\n\n");

    for (i = 0; i < 5; i++) {
        printf("Workout %d: %s\n", i+1, workouts[i].name);
        printf("Calories burnt: %.2f\n", workouts[i].calories_burnt);
        printf("Duration: %d minutes\n\n", workouts[i].duration);
    }

    printf("Total calories burnt: %.2f\n", total_calories);
    printf("Average calories burnt per workout: %.2f\n", average_calories);
    printf("Total duration: %d minutes\n", total_duration);
    printf("Average duration per workout: %.2f minutes\n", average_duration);

    return 0;
}