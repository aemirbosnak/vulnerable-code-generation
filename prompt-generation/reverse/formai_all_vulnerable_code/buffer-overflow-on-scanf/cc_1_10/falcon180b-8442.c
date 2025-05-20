//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 1000

struct step {
    int count;
    double distance;
    double calories;
};

int main() {
    struct step steps[MAX_STEPS];
    int step_count = 0;
    double total_distance = 0;
    double total_calories = 0;

    while (1) {
        printf("Enter your step count for the day (0 to stop): ");
        scanf("%d", &steps[step_count].count);

        if (steps[step_count].count == 0) {
            break;
        }

        printf("Enter the distance covered for these steps: ");
        scanf("%lf", &steps[step_count].distance);

        printf("Enter the number of calories burned for these steps: ");
        scanf("%lf", &steps[step_count].calories);

        total_distance += steps[step_count].distance;
        total_calories += steps[step_count].calories;

        step_count++;

        if (step_count >= MAX_STEPS) {
            printf("Error: Maximum number of steps reached.\n");
            exit(1);
        }
    }

    printf("\nTotal steps taken: %d\n", step_count);
    printf("Total distance covered: %.2lf km\n", total_distance);
    printf("Total calories burned: %.2lf kcal\n", total_calories);

    return 0;
}