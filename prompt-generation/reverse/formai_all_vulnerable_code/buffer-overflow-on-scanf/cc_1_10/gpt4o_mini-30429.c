//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRACKERS 100

typedef struct {
    char name[50];
    int steps;
    float distance; // in kilometers
    float calories; // burned calories
    time_t date; // timestamp for the data entry
} FitnessTracker;

typedef struct {
    FitnessTracker trackers[MAX_TRACKERS];
    int count;
} TrackerList;

void initTrackerList(TrackerList *list) {
    list->count = 0;
}

void addEntry(TrackerList *list, const char *name, int steps, float distance, float calories) {
    if (list->count >= MAX_TRACKERS) {
        printf("Cannot add more entries: maximum limit reached.\n");
        return;
    }
    FitnessTracker *tracker = &list->trackers[list->count];
    strncpy(tracker->name, name, sizeof(tracker->name) - 1);
    tracker->steps = steps;
    tracker->distance = distance;
    tracker->calories = calories;
    tracker->date = time(NULL); // current time
    list->count++;
    printf("Entry added for %s.\n", name);
}

void displayEntries(const TrackerList *list) {
    if (list->count == 0) {
        printf("No entries found.\n");
        return;
    }
    
    printf("\nFitness Tracker Entries:\n");
    printf("----------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s %-15s\n", "Name", "Steps", "Distance(km)", "Calories", "Date");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < list->count; i++) {
        FitnessTracker *tracker = &list->trackers[i];
        char dateStr[20];
        strftime(dateStr, sizeof(dateStr), "%Y-%m-%d %H:%M:%S", localtime(&tracker->date));
        printf("%-20s %-10d %-10.2f %-10.2f %-15s\n", 
               tracker->name, tracker->steps, tracker->distance, tracker->calories, dateStr);
    }
    printf("----------------------------------------------------\n");
}

void calculateTotalStats(const TrackerList *list) {
    int totalSteps = 0;
    float totalDistance = 0.0, totalCalories = 0.0;

    for (int i = 0; i < list->count; i++) {
        totalSteps += list->trackers[i].steps;
        totalDistance += list->trackers[i].distance;
        totalCalories += list->trackers[i].calories;
    }

    printf("\nTotal Stats:\n");
    printf("----------------------------------------------------\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f\n", totalCalories);
    printf("----------------------------------------------------\n");
}

void saveToFile(const TrackerList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    fwrite(list, sizeof(TrackerList), 1, file);
    fclose(file);
    printf("Data saved to file %s.\n", filename);
}

void loadFromFile(TrackerList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return;
    }

    fread(list, sizeof(TrackerList), 1, file);
    fclose(file);
    printf("Data loaded from file %s.\n", filename);
}

int main() {
    TrackerList myTrackers;
    initTrackerList(&myTrackers);

    int choice;
    char name[50];
    int steps;
    float distance, calories, totalCalBurned;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Calculate Total Stats\n");
        printf("4. Save Data to File\n");
        printf("5. Load Data from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Steps: ");
                scanf("%d", &steps);
                printf("Enter Distance (in km): ");
                scanf("%f", &distance);
                printf("Enter Calories Burned: ");
                scanf("%f", &calories);
                addEntry(&myTrackers, name, steps, distance, calories);
                break;
            case 2:
                displayEntries(&myTrackers);
                break;
            case 3:
                calculateTotalStats(&myTrackers);
                break;
            case 4:
                saveToFile(&myTrackers, "fitness_data.dat");
                break;
            case 5:
                loadFromFile(&myTrackers, "fitness_data.dat");
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}