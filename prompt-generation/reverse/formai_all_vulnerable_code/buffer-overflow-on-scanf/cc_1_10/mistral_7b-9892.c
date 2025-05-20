//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define WEEK_SIZE 7

typedef struct {
    int steps;
    double distance;
    double calories;
    double weight;
} DailyStats;

void initializeDailyStats(DailyStats *dailyStats) {
    dailyStats->steps = 0;
    dailyStats->distance = 0.0;
    dailyStats->calories = 0.0;
    dailyStats->weight = 0.0;
}

void updateDailyStats(DailyStats *dailyStats, int steps, double distance, double calories, double weight) {
    dailyStats->steps += steps;
    dailyStats->distance += distance;
    dailyStats->calories += calories;
    dailyStats->weight = weight;
}

void calculateAverageStats(DailyStats weeklyStats[WEEK_SIZE], double *avgSteps, double *avgDistance, double *avgCalories) {
    double totalSteps = 0.0;
    double totalDistance = 0.0;
    double totalCalories = 0.0;

    for (int i = 0; i < WEEK_SIZE; i++) {
        totalSteps += weeklyStats[i].steps;
        totalDistance += weeklyStats[i].distance;
        totalCalories += weeklyStats[i].calories;
    }

    *avgSteps = totalSteps / WEEK_SIZE;
    *avgDistance = totalDistance / WEEK_SIZE;
    *avgCalories = totalCalories / WEEK_SIZE;
}

int main() {
    DailyStats dailyStats[7];
    int steps;
    double distance;
    double calories;
    double weight;

    for (int day = 0; day < WEEK_SIZE; day++) {
        initializeDailyStats(&dailyStats[day]);
        printf("Enter steps for day %d: ", day + 1);
        scanf("%d", &steps);

        printf("Enter distance (in kilometers) for day %d: ", day + 1);
        scanf("%lf", &distance);

        printf("Enter calories burned for day %d: ", day + 1);
        scanf("%lf", &calories);

        printf("Enter weight (in kilograms) for day %d: ", day + 1);
        scanf("%lf", &weight);

        updateDailyStats(&dailyStats[day], steps, distance, calories, weight);
    }

    DailyStats weeklyStats[WEEK_SIZE];
    double avgSteps, avgDistance, avgCalories;

    for (int day = 0; day < WEEK_SIZE; day++) {
        weeklyStats[day] = dailyStats[day];
    }

    calculateAverageStats(weeklyStats, &avgSteps, &avgDistance, &avgCalories);

    printf("\nWeekly Stats:\n");
    printf("Average daily steps: %.2f\n", avgSteps);
    printf("Average daily distance: %.2f km\n", avgDistance);
    printf("Average daily calories burned: %.2f kcal\n", avgCalories * 1000);

    return 0;
}