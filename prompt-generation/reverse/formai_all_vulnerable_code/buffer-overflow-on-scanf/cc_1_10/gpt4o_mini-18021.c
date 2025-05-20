//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_SIZE 30

typedef struct {
    char activity[NAME_SIZE];
    int steps;
    float calories;
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker *tracker, const char *activity, int steps, float calories) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->entries[tracker->count].activity, activity, NAME_SIZE - 1);
        tracker->entries[tracker->count].activity[NAME_SIZE - 1] = '\0'; // Null terminate
        tracker->entries[tracker->count].steps = steps;
        tracker->entries[tracker->count].calories = calories;
        tracker->count++;
    } else {
        printf("Unable to add entry. Max entries reached.\n");
    }
}

void viewSummary(const FitnessTracker *tracker) {
    printf("Fitness Summary:\n");
    printf("-----------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Activity", "Steps", "Calories");
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < tracker->count; i++) {
        printf("%-20s %-10d %-10.2f\n", tracker->entries[i].activity, 
               tracker->entries[i].steps, 
               tracker->entries[i].calories);
    }
    
    printf("-----------------------------------------------------\n");
}

void displayMenu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Fitness Entry\n");
    printf("2. View Summary\n");
    printf("3. Exit\n");
}

int main() {
    FitnessTracker tracker;
    initTracker(&tracker);
    
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char activity[NAME_SIZE];
                int steps;
                float calories;

                printf("Enter activity name: ");
                scanf(" %[^\n]", activity);
                printf("Enter steps: ");
                scanf("%d", &steps);
                printf("Enter calories burned: ");
                scanf("%f", &calories);
                
                addEntry(&tracker, activity, steps, calories);
                printf("Entry added successfully!\n");
                break;
            }
            case 2:
                viewSummary(&tracker);
                break;
            case 3:
                printf("Exiting the program. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}