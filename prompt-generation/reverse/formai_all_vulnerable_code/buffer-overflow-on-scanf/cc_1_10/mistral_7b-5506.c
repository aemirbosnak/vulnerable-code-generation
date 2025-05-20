//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#define MAX_DAYS 30
typedef struct {
    int steps;
    double distance;
    int calories;
} Activity;
void recordActivity(Activity* activity, int steps, double distance, int calories);
void displayStatistics(Activity activities[MAX_DAYS]);
int main() {
    Activity activities[MAX_DAYS];
    int day = 0;
    while (day < MAX_DAYS) {
        printf("Enter the number of steps you took today, Sherlock: ");
        int steps;
        scanf("%d", &steps);
        printf("Enter the distance you covered today in kilometers, Holmes: ");
        double distance;
        scanf("%lf", &distance);
        printf("Enter the number of calories you burned today, Watson: ");
        int calories;
        scanf("%d", &calories);
        recordActivity(&activities[day], steps, distance, calories);
        day++;
    }
    printf("\n statistics for the last 30 days:\n");
    displayStatistics(activities);
    return 0;
}
void recordActivity(Activity* activity, int steps, double distance, int calories) {
    activity->steps = steps;
    activity->distance = distance;
    activity->calories = calories;
}
void displayStatistics(Activity activities[MAX_DAYS]) {
    double totalSteps = 0;
    double totalDistance = 0;
    double totalCalories = 0;
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d:\n", i + 1);
        printf("Number of steps: %d\n", activities[i].steps);
        printf("Distance covered: %.2lf km\n", activities[i].distance);
        printf("Calories burned: %d\n", activities[i].calories);
        totalSteps += activities[i].steps;
        totalDistance += activities[i].distance;
        totalCalories += activities[i].calories;
    }
    printf("\nTotal number of steps for the last 30 days: %d\n", (int) totalSteps);
    printf("Total distance covered for the last 30 days: %.2lf km\n", totalDistance);
    printf("Total calories burned for the last 30 days: %d\n", (int) totalCalories);
}