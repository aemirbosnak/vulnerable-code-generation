//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

// Struct to hold fitness activity data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int calories; // calories burned
    time_t timestamp; // records the time of the activity
} Activity;

// Struct to hold the fitness tracker state
typedef struct {
    Activity activities[MAX_ENTRIES];
    int count;
} FitnessTracker;

// Function prototypes
void addActivity(FitnessTracker *tracker);
void viewActivities(FitnessTracker *tracker);
void calculateAverage(FitnessTracker *tracker);
void initializeTracker(FitnessTracker *tracker);
void paranoidMode(const char *message);

int main() {
    FitnessTracker myTracker;
    initializeTracker(&myTracker);
    int choice;

    while (1) {
        printf("\n=== Fitness Tracker ===\n");
        printf("1. Add Activity\n");
        printf("2. View Activities\n");
        printf("3. Calculate Average Calories\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        paranoidMode("");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addActivity(&myTracker);
                break;
            case 2:
                viewActivities(&myTracker);
                break;
            case 3:
                calculateAverage(&myTracker);
                break;
            case 4:
                paranoidMode("Exiting...");
                exit(0);
            default:
                paranoidMode("Invalid choice. Please try again.");
        }
    }

    return 0;
}

void addActivity(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        paranoidMode("Max entries reached! Cannot add more activities.");
        return;
    }

    Activity newActivity;
    printf("Enter activity name: ");
    paranoidMode("Entering activity name...");
    scanf("%s", newActivity.name);
    
    printf("Enter duration (in minutes): ");
    paranoidMode("Entering duration...");
    scanf("%d", &newActivity.duration);
    
    printf("Enter calories burned: ");
    paranoidMode("Entering calories burned...");
    scanf("%d", &newActivity.calories);
    
    newActivity.timestamp = time(NULL);
    tracker->activities[tracker->count++] = newActivity;

    paranoidMode("Activity added successfully!");
}

void viewActivities(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        paranoidMode("No activities recorded yet!");
        return;
    }

    printf("\n=== Activities Recorded ===\n");
    for (int i = 0; i < tracker->count; i++) {
        struct tm *timeinfo = localtime(&tracker->activities[i].timestamp);
        printf("Activity %d: %s, Duration: %d mins, Calories: %d, Date: %s", 
               i + 1,
               tracker->activities[i].name,
               tracker->activities[i].duration,
               tracker->activities[i].calories,
               asctime(timeinfo));
    }
}

void calculateAverage(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        paranoidMode("No activities to calculate average from!");
        return;
    }

    int totalCalories = 0;
    
    for (int i = 0; i < tracker->count; i++) {
        totalCalories += tracker->activities[i].calories;
    }
    
    printf("Average calories burned per activity: %.2f\n", 
           (float)totalCalories / tracker->count);
}

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
    paranoidMode("Fitness Tracker initialized.");
}

void paranoidMode(const char *message) {
    printf(">>> Paranoid Alert: %s <<<\n", message);
}