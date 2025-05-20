//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    float caloriesBurned;
    float distanceCovered; // in kilometers
    time_t date; // stores the date of the entry
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

// Function Prototypes
void addFitnessEntry(FitnessTracker* tracker);
void displayEntries(const FitnessTracker* tracker);
void calculateStatistics(const FitnessTracker* tracker);
void saveEntriesToFile(const FitnessTracker* tracker);
void loadEntriesFromFile(FitnessTracker* tracker);

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    loadEntriesFromFile(&tracker);

    int choice;

    do {
        printf("\nWelcome to the Futuristic Fitness Tracker\n");
        printf("1. Add Fitness Entry\n");
        printf("2. Display Entries\n");
        printf("3. Calculate Statistics\n");
        printf("4. Save Entries to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFitnessEntry(&tracker);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                calculateStatistics(&tracker);
                break;
            case 4:
                saveEntriesToFile(&tracker);
                break;
            case 5:
                printf("Exiting Future Fitness Tracker. Stay active!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addFitnessEntry(FitnessTracker* tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Entry limit reached! Cannot add more entries.\n");
        return;
    }

    FitnessEntry entry;
    printf("Enter the name of the activity: ");
    scanf("%s", entry.name);
    printf("Enter calories burned: ");
    scanf("%f", &entry.caloriesBurned);
    printf("Enter distance covered (in km): ");
    scanf("%f", &entry.distanceCovered);
    entry.date = time(NULL);

    tracker->entries[tracker->count] = entry;
    tracker->count++;

    printf("Fitness Entry added successfully!\n");
}

void displayEntries(const FitnessTracker* tracker) {
    if (tracker->count == 0) {
        printf("No entries to display!\n");
        return;
    }

    printf("\n--- Fitness Entries ---\n");
    for (int i = 0; i < tracker->count; i++) {
        char dateStr[MAX_DATE_LENGTH];
        struct tm* tm_info = localtime(&(tracker->entries[i].date));
        strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", tm_info);
        printf("Activity: %s, Calories Burned: %.2f, Distance Covered: %.2f km, Date: %s\n",
               tracker->entries[i].name, tracker->entries[i].caloriesBurned,
               tracker->entries[i].distanceCovered, dateStr);
    }
}

void calculateStatistics(const FitnessTracker* tracker) {
    if (tracker->count == 0) {
        printf("No entries to calculate statistics!\n");
        return;
    }

    float totalCalories = 0.0;
    float totalDistance = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        totalCalories += tracker->entries[i].caloriesBurned;
        totalDistance += tracker->entries[i].distanceCovered;
    }

    printf("Total Calories Burned: %.2f\n", totalCalories);
    printf("Total Distance Covered: %.2f km\n", totalDistance);
}

void saveEntriesToFile(const FitnessTracker* tracker) {
    FILE *file = fopen("fitness_entries.txt", "w");

    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        char dateStr[MAX_DATE_LENGTH];
        struct tm* tm_info = localtime(&(tracker->entries[i].date));
        strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", tm_info);
        fprintf(file, "%s %.2f %.2f %s\n", tracker->entries[i].name, tracker->entries[i].caloriesBurned,
                tracker->entries[i].distanceCovered, dateStr);
    }

    fclose(file);
    printf("Entries saved to fitness_entries.txt successfully!\n");
}

void loadEntriesFromFile(FitnessTracker* tracker) {
    FILE *file = fopen("fitness_entries.txt", "r");

    if (file == NULL) {
        printf("No previous entries found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%s %f %f %s", 
                  tracker->entries[tracker->count].name, 
                  &tracker->entries[tracker->count].caloriesBurned, 
                  &tracker->entries[tracker->count].distanceCovered, 
                  tracker->entries[tracker->count].name) != EOF) {
        tracker->entries[tracker->count].date = time(NULL); // Simplified; can be improved
        tracker->count++;
    }

    fclose(file);
    printf("Entries loaded successfully! You have %d entries.\n", tracker->count);
}