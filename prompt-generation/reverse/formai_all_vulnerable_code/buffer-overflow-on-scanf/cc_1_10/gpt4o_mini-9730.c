//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define BUFFER_LENGTH 256

typedef struct {
    int steps;
    float calories;
    char exercise[BUFFER_LENGTH];
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initialize_tracker(FitnessTracker* tracker) {
    tracker->count = 0;
}

void add_entry(FitnessTracker* tracker, int steps, float calories, const char* exercise) {
    if (tracker->count < MAX_ENTRIES) {
        tracker->entries[tracker->count].steps = steps;
        tracker->entries[tracker->count].calories = calories;
        strncpy(tracker->entries[tracker->count].exercise, exercise, BUFFER_LENGTH);
        tracker->count++;
        printf("Entry added: %d steps, %.2f calories, Exercise: '%s'\n",
               steps, calories, exercise);
    } else {
        printf("Error: Maximum entries reached. Cannot add more.\n");
    }
}

void display_summary(const FitnessTracker* tracker) {
    printf("\n--- Fitness Summary ---\n");
    printf("Total Entries: %d\n", tracker->count);
    if (tracker->count > 0) {
        int total_steps = 0;
        float total_calories = 0.0;

        for (int i = 0; i < tracker->count; ++i) {
            total_steps += tracker->entries[i].steps;
            total_calories += tracker->entries[i].calories;
        }

        printf("Total Steps: %d\n", total_steps);
        printf("Total Calories Burned: %.2f\n", total_calories);
    }
}

void print_entry(const FitnessEntry* entry) {
    printf("Steps: %d, Calories: %.2f, Exercise: '%s'\n", 
           entry->steps, entry->calories, entry->exercise);
}

void display_entries(const FitnessTracker* tracker) {
    printf("\n--- All Fitness Entries ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Entry %d: ", i + 1);
        print_entry(&tracker->entries[i]);
    }
}

int main() {
    FitnessTracker tracker;
    initialize_tracker(&tracker);

    int choice;
    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Summary\n");
        printf("3. Show All Entries\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            break;
        }
        
        if (choice == 1) {
            int steps;
            float calories;
            char exercise[BUFFER_LENGTH];

            printf("Enter number of steps: ");
            scanf("%d", &steps);
            
            printf("Enter calories burned: ");
            scanf("%f", &calories);
            
            printf("Enter exercise type: ");
            getchar();  // to consume the newline character
            fgets(exercise, BUFFER_LENGTH, stdin);
            exercise[strcspn(exercise, "\n")] = 0; // remove newline

            add_entry(&tracker, steps, calories, exercise);
        } else if (choice == 2) {
            display_summary(&tracker);
        } else if (choice == 3) {
            display_entries(&tracker);
        } else if (choice == 4) {
            printf("Exiting... Thank you for using the Fitness Tracker!\n");
        } else {
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}