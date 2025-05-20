//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // YYYY-MM-DD
    float distance; // in kilometers
    int steps;
    float calories;
} ActivityLog;

ActivityLog logs[MAX_ENTRIES];
int logCount = 0;

void addActivity() {
    if (logCount >= MAX_ENTRIES) {
        printf("Log is full. Cannot add new activity.\n");
        return;
    }

    ActivityLog newLog;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", newLog.date);
    
    printf("Enter distance (in km): ");
    scanf("%f", &newLog.distance);
    
    printf("Enter number of steps: ");
    scanf("%d", &newLog.steps);
    
    printf("Enter calories burned: ");
    scanf("%f", &newLog.calories);
    
    logs[logCount++] = newLog;
    printf("Activity logged successfully!\n");
}

void viewActivities() {
    if (logCount == 0) {
        printf("No activities logged.\n");
        return;
    }

    printf("\nDate        Distance (km)  Steps   Calories Burned\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        printf("%s   %.2f               %d      %.2f\n", logs[i].date, logs[i].distance, logs[i].steps, logs[i].calories);
    }
}

void calculateStats() {
    if (logCount == 0) {
        printf("No activities to calculate stats.\n");
        return;
    }

    float totalDistance = 0;
    int totalSteps = 0;
    float totalCalories = 0;

    for (int i = 0; i < logCount; i++) {
        totalDistance += logs[i].distance;
        totalSteps += logs[i].steps;
        totalCalories += logs[i].calories;
    }

    printf("\nTotal Distance: %.2f km\n", totalDistance);
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Calories Burned: %.2f\n", totalCalories);
}

void deleteActivity() {
    if (logCount == 0) {
        printf("No activities to delete.\n");
        return;
    }

    viewActivities();
    int index;
    printf("Enter the index of the activity to delete (0 to %d): ", logCount - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= logCount) {
        printf("Invalid index entered.\n");
        return;
    }

    for (int i = index; i < logCount - 1; i++) {
        logs[i] = logs[i + 1];
    }
    logCount--;
    printf("Activity deleted successfully!\n");
}

void saveToFile() {
    FILE *file = fopen("activity_log.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < logCount; i++) {
        fprintf(file, "%s,%.2f,%d,%.2f\n", logs[i].date, logs[i].distance, logs[i].steps, logs[i].calories);
    }

    fclose(file);
    printf("Activities saved to activity_log.txt\n");
}

void loadFromFile() {
    FILE *file = fopen("activity_log.txt", "r");
    if (file == NULL) {
        printf("No saved file found, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%10[^,],%f,%d,%f\n", logs[logCount].date, &logs[logCount].distance, &logs[logCount].steps, &logs[logCount].calories) != EOF && logCount < MAX_ENTRIES) {
        logCount++;
    }

    fclose(file);
    printf("Activities loaded successfully!\n");
}

void displayMenu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add Activity\n");
    printf("2. View Activities\n");
    printf("3. Calculate Stats\n");
    printf("4. Delete Activity\n");
    printf("5. Save to File\n");
    printf("6. Load from File\n");
    printf("7. Exit\n");
    printf("===========================\n");
}

int main() {
    loadFromFile();
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addActivity();
                break;
            case 2:
                viewActivities();
                break;
            case 3:
                calculateStats();
                break;
            case 4:
                deleteActivity();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                loadFromFile();
                break;
            case 7:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}