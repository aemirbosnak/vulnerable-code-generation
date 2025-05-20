//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DAYS 30
#define STEPS_PER_KM 1000
#define CALORIES_PER_KM 0.025

typedef struct {
    int steps;
    double distance;
    double calories;
} DayData;

DayData dailyData[MAX_DAYS];
int currentDay = 0;

void updateDailyData(int steps) {
    dailyData[currentDay].steps += steps;
    dailyData[currentDay].distance += dailyData[currentDay].steps * CALORIES_PER_KM;
    dailyData[currentDay].calories += steps * CALORIES_PER_KM;
}

void printCurrentDayData() {
    printf("\nDay %d:\n", currentDay + 1);
    printf("Steps: %d\n", dailyData[currentDay].steps);
    printf("Distance: %.2f km\n", dailyData[currentDay].distance / STEPS_PER_KM);
    printf("Calories: %.2f kcal\n", dailyData[currentDay].calories);
}

void printAllData() {
    printf("\nData for the last %d days:\n", MAX_DAYS);
    for (int i = 0; i < MAX_DAYS; i++) {
        if (i == currentDay) continue;
        printf("\nDay %d:\n", i + 1);
        printf("Steps: %d\n", dailyData[i].steps);
        printf("Distance: %.2f km\n", dailyData[i].distance / STEPS_PER_KM);
        printf("Calories: %.2f kcal\n", dailyData[i].calories);
    }
}

void saveDataToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i <= currentDay; i++) {
        fprintf(file, "Day %d: Steps: %d, Distance: %.2f km, Calories: %.2f kcal\n", i + 1, dailyData[i].steps, dailyData[i].distance / STEPS_PER_KM, dailyData[i].calories);
    }

    fclose(file);
}

int main() {
    int steps;

    while (1) {
        printf("Enter your daily steps: ");
        scanf("%d", &steps);

        updateDailyData(steps);
        currentDay = (currentDay + 1) % MAX_DAYS;

        printf("Do you want to print current day data (y/n)?\n");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            printCurrentDayData();
        }

        printf("Do you want to print all data (y/n)?\n");
        scanf("%c", &choice);

        if (choice == 'y') {
            printAllData();
        }

        if (choice == 's') {
            char filename[50];
            printf("Enter filename to save data: ");
            scanf("%s", filename);
            saveDataToFile(filename);
            printf("Data saved to file: %s\n", filename);
            break;
        }
    }

    return 0;
}