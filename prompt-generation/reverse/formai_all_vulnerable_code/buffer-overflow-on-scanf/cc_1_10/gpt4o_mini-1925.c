//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define WORKOUT_TYPE_LENGTH 30
#define MAX_WORKOUT_NAME 50

typedef struct {
    char name[MAX_WORKOUT_NAME];
    char type[WORKOUT_TYPE_LENGTH];
    int duration; // in minutes
    int calories; // burned during the workout
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int workout_count;
} FitnessTracker;

void initialize_tracker(FitnessTracker *tracker) {
    tracker->workout_count = 0;
}

void add_workout(FitnessTracker *tracker, const char *name, const char *type, int duration, int calories) {
    if (tracker->workout_count < MAX_WORKOUTS) {
        strncpy(tracker->workouts[tracker->workout_count].name, name, MAX_WORKOUT_NAME);
        strncpy(tracker->workouts[tracker->workout_count].type, type, WORKOUT_TYPE_LENGTH);
        tracker->workouts[tracker->workout_count].duration = duration;
        tracker->workouts[tracker->workout_count].calories = calories;
        tracker->workout_count++;
        printf("Workout '%s' added successfully!\n", name);
    } else {
        printf("Workout log is full! Cannot add more workouts.\n");
    }
}

void display_workouts(const FitnessTracker *tracker) {
    printf("\n---- Workout Summary ----\n");
    for (int i = 0; i < tracker->workout_count; i++) {
        printf("Workout %d:\n", i + 1);
        printf("  Name: %s\n", tracker->workouts[i].name);
        printf("  Type: %s\n", tracker->workouts[i].type);
        printf("  Duration: %d minutes\n", tracker->workouts[i].duration);
        printf("  Calories Burned: %d\n", tracker->workouts[i].calories);
        printf("-------------------------\n");
    }
}

void save_to_file(const FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < tracker->workout_count; i++) {
        fprintf(file, "%s,%s,%d,%d\n",
                tracker->workouts[i].name,
                tracker->workouts[i].type,
                tracker->workouts[i].duration,
                tracker->workouts[i].calories);
    }
    fclose(file);
    printf("Data saved to '%s'\n", filename);
}

void load_from_file(FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char buffer[150];
    while (fgets(buffer, sizeof(buffer), file) && tracker->workout_count < MAX_WORKOUTS) {
        char name[MAX_WORKOUT_NAME];
        char type[WORKOUT_TYPE_LENGTH];
        int duration;
        int calories;

        sscanf(buffer, "%[^,],%[^,],%d,%d", name, type, &duration, &calories);
        add_workout(tracker, name, type, duration, calories);
    }
    fclose(file);
}

void display_menu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Workout\n");
    printf("2. Display Workouts\n");
    printf("3. Save Workouts to File\n");
    printf("4. Load Workouts from File\n");
    printf("5. Exit\n");
    printf("----------------------------\n");
}

int main() {
    FitnessTracker tracker;
    initialize_tracker(&tracker);
    char filename[] = "workouts.txt";
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[MAX_WORKOUT_NAME];
                char type[WORKOUT_TYPE_LENGTH];
                int duration;
                int calories;

                printf("Enter workout name: ");
                getchar(); // clear newline
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline

                printf("Enter workout type: ");
                fgets(type, sizeof(type), stdin);
                type[strcspn(type, "\n")] = '\0'; // remove newline

                printf("Enter duration (in minutes): ");
                scanf("%d", &duration);
                printf("Enter calories burned: ");
                scanf("%d", &calories);

                add_workout(&tracker, name, type, duration, calories);
                break;
            }
            case 2:
                display_workouts(&tracker);
                break;
            case 3:
                save_to_file(&tracker, filename);
                break;
            case 4:
                load_from_file(&tracker, filename);
                break;
            case 5:
                printf("Exiting the tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}