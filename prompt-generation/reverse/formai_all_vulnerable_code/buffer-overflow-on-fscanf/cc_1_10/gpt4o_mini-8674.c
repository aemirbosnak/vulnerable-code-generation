//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];   // Format: YYYY-MM-DD
    float distance;  // in kilometers
    int duration;    // in minutes
    int calories;    // burned calories
} WorkoutEntry;

typedef struct {
    WorkoutEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

// Function prototypes
void addWorkout(FitnessTracker *tracker);
void displayWorkouts(const FitnessTracker *tracker);
void saveToFile(const FitnessTracker *tracker);
void loadFromFile(FitnessTracker *tracker);
void menu(FitnessTracker *tracker);

int main() {
    FitnessTracker tracker;
    tracker.count = 0;
    
    loadFromFile(&tracker);
    
    menu(&tracker);
    
    saveToFile(&tracker);
    return 0;
}

void menu(FitnessTracker *tracker) {
    int choice;
    do {
        printf("\n=== Fitness Tracker ===\n");
        printf("1. Add Workout Entry\n");
        printf("2. Display Workout Entries\n");
        printf("3. Quit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addWorkout(tracker);
                break;
            case 2:
                displayWorkouts(tracker);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);
}

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more workouts.\n");
        return;
    }
    
    WorkoutEntry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    
    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);
    
    printf("Enter duration (in minutes): ");
    scanf("%d", &newEntry.duration);
    
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);
    
    tracker->entries[tracker->count++] = newEntry;
    printf("Workout entry added successfully!\n");
}

void displayWorkouts(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workout entries found.\n");
        return;
    }
    
    printf("\n--- Workout Entries ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Date: %s | Distance: %.2f km | Duration: %d min | Calories: %d kcal\n",
               tracker->entries[i].date,
               tracker->entries[i].distance,
               tracker->entries[i].duration,
               tracker->entries[i].calories);
    }
}

void saveToFile(const FitnessTracker *tracker) {
    FILE *file = fopen("fitness_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving data.\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s %f %d %d\n", 
                tracker->entries[i].date, 
                tracker->entries[i].distance,
                tracker->entries[i].duration,
                tracker->entries[i].calories);
    }
    fclose(file);
    printf("Data saved to fitness_data.txt\n");
}

void loadFromFile(FitnessTracker *tracker) {
    FILE *file = fopen("fitness_data.txt", "r");
    if (file == NULL) {
        printf("No previous data found, starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%s %f %d %d\n",
                  tracker->entries[tracker->count].date,
                  &tracker->entries[tracker->count].distance,
                  &tracker->entries[tracker->count].duration,
                  &tracker->entries[tracker->count].calories) == 4) {
        tracker->count++;
        if (tracker->count >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
    printf("Data loaded from fitness_data.txt\n");
}