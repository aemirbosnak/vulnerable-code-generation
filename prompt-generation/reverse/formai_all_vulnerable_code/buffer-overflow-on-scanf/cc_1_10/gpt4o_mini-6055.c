//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50

typedef struct {
    char activityName[MAX_NAME_LEN];
    int duration; // in minutes
    float caloriesPerMinute;
} Activity;

Activity workoutLog[MAX_ENTRIES];
int entryCount = 0;

void addActivity() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Log is full! Cannot add more activities.\n");
        return;
    }
    
    Activity newActivity;
    
    printf("Enter activity name: ");
    scanf("%s", newActivity.activityName);
    printf("Enter duration (in minutes): ");
    scanf("%d", &newActivity.duration);
    printf("Enter calories burned per minute: ");
    scanf("%f", &newActivity.caloriesPerMinute);
    
    workoutLog[entryCount] = newActivity;
    entryCount++;
    printf("Activity logged successfully!\n");
}

void viewActivities() {
    if (entryCount == 0) {
        printf("No activities logged yet!\n");
        return;
    }
    
    printf("\nActivity Log:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-20s\n", "Activity Name", "Duration", "Calories Burned");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < entryCount; i++) {
        float totalCalories = workoutLog[i].duration * workoutLog[i].caloriesPerMinute;
        printf("%-20s %-10d %-20.2f\n", workoutLog[i].activityName, workoutLog[i].duration, totalCalories);
    }
    printf("--------------------------------------------------\n");
}

void calculateStatistics() {
    if (entryCount == 0) {
        printf("No activities logged yet!\n");
        return;
    }
    
    float totalCalories = 0;
    for (int i = 0; i < entryCount; i++) {
        totalCalories += workoutLog[i].duration * workoutLog[i].caloriesPerMinute;
    }
    
    float averageCalories = totalCalories / entryCount;
    
    printf("\nTotal Calories Burned: %.2f\n", totalCalories);
    printf("Average Calories per Activity: %.2f\n", averageCalories);
}

void clearLog() {
    entryCount = 0;
    printf("Workout log cleared!\n");
}

int main() {
    int choice;
    
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Activity\n");
        printf("2. View Activities\n");
        printf("3. Calculate Statistics\n");
        printf("4. Clear Log\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addActivity();
                break;
            case 2:
                viewActivities();
                break;
            case 3:
                calculateStatistics();
                break;
            case 4:
                clearLog();
                break;
            case 5:
                printf("Exiting the program. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);
    
    return 0;
}