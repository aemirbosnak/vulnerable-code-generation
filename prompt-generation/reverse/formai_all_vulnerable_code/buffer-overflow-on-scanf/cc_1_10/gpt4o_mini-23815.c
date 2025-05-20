//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int steps;
    float calories;
    int exercise_time; // in minutes
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more.\n");
        return;
    }

    FitnessEntry new_entry;
    printf("Enter activity name: ");
    fgets(new_entry.name, MAX_NAME_LEN, stdin);
    new_entry.name[strcspn(new_entry.name, "\n")] = 0; // Remove newline

    printf("Enter steps taken: ");
    scanf("%d", &new_entry.steps);
    printf("Enter calories burnt: ");
    scanf("%f", &new_entry.calories);
    printf("Enter exercise time (minutes): ");
    scanf("%d", &new_entry.exercise_time);
    getchar(); // Consume newline after scanf

    entries[entry_count++] = new_entry;

    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d: Activity: %s, Steps: %d, Calories: %.2f, Exercise Time: %d mins\n",
               i + 1, entries[i].name, entries[i].steps, entries[i].calories, entries[i].exercise_time);
    }
}

void menu() {
    int choice;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Exiting the program. Keep fit!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

int main() {
    printf("Welcome to the C Fitness Tracker!\n");
    menu();
    return 0;
}