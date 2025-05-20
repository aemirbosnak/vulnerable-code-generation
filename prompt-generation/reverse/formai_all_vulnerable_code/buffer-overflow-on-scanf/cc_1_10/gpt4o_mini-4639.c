//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    int calories; // in kcal
    time_t date; // Store date in UNIX timestamp
} FitnessEntry;

void displayMenu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add New Entry\n");
    printf("2. View All Entries\n");
    printf("3. Calculate Total Steps\n");
    printf("4. Calculate Total Distance\n");
    printf("5. Calculate Total Calories\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void addEntry(FitnessEntry* entries, int* count) {
    if (*count >= MAX_ENTRIES) {
        printf("Max entries reached. Cannot add more.\n");
        return;
    }

    FitnessEntry newEntry;

    printf("Enter your name: ");
    fgets(newEntry.name, NAME_LENGTH, stdin);
    newEntry.name[strcspn(newEntry.name, "\n")] = 0; // Remove newline character

    printf("Enter steps taken: ");
    scanf("%d", &newEntry.steps);

    printf("Enter distance in kilometers: ");
    scanf("%f", &newEntry.distance);

    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);

    newEntry.date = time(NULL); // Current time as entry date

    entries[*count] = newEntry;
    (*count)++;

    printf("Entry added successfully!\n");
    getchar(); // Consume newline left by scanf
}

void viewEntries(FitnessEntry* entries, int count) {
    if (count == 0) {
        printf("No entries to show.\n");
        return;
    }
    printf("Fitness Tracker Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d: Name: %s, Steps: %d, Distance: %.2f km, Calories: %d, Date: %s",
            i + 1, entries[i].name, entries[i].steps, entries[i].distance, entries[i].calories,
            ctime(&entries[i].date)); // Convert date to readable format
    }
}

int calculateTotalSteps(FitnessEntry* entries, int count) {
    int totalSteps = 0;
    for (int i = 0; i < count; i++) {
        totalSteps += entries[i].steps;
    }
    return totalSteps;
}

float calculateTotalDistance(FitnessEntry* entries, int count) {
    float totalDistance = 0.0;
    for (int i = 0; i < count; i++) {
        totalDistance += entries[i].distance;
    }
    return totalDistance;
}

int calculateTotalCalories(FitnessEntry* entries, int count) {
    int totalCalories = 0;
    for (int i = 0; i < count; i++) {
        totalCalories += entries[i].calories;
    }
    return totalCalories;
}

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int count = 0;
    int option;

    do {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Consume newline left by scanf

        switch (option) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                printf("Total Steps: %d\n", calculateTotalSteps(entries, count));
                break;
            case 4:
                printf("Total Distance: %.2f km\n", calculateTotalDistance(entries, count));
                break;
            case 5:
                printf("Total Calories: %d kcal\n", calculateTotalCalories(entries, count));
                break;
            case 6:
                printf("Exiting the program. Have a healthy day!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (option != 6);

    return 0;
}