//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int sets;
    int reps;
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int totalExercises;
} FitnessTracker;

void initializeTracker(FitnessTracker* tracker) {
    tracker->totalExercises = 0;
}

void addExercise(FitnessTracker* tracker, const char* name, int sets, int reps) {
    if (tracker->totalExercises < MAX_EXERCISES) {
        strcpy(tracker->exercises[tracker->totalExercises].name, name);
        tracker->exercises[tracker->totalExercises].sets = sets;
        tracker->exercises[tracker->totalExercises].reps = reps;
        tracker->totalExercises++;
        printf("Exercise added: %s, Sets: %d, Reps: %d\n", name, sets, reps);
    } else {
        printf("Unable to add exercise. Maximum limit reached.\n");
    }
}

void displayExercises(const FitnessTracker* tracker) {
    printf("\n--- Current Exercise Tracker ---\n");
    for (int i = 0; i < tracker->totalExercises; i++) {
        printf("Exercise %d: %s, Sets: %d, Reps: %d\n", 
               i + 1, tracker->exercises[i].name, tracker->exercises[i].sets, tracker->exercises[i].reps);
    }
    if (tracker->totalExercises == 0) {
        printf("No exercises recorded.\n");
    }
    printf("---------------------------------\n");
}

void removeExercise(FitnessTracker* tracker, int index) {
    if (index < 0 || index >= tracker->totalExercises) {
        printf("Invalid index. No exercise removed.\n");
        return;
    }
    for (int i = index; i < tracker->totalExercises - 1; i++) {
        tracker->exercises[i] = tracker->exercises[i + 1];
    }
    tracker->totalExercises--;
    printf("Exercise removed successfully.\n");
}

void saveTracker(const FitnessTracker* tracker, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < tracker->totalExercises; i++) {
        fprintf(file, "%s;%d;%d\n", tracker->exercises[i].name, 
                tracker->exercises[i].sets, tracker->exercises[i].reps);
    }
    fclose(file);
    printf("Tracker saved to %s\n", filename);
}

void loadTracker(FitnessTracker* tracker, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for loading.\n");
        return;
    }
    initializeTracker(tracker);
    while (!feof(file)) {
        char line[100];
        if (fgets(line, sizeof(line), file)) {
            char name[MAX_NAME_LENGTH];
            int sets, reps;

            sscanf(line, "%[^;];%d;%d", name, &sets, &reps);
            addExercise(tracker, name, sets, reps);
        }
    }
    fclose(file);
    printf("Tracker loaded from %s\n", filename);
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);

    int choice, sets, reps;
    char name[MAX_NAME_LENGTH];
    const char* filename = "fitness_tracker.txt";

    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Exercise\n");
        printf("2. View Exercises\n");
        printf("3. Remove Exercise\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Exercise Name: ");
                scanf("%s", name);
                printf("Enter Number of Sets: ");
                scanf("%d", &sets);
                printf("Enter Number of Reps: ");
                scanf("%d", &reps);
                addExercise(&tracker, name, sets, reps);
                break;

            case 2:
                displayExercises(&tracker);
                break;

            case 3:
                printf("Enter the exercise index to remove (1 to %d): ", tracker.totalExercises);
                int index;
                scanf("%d", &index);
                removeExercise(&tracker, index - 1);
                break;

            case 4:
                saveTracker(&tracker, filename);
                break;

            case 5:
                loadTracker(&tracker, filename);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}