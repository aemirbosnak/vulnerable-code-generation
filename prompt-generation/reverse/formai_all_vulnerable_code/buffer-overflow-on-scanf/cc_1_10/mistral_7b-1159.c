//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DAYS 7

typedef struct {
    int steps;
    int calories;
    double distance;
} DayData;

DayData dailyData[MAX_DAYS];
int currentDay = 0;

void initializeData() {
    for (int i = 0; i < MAX_DAYS; i++) {
        dailyData[i].steps = 0;
        dailyData[i].calories = 0;
        dailyData[i].distance = 0;
    }
}

void updateData(int steps, int calories) {
    dailyData[currentDay].steps += steps;
    dailyData[currentDay].calories += calories;

    dailyData[currentDay].distance += steps * 0.005286; // 1 step = 0.005286 miles

    currentDay = (currentDay + 1) % MAX_DAYS;
}

void displayProgress() {
    printf("Progress over the last 7 days:\n");

    for (int i = 0; i < MAX_DAYS; i++) {
        printf("Day %d: %d steps, %d calories, %.2f miles\n", i, dailyData[i].steps, dailyData[i].calories, dailyData[i].distance);
    }
}

int main() {
    int choice;

    initializeData();

    while (1) {
        printf("\nFitness Tracker\n");
        printf("1. Record new data\n");
        printf("2. Display progress\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int steps, calories;
                printf("Enter steps taken: ");
                scanf("%d", &steps);
                printf("Enter calories burned: ");
                scanf("%d", &calories);

                updateData(steps, calories);
                break;
            }
            case 2: {
                displayProgress();
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}