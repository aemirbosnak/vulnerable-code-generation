//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float distance;      // distance in kilometers
    int duration;        // duration in minutes
    time_t timestamp;    // timestamp of the entry
} ActivityEntry;

typedef struct {
    ActivityEntry entries[MAX_ENTRIES];
    int count;
} ActivityTracker;

// Function Prototypes
void addActivity(ActivityTracker* tracker);
void displayActivities(const ActivityTracker* tracker);
void saveToFile(const ActivityTracker* tracker, const char* filename);
void loadFromFile(ActivityTracker* tracker, const char* filename);
void printMenu();
void clearEntries(ActivityTracker* tracker);

int main() {
    ActivityTracker tracker = {.count = 0};
    loadFromFile(&tracker, "activities.txt");

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                addActivity(&tracker);
                break;
            case 2:
                displayActivities(&tracker);
                break;
            case 3:
                saveToFile(&tracker, "activities.txt");
                break;
            case 4:
                clearEntries(&tracker);
                break;
            case 5: 
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void printMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Activity\n");
    printf("2. Display Activities\n");
    printf("3. Save Activities\n");
    printf("4. Clear All Activities\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void addActivity(ActivityTracker* tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Activity log is full! Cannot add more activities.\n");
        return;
    }

    ActivityEntry newEntry;

    printf("Enter your name: ");
    scanf("%s", newEntry.name);

    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);

    printf("Enter duration (in minutes): ");
    scanf("%d", &newEntry.duration);

    newEntry.timestamp = time(NULL); // Get the current time

    tracker->entries[tracker->count++] = newEntry;
    printf("Activity added successfully!\n");
}

void displayActivities(const ActivityTracker* tracker) {
    if (tracker->count == 0) {
        printf("No activities recorded yet.\n");
        return;
    }

    printf("\n--- Recorded Activities ---\n");
    for (int i = 0; i < tracker->count; ++i) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", tracker->entries[i].name);
        printf("Distance: %.2f km\n", tracker->entries[i].distance);
        printf("Duration: %d min\n", tracker->entries[i].duration);
        printf("Date: %s", ctime(&tracker->entries[i].timestamp)); // Convert timestamp to readable format
        printf("--------------------------\n");
    }
}

void saveToFile(const ActivityTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    fwrite(tracker, sizeof(ActivityTracker), 1, file);
    fclose(file);
    printf("Activities saved successfully!\n");
}

void loadFromFile(ActivityTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous activity log found. Starting fresh.\n");
        return;
    }

    fread(tracker, sizeof(ActivityTracker), 1, file);
    fclose(file);
    printf("Activities loaded successfully!\n");
}

void clearEntries(ActivityTracker* tracker) {
    tracker->count = 0;
    printf("All activities cleared successfully!\n");
}