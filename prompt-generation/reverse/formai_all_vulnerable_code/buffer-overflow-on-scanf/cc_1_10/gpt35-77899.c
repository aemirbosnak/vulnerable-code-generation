//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

// Struct to represent a workout entry
typedef struct {
    int day;
    int month;
    int year;
    float duration;
    int calories;
} WorkoutEntry;

// Function to print a WorkoutEntry
void printWorkoutEntry(WorkoutEntry entry) {
    printf("Date: %d/%d/%d\n", entry.day, entry.month, entry.year);
    printf("Duration: %.2f minutes\n", entry.duration);
    printf("Calories burned: %d\n", entry.calories);
}

// Function to add a new workout entry
void addWorkoutEntry(WorkoutEntry entries[], int *entryCount) {
    printf("Enter date (dd mm yyyy) of workout: ");
    scanf("%d %d %d", &entries[*entryCount].day, &entries[*entryCount].month, &entries[*entryCount].year);

    printf("Enter duration of workout (in minutes): ");
    scanf("%f", &entries[*entryCount].duration);

    printf("Enter number of calories burned during workout: ");
    scanf("%d", &entries[*entryCount].calories);

    *entryCount += 1; // increment the count of entries
}

// Function to get the total duration of all workouts
float getTotalDuration(WorkoutEntry entries[], int entryCount) {
    float totalDuration = 0;

    for (int i = 0; i < entryCount; i++) {
        totalDuration += entries[i].duration;
    }

    return totalDuration;
}

// Function to get the average duration of workouts
float getAverageDuration(WorkoutEntry entries[], int entryCount) {
    float totalDuration = getTotalDuration(entries, entryCount);

    if (entryCount == 0) {
        return 0;
    } else {
        return totalDuration / entryCount;
    }
}

// Function to get the total number of calories burned
int getTotalCalories(WorkoutEntry entries[], int entryCount) {
    int totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalCalories += entries[i].calories;
    }

    return totalCalories;
}

// Function to get the highest number of calories burned in a single entry
int getHighestCalories(WorkoutEntry entries[], int entryCount) {
    int highestCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        if (entries[i].calories > highestCalories) {
            highestCalories = entries[i].calories;
        }
    }

    return highestCalories;
}

// Function to print the main menu
void printMenu() {
    printf("\nFitness Tracker\n");
    printf("================\n");
    printf("1. Add new workout entry\n");
    printf("2. View all workout entries\n");
    printf("3. Get total duration of all workouts\n");
    printf("4. Get average duration of all workouts\n");
    printf("5. Get total calories burned\n");
    printf("6. Get highest number of calories burned in a single entry\n");
    printf("7. Exit\n");
    printf("\nEnter your choice: ");
}

int main() {
    WorkoutEntry entries[100];
    int entryCount = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkoutEntry(entries, &entryCount);
                break;
            case 2:
                printf("\nAll Workout Entries\n");
                printf("====================\n");
                if (entryCount == 0) {
                    printf("No entries have been added yet\n");
                } else {
                    for (int i = 0; i < entryCount; i++) {
                        printWorkoutEntry(entries[i]);
                        printf("\n");
                    }
                }
                break;
            case 3:
                printf("\nTotal Duration: %.2f minutes\n", getTotalDuration(entries, entryCount));
                break;
            case 4:
                printf("\nAverage Duration: %.2f minutes\n", getAverageDuration(entries, entryCount));
                break;
            case 5:
                printf("\nTotal Calories: %d\n", getTotalCalories(entries, entryCount));
                break;
            case 6:
                printf("\nHighest Number of Calories Burned in a Single Entry: %d\n", getHighestCalories(entries, entryCount));
                break;
            case 7:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}