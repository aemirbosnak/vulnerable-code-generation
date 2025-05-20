//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float distance;    // in kilometers
    float duration;    // in minutes
    time_t timestamp;  // timestamp of entry
} ActivityEntry;

ActivityEntry activities[MAX_ENTRIES];
int entryCount = 0;

void addActivity();
void viewActivities();
void saveActivities(const char* filename);
void loadActivities(const char* filename);
void clearActivities();

int main() {
    int choice;
    const char* filename = "activities.txt";

    loadActivities(filename);

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add New Activity\n");
        printf("2. View Activities\n");
        printf("3. Save Activities\n");
        printf("4. Clear All Activities\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addActivity();
                break;
            case 2:
                viewActivities();
                break;
            case 3:
                saveActivities(filename);
                break;
            case 4:
                clearActivities();
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void addActivity() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum number of entries reached. Unable to add new activity.\n");
        return;
    }

    ActivityEntry newEntry;
    printf("Enter activity name: ");
    scanf("%s", newEntry.name);
    printf("Enter distance (km): ");
    scanf("%f", &newEntry.distance);
    printf("Enter duration (minutes): ");
    scanf("%f", &newEntry.duration);
    newEntry.timestamp = time(NULL);

    activities[entryCount] = newEntry;
    entryCount++;
    printf("Activity added successfully!\n");
}

void viewActivities() {
    if (entryCount == 0) {
        printf("No activities to display.\n");
        return;
    }

    printf("\nActivity Log:\n");
    printf("-------------------------------------------------\n");
    printf("Name         | Distance (km) | Duration (min) | Date\n");
    printf("-------------------------------------------------\n");
    
    char buffer[26];
    for (int i = 0; i < entryCount; i++) {
        ctime_r(&activities[i].timestamp, buffer);
        buffer[strlen(buffer) - 1] = '\0'; // remove newline character
        printf("%-12s | %-13.2f | %-15.2f | %s\n", 
               activities[i].name, 
               activities[i].distance, 
               activities[i].duration, 
               buffer);
    }
    printf("-------------------------------------------------\n");
}

void saveActivities(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for saving activities.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %.2f %.2f %ld\n", 
                activities[i].name, 
                activities[i].distance, 
                activities[i].duration, 
                activities[i].timestamp);
    }

    fclose(file);
    printf("Activities saved successfully to %s\n", filename);
}

void loadActivities(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("No existing activities found, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s %f %f %ld", 
                  activities[entryCount].name, 
                  &activities[entryCount].distance, 
                  &activities[entryCount].duration, 
                  &activities[entryCount].timestamp) == 4) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }

    fclose(file);
    printf("Activities loaded successfully. Total entries: %d\n", entryCount);
}

void clearActivities() {
    entryCount = 0;
    printf("All activities cleared.\n");
}