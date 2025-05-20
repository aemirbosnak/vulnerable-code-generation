//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>

// struct to store fitness data
struct fitnessData {
    int steps;
    float distance;
    int caloriesBurned;
    int activeMinutes;
};

int main() {
    // initialize fitness data
    struct fitnessData data = {0};

    // loop to track fitness
    while (1) {
        // ask user for input
        printf("Enter the number of steps taken: ");
        scanf("%d", &data.steps);

        printf("Enter the distance covered (in meters): ");
        scanf("%f", &data.distance);

        printf("Enter the number of calories burned: ");
        scanf("%d", &data.caloriesBurned);

        printf("Enter the number of active minutes: ");
        scanf("%d", &data.activeMinutes);

        // calculate total calories burned
        float totalCaloriesBurned = data.caloriesBurned * data.activeMinutes;

        // calculate distance covered (in kilometers)
        float distanceInKm = data.distance / 1000;

        // display fitness data
        printf("\nFitness Data:\n");
        printf("Steps taken: %d\n", data.steps);
        printf("Distance covered: %0.2f km\n", distanceInKm);
        printf("Calories burned: %d\n", data.caloriesBurned);
        printf("Active minutes: %d\n", data.activeMinutes);
        printf("Total calories burned: %0.2f\n\n", totalCaloriesBurned);

        // ask user if they want to continue
        char choice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    return 0;
}