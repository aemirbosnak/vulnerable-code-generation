//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DAYS 30

typedef struct {
    int steps;
    int calories;
    float distance;
} FitnessData;

void display_menu() {
    printf("\n*** Welcome to FitBuddy! ***\n");
    printf("1. Record new fitness data\n");
    printf("2. View progress report\n");
    printf("3. Quit\n");
}

FitnessData daily_data[MAX_DAYS];
int current_day = 0;

void record_fitness_data() {
    time_t now;
    struct tm *local;

    time(&now);
    local = localtime(&now);

    printf("\nRecording fitness data for day %d (%s %d)\n", current_day + 1, asctime(local), local->tm_mday);
    printf("Enter number of steps: ");
    scanf("%d", &daily_data[current_day].steps);
    printf("Enter number of calories burned: ");
    scanf("%d", &daily_data[current_day].calories);

    daily_data[current_day].distance = daily_data[current_day].steps * 0.00528; // 1 mile = 2000 steps, 1 mile = 5280 feet
    current_day++;
}

void view_progress_report() {
    if (current_day == 0) {
        printf("\nYou have not recorded any fitness data yet!\n");
        return;
    }

    printf("\n----------------------------------------------------\n");
    printf("| Day | Steps | Calories | Distance (miles) |\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < current_day; i++) {
        printf("| %d   | %d     | %d        | %0.2f        |\n", i + 1, daily_data[i].steps, daily_data[i].calories, daily_data[i].distance);
    }
    printf("----------------------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                record_fitness_data();
                break;
            case 2:
                view_progress_report();
                break;
            case 3:
                printf("\nThanks for using FitBuddy! Have a great day!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}