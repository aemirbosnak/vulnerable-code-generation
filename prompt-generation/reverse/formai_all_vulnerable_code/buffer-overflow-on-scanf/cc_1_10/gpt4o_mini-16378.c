//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACTIVITIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char activity_name[MAX_NAME_LENGTH];
    int duration; // in minutes
    float calories_per_minute; // calories burned per minute
} Activity;

Activity activities[MAX_ACTIVITIES];
int activity_count = 0;

void log_activity() {
    if (activity_count >= MAX_ACTIVITIES) {
        printf("Activity log is full!\n");
        return;
    }
    
    Activity new_activity;
    printf("Enter activity name: ");
    scanf("%s", new_activity.activity_name);
    
    printf("Enter duration (in minutes): ");
    scanf("%d", &new_activity.duration);
    
    printf("Enter calories burned per minute: ");
    scanf("%f", &new_activity.calories_per_minute);
    
    activities[activity_count] = new_activity;
    activity_count++;
    
    printf("Activity logged successfully!\n");
}

void view_activities() {
    if (activity_count == 0) {
        printf("No activities logged yet!\n");
        return;
    }
    
    printf("\nYour Activities:\n");
    printf("%-20s %-10s %-10s\n", "Activity Name", "Duration", "Calories");
    for (int i = 0; i < activity_count; i++) {
        float total_calories = activities[i].duration * activities[i].calories_per_minute;
        printf("%-20s %-10d %-10.2f\n", activities[i].activity_name, activities[i].duration, total_calories);
    }

    printf("\nTotal activities logged: %d\n", activity_count);
}

void calculate_total_calories() {
    float total_calories_burned = 0.0;
    
    for (int i = 0; i < activity_count; i++) {
        total_calories_burned += activities[i].duration * activities[i].calories_per_minute;
    }
    
    printf("Total calories burned: %.2f\n", total_calories_burned);
}

void menu() {
    int choice;
    
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Log Activity\n");
        printf("2. View Activities\n");
        printf("3. Calculate Total Calories Burned\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log_activity();
                break;
            case 2:
                view_activities();
                break;
            case 3:
                calculate_total_calories();
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");
    menu();
    return 0;
}