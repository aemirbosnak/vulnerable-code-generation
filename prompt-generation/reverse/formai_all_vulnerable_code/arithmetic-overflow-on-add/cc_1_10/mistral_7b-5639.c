//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 100000
#define CALORIES_PER_STEP 0.1697
#define MINUTES_PER_HOUR 60

typedef struct {
    int steps;
    int calories;
    int time_spent_minutes;
} FitnessTracker;

void print_stats(FitnessTracker tracker) {
    double avg_calories_per_pound;
    int total_calories = tracker.calories;
    int total_weight;

    printf("\n--- Statistics ---\n");
    printf("Total steps: %d\n", tracker.steps);
    printf("Total calories burned: %d\n", total_calories);
    printf("Calories burned per minute: %.2f\n", (float)total_calories / (float)tracker.time_spent_minutes);

    printf("Enter your weight in pounds: ");
    scanf("%d", &total_weight);

    avg_calories_per_pound = (double)total_calories / (double)total_weight;
    printf("Average calories burned per pound: %.2f\n", avg_calories_per_pound);
}

int main() {
    FitnessTracker tracker = {0};
    int choice;
    clock_t start, end;

    do {
        printf("\n--- Fitness Tracker ---\n");
        printf("1. Record step count and calories burned during exercise.\n");
        printf("2. View statistics.\n");
        printf("3. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of steps taken: ");
                scanf("%d", &tracker.steps);
                printf("Enter number of minutes spent exercising: ");
                scanf("%d", &tracker.time_spent_minutes);
                start = clock();
                tracker.calories = tracker.steps * CALORIES_PER_STEP;
                end = clock();
                tracker.time_spent_minutes += (int)((end - start) / CLOCKS_PER_SEC);
                break;
            case 2:
                print_stats(tracker);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3 && tracker.steps < MAX_STEPS);

    return 0;
}