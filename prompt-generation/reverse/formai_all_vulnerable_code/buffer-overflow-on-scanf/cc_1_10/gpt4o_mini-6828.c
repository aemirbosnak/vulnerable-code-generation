//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int steps;
    float distance; // in kilometers
    float calories; // in kilocalories
} Activity;

void input_activity(Activity* activity) {
    printf("Enter steps taken today: ");
    scanf("%d", &activity->steps);
    printf("Enter distance traveled (in km): ");
    scanf("%f", &activity->distance);
    printf("Enter calories burned: ");
    scanf("%f", &activity->calories);
}

void display_activity(const Activity* activity) {
    printf("\n--- Today's Activity Summary ---\n");
    printf("Steps: %d\n", activity->steps);
    printf("Distance: %.2f km\n", activity->distance);
    printf("Calories burned: %.2f kcal\n", activity->calories);
}

void weekly_summary(Activity* activities, int days) {
    int total_steps = 0;
    float total_distance = 0.0f;
    float total_calories = 0.0f;

    for (int i = 0; i < days; i++) {
        total_steps += activities[i].steps;
        total_distance += activities[i].distance;
        total_calories += activities[i].calories;
    }

    printf("\n--- Weekly Activity Summary ---\n");
    printf("Total Steps: %d\n", total_steps);
    printf("Total Distance: %.2f km\n", total_distance);
    printf("Total Calories burned: %.2f kcal\n", total_calories);
}

int main() {
    const int MAX_DAYS = 7;
    Activity activities[MAX_DAYS];
    int day_count = 0;
    int option;

    while (1) {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Log today's activity\n");
        printf("2. View today's activity\n");
        printf("3. View weekly summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (day_count < MAX_DAYS) {
                    input_activity(&activities[day_count]);
                    day_count++;
                } else {
                    printf("You can only log activity for up to 7 days!\n");
                }
                break;
            case 2:
                if (day_count > 0) {
                    display_activity(&activities[day_count - 1]);
                } else {
                    printf("No activity logged for today.\n");
                }
                break;
            case 3:
                if (day_count > 0) {
                    weekly_summary(activities, day_count);
                } else {
                    printf("No activity logged for the week.\n");
                }
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}