//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    int calories;
    time_t date; // store date as a timestamp
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

// Function to initialize the fitness tracker
void initTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

// Function to add an entry to the tracker
void addEntry(FitnessTracker *tracker, const char *name, int steps, float distance, int calories) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Maximum entries reached!\n");
        return;
    }
    
    strcpy(tracker->entries[tracker->count].name, name);
    tracker->entries[tracker->count].steps = steps;
    tracker->entries[tracker->count].distance = distance;
    tracker->entries[tracker->count].calories = calories;
    tracker->entries[tracker->count].date = time(NULL); // current date and time
    tracker->count++;
    printf("Entry added successfully!\n");
}

// Function to display all entries
void displayEntries(const FitnessTracker *tracker) {
    printf("Fitness Tracker Entries:\n");
    printf("----------------------------------------------------------\n");
    printf("| Name            | Steps | Distance (km) | Calories  |\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < tracker->count; i++) {
        printf("| %-15s | %-5d | %-13.2f | %-8d  |\n", 
               tracker->entries[i].name, 
               tracker->entries[i].steps, 
               tracker->entries[i].distance, 
               tracker->entries[i].calories);
    }
    printf("----------------------------------------------------------\n");
}

// Function to calculate total stats
void calculateStats(const FitnessTracker *tracker) {
    int totalSteps = 0, totalCalories = 0;
    float totalDistance = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->entries[i].steps;
        totalDistance += tracker->entries[i].distance;
        totalCalories += tracker->entries[i].calories;
    }

    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

// Function to get user input safely
void getInput(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    }
}

// Main menu
void displayMenu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Calculate Stats\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

// Main function
int main() {
    FitnessTracker tracker;
    initTracker(&tracker);
    int choice;
    char name[MAX_NAME_LENGTH];
    int steps;
    float distance;
    int calories;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                getInput(name, sizeof(name));
                printf("Enter Steps: ");
                scanf("%d", &steps);
                printf("Enter Distance (in km): ");
                scanf("%f", &distance);
                printf("Enter Calories: ");
                scanf("%d", &calories);
                addEntry(&tracker, name, steps, distance, calories);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                calculateStats(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}