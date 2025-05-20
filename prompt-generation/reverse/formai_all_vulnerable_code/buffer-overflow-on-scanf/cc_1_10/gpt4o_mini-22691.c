//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    time_t date;
    double steps;
    double distance;
    double calories;
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry(double steps, double distance, double calories) {
    if (entry_count < MAX_ENTRIES) {
        entries[entry_count].date = time(NULL);
        entries[entry_count].steps = steps;
        entries[entry_count].distance = distance;
        entries[entry_count].calories = calories;
        entry_count++;
        printf("Entry added successfully!\n");
    } else {
        printf("Entry limit reached!\n");
    }
}

void display_entries() {
    printf("Fitness Tracker Entries:\n");
    printf("Date\t\t\tSteps\tDistance(m)\tCalories\n");
    for (int i = 0; i < entry_count; i++) {
        char date_str[50];
        struct tm *tm_info = localtime(&entries[i].date);
        strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s\t%.0f\t%.2f\t\t%.2f\n", date_str, entries[i].steps, entries[i].distance, entries[i].calories);
    }
}

void calculate_summary() {
    double total_steps = 0, total_distance = 0, total_calories = 0;

    for (int i = 0; i < entry_count; i++) {
        total_steps += entries[i].steps;
        total_distance += entries[i].distance;
        total_calories += entries[i].calories;
    }

    printf("Fitness Summary:\n");
    printf("Total Steps: %.0f\n", total_steps);
    printf("Total Distance: %.2f m\n", total_distance);
    printf("Total Calories: %.2f kcal\n", total_calories);
}

void display_menu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Fitness Entry\n");
    printf("2. Display Entries\n");
    printf("3. Calculate Summary\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    double steps, distance, calories;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Steps: ");
                scanf("%lf", &steps);
                printf("Enter Distance (m): ");
                scanf("%lf", &distance);
                printf("Enter Calories: ");
                scanf("%lf", &calories);
                add_entry(steps, distance, calories);
                break;
            case 2:
                display_entries();
                break;
            case 3:
                calculate_summary();
                break;
            case 4:
                printf("Exiting Fitness Tracker. Stay active!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}