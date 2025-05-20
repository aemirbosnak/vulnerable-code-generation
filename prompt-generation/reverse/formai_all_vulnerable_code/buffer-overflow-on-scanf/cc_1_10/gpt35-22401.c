//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct Fitness_Entry {
    char date[11];
    double weight;
    int calories;
    int steps;
};

typedef struct Fitness_Entry Fitness_Entry;

int num_entries = 0;
Fitness_Entry entries[MAX_ENTRIES];

void display_menu() {
    printf("Fitness Tracker Menu\n");
    printf("1. Enter new entry\n");
    printf("2. View all entries\n");
    printf("3. View entries for a specific date\n");
    printf("4. View average weight\n");
    printf("5. View average calories burned\n");
    printf("6. View average steps\n");
    printf("0. Exit\n");
    printf("Please enter your choice: ");
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached\n");
        return;
    }

    Fitness_Entry entry;

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", entry.date);

    printf("Enter weight (in pounds): ");
    scanf("%lf", &entry.weight);

    printf("Enter calories burned: ");
    scanf("%d", &entry.calories);

    printf("Enter steps taken: ");
    scanf("%d", &entry.steps);

    entries[num_entries++] = entry;

    printf("Entry added successfully\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("There are no entries to display\n");
        return;
    }

    printf("%-15s %-15s %-15s %-15s\n", "Date", "Weight (lbs)", "Calories burned", "Steps taken");

    for (int i = 0; i < num_entries; i++) {
        Fitness_Entry entry = entries[i];

        printf("%-15s %-15.2lf %-15d %-15d\n", entry.date, entry.weight, entry.calories, entry.steps);
    }
}

void view_entries_for_date() {
    if (num_entries == 0) {
        printf("There are no entries to display\n");
        return;
    }

    char date[11];
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", date);

    printf("%-15s %-15s %-15s %-15s\n", "Date", "Weight (lbs)", "Calories burned", "Steps taken");

    for (int i = 0; i < num_entries; i++) {
        Fitness_Entry entry = entries[i];

        if (strcmp(entry.date, date) == 0) {
            printf("%-15s %-15.2lf %-15d %-15d\n", entry.date, entry.weight, entry.calories, entry.steps);
        }
    }
}

void view_average_weight() {
    if (num_entries == 0) {
        printf("There are no entries to display\n");
        return;
    }

    double sum = 0;

    for (int i = 0; i < num_entries; i++) {
        sum += entries[i].weight;
    }

    printf("Average weight: %.2lf lbs\n", sum/num_entries);
}

void view_average_calories() {
    if (num_entries == 0) {
        printf("There are no entries to display\n");
        return;
    }

    int sum = 0;

    for (int i = 0; i < num_entries; i++) {
        sum += entries[i].calories;
    }

    printf("Average calories burned: %d\n", sum/num_entries);
}

void view_average_steps() {
    if (num_entries == 0) {
        printf("There are no entries to display\n");
        return;
    }

    int sum = 0;

    for (int i = 0; i < num_entries; i++) {
        sum += entries[i].steps;
    }

    printf("Average steps taken: %d\n", sum/num_entries);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exiting program...\n");
            exit(0);
        case 1:
            add_entry();
            break;
        case 2:
            view_entries();
            break;
        case 3:
            view_entries_for_date();
            break;
        case 4:
            view_average_weight();
            break;
        case 5:
            view_average_calories();
            break;
        case 6:
            view_average_steps();
            break;
        default:
            printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}