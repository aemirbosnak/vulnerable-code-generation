//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct FitnessTracker {
    int steps;
    double calories;
    double distance;
    double heart_rate;
};

int main() {
    struct FitnessTracker tracker;
    tracker.steps = 0;
    tracker.calories = 0;
    tracker.distance = 0;
    tracker.heart_rate = 0;

    printf("Welcome to the Fitness Tracker app!\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add Steps\n");
        printf("2. Update Heart Rate\n");
        printf("3. Calculate Calories Burned\n");
        printf("4. Calculate Distance Traveled\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of steps taken: ");
                int steps;
                scanf("%d", &steps);
                tracker.steps += steps;
                printf("%d steps added!\n", steps);
                break;

            case 2:
                printf("Enter heart rate: ");
                double heart_rate;
                scanf("%lf", &heart_rate);
                tracker.heart_rate = heart_rate;
                printf("Heart rate updated!\n");
                break;

            case 3: 
                tracker.calories = tracker.steps * 0.05;
                printf("Calories burned: %.2lf\n", tracker.calories);
                break;

            case 4:
                tracker.distance = (double)tracker.steps / 2100.0;
                printf("Distance traveled: %.2lf miles\n", tracker.distance);
                break;

            case 5:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option, please select again.\n");
        }
    }

    return 0;
}