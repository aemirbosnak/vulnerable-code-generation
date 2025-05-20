//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    int steps;
    float distance; // in kilometers
    int calories;
} ActivityLog;

ActivityLog logs[MAX_ENTRIES];
int logCount = 0;

void addEntry() {
    if (logCount >= MAX_ENTRIES) {
        printf("Log is full! Can't add more entries.\n");
        return;
    }
    ActivityLog newLog;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newLog.date);
    printf("Enter steps taken: ");
    scanf("%d", &newLog.steps);
    printf("Enter distance traveled (km): ");
    scanf("%f", &newLog.distance);
    printf("Enter calories burned: ");
    scanf("%d", &newLog.calories);

    logs[logCount++] = newLog;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (logCount == 0) {
        printf("No entries to display.\n");
        return;
    }
    printf("Date        | Steps | Distance (km) | Calories\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        printf("%s | %d    | %.2f          | %d\n", logs[i].date, logs[i].steps, logs[i].distance, logs[i].calories);
    }
}

void analyzeData() {
    if (logCount == 0) {
        printf("No data to analyze.\n");
        return;
    }
    int totalSteps = 0, totalCalories = 0;
    float totalDistance = 0.0;

    for (int i = 0; i < logCount; i++) {
        totalSteps += logs[i].steps;
        totalDistance += logs[i].distance;
        totalCalories += logs[i].calories;
    }
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void menu() {
    printf("\nC Fitness Tracker\n");
    printf("-----------------\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Analyze Data\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                analyzeData();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 4);
    return 0;
}