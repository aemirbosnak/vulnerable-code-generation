//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    int calories; // burned calories
    int waterIntake; // in liters
} FitnessTracker;

void addTracker(FitnessTracker *trackers, int *count) {
    if (*count >= MAX_TRACKERS) {
        printf("Maximum tracker limit reached!\n");
        return;
    }
    
    FitnessTracker newTracker;
    printf("Enter the name of the tracker: ");
    scanf("%s", newTracker.name);
    
    newTracker.steps = 0;
    newTracker.distance = 0.0;
    newTracker.calories = 0;
    newTracker.waterIntake = 0;

    trackers[*count] = newTracker;
    (*count)++;
    printf("Tracker %s added successfully!\n", newTracker.name);
}

void updateTracker(FitnessTracker *trackers, int count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the tracker to update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(trackers[i].name, name) == 0) {
            printf("Updating tracker for %s:\n", trackers[i].name);
            printf("Enter steps taken: ");
            scanf("%d", &trackers[i].steps);
            printf("Enter distance travelled (in km): ");
            scanf("%f", &trackers[i].distance);
            printf("Enter calories burned: ");
            scanf("%d", &trackers[i].calories);
            printf("Enter water intake (in liters): ");
            scanf("%d", &trackers[i].waterIntake);
            printf("Tracker %s updated successfully!\n", trackers[i].name);
            return;
        }
    }

    printf("Tracker with name %s not found!\n", name);
}

void displayTrackers(FitnessTracker *trackers, int count) {
    if (count == 0) {
        printf("No trackers available.\n");
        return;
    }

    printf("Fitness Trackers:\n");
    for (int i = 0; i < count; i++) {
        printf("--------------------------------------------------\n");
        printf("Tracker Name: %s\n", trackers[i].name);
        printf("Steps: %d\n", trackers[i].steps);
        printf("Distance: %.2f km\n", trackers[i].distance);
        printf("Calories: %d kcal\n", trackers[i].calories);
        printf("Water Intake: %d L\n", trackers[i].waterIntake);
    }
    printf("--------------------------------------------------\n");
}

void deleteTracker(FitnessTracker *trackers, int *count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the tracker to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(trackers[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                trackers[j] = trackers[j + 1];
            }
            (*count)--;
            printf("Tracker %s deleted successfully!\n", name);
            return;
        }
    }

    printf("Tracker with name %s not found!\n", name);
}

int main() {
    FitnessTracker trackers[MAX_TRACKERS];
    int count = 0;
    int choice;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Tracker\n");
        printf("2. Update Tracker\n");
        printf("3. Display Trackers\n");
        printf("4. Delete Tracker\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTracker(trackers, &count);
                break;
            case 2:
                updateTracker(trackers, count);
                break;
            case 3:
                displayTrackers(trackers, count);
                break;
            case 4:
                deleteTracker(trackers, &count);
                break;
            case 5:
                printf("Exiting the fitness tracker program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}