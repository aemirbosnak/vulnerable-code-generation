//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 30

void inputActivityData(int steps[], int calories[], int activeMinutes[], int days);
void calculateStats(int steps[], int calories[], int activeMinutes[], int days);
void displayStats(int totalSteps, int totalCalories, int totalActiveMinutes, int days);
float calculateAverage(int total, int days);

int main() {
    int steps[MAX_DAYS] = {0};
    int calories[MAX_DAYS] = {0};
    int activeMinutes[MAX_DAYS] = {0};
    
    int days;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Enter the number of days (up to %d): ", MAX_DAYS);
    scanf("%d", &days);
    
    // Ensure that the number of days does not exceed MAX_DAYS
    if (days < 1 || days > MAX_DAYS) {
        printf("Invalid number of days. Please enter a value between 1 and %d.\n", MAX_DAYS);
        return 1;
    }

    inputActivityData(steps, calories, activeMinutes, days);
    calculateStats(steps, calories, activeMinutes, days);
    
    return 0;
}

void inputActivityData(int steps[], int calories[], int activeMinutes[], int days) {
    for (int i = 0; i < days; i++) {
        printf("Day %d:\n", i + 1);
        printf("Enter steps taken: ");
        scanf("%d", &steps[i]);
        printf("Enter calories burned: ");
        scanf("%d", &calories[i]);
        printf("Enter active minutes: ");
        scanf("%d", &activeMinutes[i]);
    }
}

void calculateStats(int steps[], int calories[], int activeMinutes[], int days) {
    int totalSteps = 0, totalCalories = 0, totalActiveMinutes = 0;
    int maxSteps = 0, minSteps = 1000000; // Assume a high value for min initialization

    for (int i = 0; i < days; i++) {
        totalSteps += steps[i];
        totalCalories += calories[i];
        totalActiveMinutes += activeMinutes[i];
        
        if (steps[i] > maxSteps) {
            maxSteps = steps[i];
        }
        if (steps[i] < minSteps) {
            minSteps = steps[i];
        }
    }

    displayStats(totalSteps, totalCalories, totalActiveMinutes, days);
    printf("Maximum steps in a single day: %d\n", maxSteps);
    printf("Minimum steps in a single day: %d\n", minSteps);
}

void displayStats(int totalSteps, int totalCalories, int totalActiveMinutes, int days) {
    printf("\n--- Fitness Stats ---\n");
    printf("Total steps taken: %d\n", totalSteps);
    printf("Total calories burned: %d\n", totalCalories);
    printf("Total active minutes: %d\n", totalActiveMinutes);
    
    float avgSteps = calculateAverage(totalSteps, days);
    float avgCalories = calculateAverage(totalCalories, days);
    float avgActiveMinutes = calculateAverage(totalActiveMinutes, days);
    
    printf("Average steps per day: %.2f\n", avgSteps);
    printf("Average calories burned per day: %.2f\n", avgCalories);
    printf("Average active minutes per day: %.2f\n", avgActiveMinutes);
}

float calculateAverage(int total, int days) {
    return (float)total / days;
}