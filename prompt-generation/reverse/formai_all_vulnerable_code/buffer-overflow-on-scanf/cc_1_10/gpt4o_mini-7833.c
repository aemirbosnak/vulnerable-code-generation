//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t date;
    int steps;
    float distance; // in kilometers
    int calories; // burned
} ExerciseEntry;

typedef struct {
    ExerciseEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker *tracker, const char *name, int steps, float distance, int calories) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->entries[tracker->count].name, name, MAX_NAME_LENGTH);
        tracker->entries[tracker->count].date = time(NULL);
        tracker->entries[tracker->count].steps = steps;
        tracker->entries[tracker->count].distance = distance;
        tracker->entries[tracker->count].calories = calories;
        tracker->count++;
    } else {
        printf("Maximum entries reached!\n");
    }
}

void listEntries(const FitnessTracker *tracker) {
    printf("\nExercise Entries:\n");
    printf("----------------------------------------------------------\n");
    printf("%-15s %-15s %-10s %-10s %-10s\n", "Name", "Date", "Steps", "Distance", "Calories");
    printf("----------------------------------------------------------\n");
    char dateBuffer[26];
    for (int i = 0; i < tracker->count; i++) {
        struct tm *tm_info = localtime(&tracker->entries[i].date);
        strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", tm_info);
        printf("%-15s %-15s %-10d %-10.2f %-10d\n", tracker->entries[i].name,
               dateBuffer, tracker->entries[i].steps,
               tracker->entries[i].distance, tracker->entries[i].calories);
    }
}

float calculateAverageSteps(const FitnessTracker *tracker) {
    if (tracker->count == 0) return 0;
    
    int totalSteps = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->entries[i].steps;
    }
    return (float)totalSteps / tracker->count;
}

void saveToFile(const FitnessTracker *tracker) {
    FILE *file = fopen("fitness_tracker.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%ld,%d,%.2f,%d\n", tracker->entries[i].name,
                tracker->entries[i].date, tracker->entries[i].steps,
                tracker->entries[i].distance, tracker->entries[i].calories);
    }

    fclose(file);
    printf("Data saved to fitness_tracker.txt\n");
}

void loadFromFile(FitnessTracker *tracker) {
    FILE *file = fopen("fitness_tracker.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    while (!feof(file) && tracker->count < MAX_ENTRIES) {
        ExerciseEntry entry;
        char dateBuffer[26];
        fscanf(file, "%49[^,],%25[^,],%d,%f,%d\n", entry.name, dateBuffer,
               &entry.steps, &entry.distance, &entry.calories);
        entry.date = time(NULL);  // In a real implementation store the parsed date
        tracker->entries[tracker->count++] = entry;
    }

    fclose(file);
    printf("Data loaded from fitness_tracker.txt\n");
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. List Entries\n");
        printf("3. Calculate Average Steps\n");
        printf("4. Save Data to File\n");
        printf("5. Load Data from File\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                int steps;
                float distance;
                int calories;
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter steps: ");
                scanf("%d", &steps);
                printf("Enter distance (km): ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                addEntry(&tracker, name, steps, distance, calories);
                break;
            }
            case 2:
                listEntries(&tracker);
                break;
            case 3: {
                float avgSteps = calculateAverageSteps(&tracker);
                printf("Average Steps: %.2f\n", avgSteps);
                break;
            }
            case 4:
                saveToFile(&tracker);
                break;
            case 5:
                loadFromFile(&tracker);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}