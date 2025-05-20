//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold fitness activity details
typedef struct {
    char activity[30];
    int duration; // in minutes
    int caloriesBurned;
    char date[11]; // DD-MM-YYYY
} FitnessActivity;

// Function declarations
void logActivity(FitnessActivity *activities, int *count);
void displayActivities(FitnessActivity *activities, int count);
int calculateTotalCalories(FitnessActivity *activities, int count);
void findMaxActivity(FitnessActivity *activities, int count);

// Main function
int main() {
    FitnessActivity activities[100];
    int activityCount = 0;
    int choice;

    do {
        printf("\n================ Fitness Tracker =================\n");
        printf("1. Log Activity\n");
        printf("2. Display Activities\n");
        printf("3. Total Calories Burned\n");
        printf("4. Max Activity Duration\n");
        printf("5. Exit\n");
        printf("==================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                logActivity(activities, &activityCount);
                break;
            case 2:
                displayActivities(activities, activityCount);
                break;
            case 3:
                printf("Total Calories Burned: %d cal\n", calculateTotalCalories(activities, activityCount));
                break;
            case 4:
                findMaxActivity(activities, activityCount);
                break;
            case 5:
                printf("Exiting. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to log a new fitness activity
void logActivity(FitnessActivity *activities, int *count) {
    if (*count >= 100) {
        printf("Activity log is full!\n");
        return;
    }

    printf("Enter activity name: ");
    scanf("%s", activities[*count].activity);
    printf("Enter duration (in minutes): ");
    scanf("%d", &activities[*count].duration);
    printf("Enter calories burned: ");
    scanf("%d", &activities[*count].caloriesBurned);
    
    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(activities[*count].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    (*count)++;
    printf("Activity logged successfully!\n");
}

// Function to display all logged activities
void displayActivities(FitnessActivity *activities, int count) {
    if (count == 0) {
        printf("No activities logged yet.\n");
        return;
    }

    printf("==================================================================\n");
    printf("%-30s %-10s %-10s %-12s\n", "Activity", "Duration", "Calories", "Date");
    printf("==================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%-30s %-10d %-10d %-12s\n", activities[i].activity, activities[i].duration, activities[i].caloriesBurned, activities[i].date);
    }

    printf("==================================================================\n");
}

// Function to calculate total calories burned
int calculateTotalCalories(FitnessActivity *activities, int count) {
    int totalCalories = 0;

    for (int i = 0; i < count; i++) {
        totalCalories += activities[i].caloriesBurned;
    }

    return totalCalories;
}

// Function to find the maximum activity duration
void findMaxActivity(FitnessActivity *activities, int count) {
    if (count == 0) {
        printf("No activities logged yet.\n");
        return;
    }

    int maxDuration = activities[0].duration;
    char maxActivity[30];
    strcpy(maxActivity, activities[0].activity);

    for (int i = 1; i < count; i++) {
        if (activities[i].duration > maxDuration) {
            maxDuration = activities[i].duration;
            strcpy(maxActivity, activities[i].activity);
        }
    }

    printf("Maximum activity: %s with duration of %d minutes.\n", maxActivity, maxDuration);
}