//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACTIVITIES 100
#define ACTIVITY_NAME_LEN 30
#define FILENAME "fitness_tracker.dat"

typedef struct {
    char name[ACTIVITY_NAME_LEN];
    int duration; // in minutes
    int calories_burnt; // calories burnt
} Activity;

Activity activities[MAX_ACTIVITIES];
int activity_count = 0;

void load_activities() {
    FILE *file = fopen(FILENAME, "rb");
    if (file) {
        fread(&activity_count, sizeof(int), 1, file);
        fread(activities, sizeof(Activity), activity_count, file);
        fclose(file);
    }
}

void save_activities() {
    FILE *file = fopen(FILENAME, "wb");
    if (file) {
        fwrite(&activity_count, sizeof(int), 1, file);
        fwrite(activities, sizeof(Activity), activity_count, file);
        fclose(file);
    }
}

void add_activity() {
    if (activity_count < MAX_ACTIVITIES) {
        Activity new_activity;
        printf("Enter activity name: ");
        scanf("%s", new_activity.name);
        printf("Enter duration (in minutes): ");
        scanf("%d", &new_activity.duration);
        printf("Enter calories burnt: ");
        scanf("%d", &new_activity.calories_burnt);

        activities[activity_count] = new_activity;
        activity_count++;
        save_activities();
        printf("Activity added successfully!\n");
    } else {
        printf("Activity limit reached. Cannot add more activities.\n");
    }
}

void display_activities() {
    printf("\n--- Activity Log ---\n");
    for (int i = 0; i < activity_count; i++) {
        printf("Activity: %s | Duration: %d min | Calories: %d\n",
               activities[i].name,
               activities[i].duration,
               activities[i].calories_burnt);
    }
}

void display_statistics() {
    int total_duration = 0;
    int total_calories = 0;

    for (int i = 0; i < activity_count; i++) {
        total_duration += activities[i].duration;
        total_calories += activities[i].calories_burnt;
    }

    printf("\n--- Statistics ---\n");
    printf("Total Duration: %d minutes\n", total_duration);
    printf("Total Calories Burnt: %d calories\n", total_calories);
}

void menu() {
    int choice;

    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Activity\n");
        printf("2. Display Activities\n");
        printf("3. Display Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_activity();
                break;
            case 2:
                display_activities();
                break;
            case 3:
                display_statistics();
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay healthy!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    load_activities();
    menu();
    return 0;
}