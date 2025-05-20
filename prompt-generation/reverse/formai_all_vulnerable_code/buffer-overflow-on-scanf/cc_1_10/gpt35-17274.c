//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct fitnessData {
    float weight;
    int steps;
    float caloriesBurned;
};

int main() {
    int currentDay = 1;
    struct fitnessData weekData[7]; // for 7 days of the week
    srand(time(NULL)); // for random data

    // loop to collect data for a week
    while (currentDay <= 7) {
        printf("\nDay %d\n", currentDay);

        // collect weight data
        printf("Enter your weight for the day (kg): ");
        scanf("%f", &weekData[currentDay-1].weight);

        // collect step data
        printf("Enter the steps taken for the day: ");
        scanf("%d", &weekData[currentDay-1].steps);

        // calculate calories burned with a random factor
        float calories = weekData[currentDay-1].steps / 20.0;
        calories *= (rand() % 30 + 70) / 100.0;
        weekData[currentDay-1].caloriesBurned = calories;

        currentDay++;
    }

    // print the data for the week
    printf("\nWeek's Data:\n");
    printf("Day | Weight | Steps | Calories Burned\n");
    for (int i = 0; i < 7; i++) {
        printf("%d | %.2f | %d | %.2f\n", i+1, weekData[i].weight, weekData[i].steps, weekData[i].caloriesBurned);
    }

    // calculate weekly averages
    float totalWeight = 0, totalSteps = 0, totalCalories = 0;
    for (int i = 0; i < 7; i++) {
        totalWeight += weekData[i].weight;
        totalSteps += weekData[i].steps;
        totalCalories += weekData[i].caloriesBurned;
    }
    float weightAvg = totalWeight / 7.0;
    float stepsAvg = totalSteps / 7.0;
    float caloriesAvg = totalCalories / 7.0;

    printf("\nWeekly Averages:\n");
    printf("Weight: %.2f kg\n", weightAvg);
    printf("Steps: %.2f\n", stepsAvg);
    printf("Calories Burned: %.2f\n", caloriesAvg);

    return 0;
}