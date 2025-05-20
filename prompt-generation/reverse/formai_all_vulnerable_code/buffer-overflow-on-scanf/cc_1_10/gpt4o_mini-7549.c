//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    int day;
    int steps;
    float distance; // in kilometers
    float calories; // burned
} ActivityRecord;

ActivityRecord records[MAX_ENTRIES];
int entry_count = 0;

void log_activity(int day, int steps, float distance, float calories) {
    if (entry_count >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached\n");
        return;
    }
    records[entry_count].day = day;
    records[entry_count].steps = steps;
    records[entry_count].distance = distance;
    records[entry_count].calories = calories;
    entry_count++;
}

void print_summary() {
    int total_steps = 0;
    float total_distance = 0.0;
    float total_calories = 0.0;

    printf("\nFITNESS TRACKER SUMMARY\n");
    printf("Day\tSteps\tDistance(km)\tCalories\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%d\t%d\t%.2f\t\t%.2f\n", records[i].day, records[i].steps, records[i].distance, records[i].calories);
        total_steps += records[i].steps;
        total_distance += records[i].distance;
        total_calories += records[i].calories;
    }

    printf("\nTotal Entries: %d\n", entry_count);
    printf("Total Steps: %d\n", total_steps);
    printf("Total Distance: %.2f km\n", total_distance);
    printf("Total Calories Burned: %.2f kcal\n", total_calories);
}

void print_statistics() {
    if (entry_count == 0) {
        printf("No data to calculate statistics.\n");
        return;
    }

    int total_steps = 0;
    float total_distance = 0.0;
    float total_calories = 0.0;

    for (int i = 0; i < entry_count; i++) {
        total_steps += records[i].steps;
        total_distance += records[i].distance;
        total_calories += records[i].calories;
    }

    printf("\nFITNESS TRACKER STATISTICS\n");
    printf("Average Steps per Entry: %.2f\n", (float)total_steps / entry_count);
    printf("Average Distance per Entry: %.2f km\n", total_distance / entry_count);
    printf("Average Calories Burned per Entry: %.2f kcal\n", total_calories / entry_count);
}

int main() {
    int choice;
    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Log Activity\n");
        printf("2. Print Summary\n");
        printf("3. Print Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int day, steps;
            float distance, calories;
            printf("Enter Day (1-30): ");
            scanf("%d", &day);
            printf("Enter Steps: ");
            scanf("%d", &steps);
            printf("Enter Distance (km): ");
            scanf("%f", &distance);
            printf("Enter Calories Burned: ");
            scanf("%f", &calories);
            log_activity(day, steps, distance, calories);
        } else if (choice == 2) {
            print_summary();
        } else if (choice == 3) {
            print_statistics();
        } else if (choice == 4) {
            printf("Exiting the program. Bye!\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}