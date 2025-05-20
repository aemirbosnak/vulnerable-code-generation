//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    float distance; // in kilometers
    int calories; // calories burned
    int steps; // number of steps taken
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Cannot add more entries. Max limit reached.\n");
        return;
    }

    FitnessEntry new_entry;
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    printf("Adding new fitness entry...\n");
    printf("Date (YYYY-MM-DD): ");
    scanf("%10s", new_entry.date);
    printf("Distance (in km): ");
    scanf("%f", &new_entry.distance);
    printf("Calories burned: ");
    scanf("%d", &new_entry.calories);
    printf("Steps taken: ");
    scanf("%d", &new_entry.steps);

    entries[entry_count] = new_entry;
    entry_count++;

    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No fitness entries found.\n");
        return;
    }

    printf("Fitness Entries:\n");
    printf("---------------------------------------------------\n");
    printf("| Date       | Distance (km) | Calories | Steps   |\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < entry_count; i++) {
        FitnessEntry e = entries[i];
        printf("| %s | %.2f         | %d      | %d      |\n", e.date, e.distance, e.calories, e.steps);
    }
    printf("---------------------------------------------------\n");
}

void calculate_statistics() {
    if (entry_count == 0) {
        printf("No entries to calculate statistics.\n");
        return;
    }

    float total_distance = 0.0;
    int total_calories = 0;
    int total_steps = 0;

    for (int i = 0; i < entry_count; i++) {
        total_distance += entries[i].distance;
        total_calories += entries[i].calories;
        total_steps += entries[i].steps;
    }

    printf("Fitness Statistics:\n");
    printf("---------------------------------------------------\n");
    printf("Total Distance (km): %.2f\n", total_distance);
    printf("Total Calories Burned: %d\n", total_calories);
    printf("Total Steps Taken: %d\n", total_steps);
    printf("Average Distance (km): %.2f\n", total_distance / entry_count);
    printf("Average Calories Burned: %.2f\n", (float)total_calories / entry_count);
    printf("Average Steps Taken: %.2f\n", (float)total_steps / entry_count);
    printf("---------------------------------------------------\n");
}

void save_entries_to_file() {
    FILE *file = fopen("fitness_entries.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        FitnessEntry e = entries[i];
        fprintf(file, "%s %.2f %d %d\n", e.date, e.distance, e.calories, e.steps);
    }

    fclose(file);
    printf("Entries saved to fitness_entries.txt successfully!\n");
}

void load_entries_from_file() {
    FILE *file = fopen("fitness_entries.txt", "r");
    if (!file) {
        printf("No saved entries found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%10s %f %d %d", entries[entry_count].date, 
          &entries[entry_count].distance, &entries[entry_count].calories, &entries[entry_count].steps) == 4) {
        entry_count++;
        if (entry_count >= MAX_ENTRIES) break; // Prevent overflow
    }

    fclose(file);
    printf("Entries loaded successfully! [Total: %d]\n", entry_count);
}

void display_menu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Fitness Entry\n");
    printf("2. View Fitness Entries\n");
    printf("3. Calculate Statistics\n");
    printf("4. Save Entries to File\n");
    printf("5. Load Entries from File\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    load_entries_from_file();
    
    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                calculate_statistics();
                break;
            case 4:
                save_entries_to_file();
                break;
            case 5:
                load_entries_from_file();
                break;
            case 6:
                printf("Exiting the fitness tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select again.\n");
        }
    }

    return 0;
}