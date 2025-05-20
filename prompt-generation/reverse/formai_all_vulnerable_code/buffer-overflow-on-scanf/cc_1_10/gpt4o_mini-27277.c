//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];  // Format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    float calories; // in kcal
} ActivityEntry;

typedef struct {
    ActivityEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker *tracker, const char *date, int steps, float distance, float calories) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->entries[tracker->count].date, date, 10);
        tracker->entries[tracker->count].date[10] = '\0'; // Null-terminate
        tracker->entries[tracker->count].steps = steps;
        tracker->entries[tracker->count].distance = distance;
        tracker->entries[tracker->count].calories = calories;
        tracker->count++;
    } else {
        printf("Cannot add more entries. Maximum entries reached.\n");
    }
}

void displayEntries(const FitnessTracker *tracker) {
    printf("Date       | Steps   | Distance (km) | Calories\n");
    printf("-----------|---------|----------------|---------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s | %7d | %14.2f | %7.2f\n", tracker->entries[i].date, 
                tracker->entries[i].steps, 
                tracker->entries[i].distance, 
                tracker->entries[i].calories);
    }
}

void dailySummary(const FitnessTracker *tracker) {
    int totalSteps = 0;
    float totalDistance = 0.0;
    float totalCalories = 0.0;
    
    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->entries[i].steps;
        totalDistance += tracker->entries[i].distance;
        totalCalories += tracker->entries[i].calories;
    }
    
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f kcal\n", totalCalories);
}

void findEntryByDate(const FitnessTracker *tracker, const char *date) {
    int found = 0;
    printf("Searching for entries on %s...\n", date);
    for (int i = 0; i < tracker->count; i++) {
        if (strcmp(tracker->entries[i].date, date) == 0) {
            printf("Found entry: %s | %d steps | %.2f km | %.2f kcal\n", 
                   tracker->entries[i].date, 
                   tracker->entries[i].steps, 
                   tracker->entries[i].distance, 
                   tracker->entries[i].calories);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found for date %s.\n", date);
    }
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Activity Entry\n");
    printf("2. View All Entries\n");
    printf("3. Daily Summary\n");
    printf("4. Find Entry by Date\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume the newline character
        
        switch (choice) {
            case 1: {
                char date[11];
                int steps;
                float distance, calories;
                
                printf("Enter date (YYYY-MM-DD): ");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = '\0'; // Remove newline
                
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                
                printf("Enter distance (in km): ");
                scanf("%f", &distance);
                
                printf("Enter calories burned: ");
                scanf("%f", &calories);
                
                addEntry(&tracker, date, steps, distance, calories);
                printf("Entry added successfully!\n");
                break;
            }
            case 2: {
                displayEntries(&tracker);
                break;
            }
            case 3: {
                dailySummary(&tracker);
                break;
            }
            case 4: {
                char date[11];
                printf("Enter date (YYYY-MM-DD) to search: ");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = '\0'; // Remove newline
                findEntryByDate(&tracker, date);
                break;
            }
            case 5:
                printf("Exiting the Fitness Tracker.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}