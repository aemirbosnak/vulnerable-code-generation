//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACTIVITIES 10
#define STEPS_PER_DAY 10000

typedef struct {
    char name[30];
    int steps;
    time_t time;
} Activity;

Activity activities[MAX_ACTIVITIES];
int num_activities = 0;

void print_menu() {
    printf("\n---- Fitness Tracker ----\n");
    printf("1. Record Activity\n");
    printf("2. View Activities\n");
    printf("3. View Statistics\n");
    printf("4. Quit\n");
}

void record_activity() {
    if (num_activities >= MAX_ACTIVITIES) {
        printf("Max activities reached, please delete old ones first.\n");
        return;
    }

    Activity *new_activity = &activities[num_activities];

    printf("Enter name of activity: ");
    scanf("%s", new_activity->name);

    new_activity->steps = 0;

    time_t now = time(NULL);
    new_activity->time = now;

    printf("Activity recorded successfully.\n");
    num_activities++;
}

void view_activities() {
    if (num_activities == 0) {
        printf("No activities recorded yet.\n");
        return;
    }

    printf("\n---- Activities ----\n");
    for (int i = 0; i < num_activities; i++) {
        Activity *activity = &activities[i];
        printf("%d. %s - %s\n", i+1, activity->name, ctime(&activity->time));
    }
}

void view_statistics() {
    int total_steps = 0;

    for (int i = 0; i < num_activities; i++) {
        Activity *activity = &activities[i];
        total_steps += activity->steps;
    }

    int daily_avg = total_steps / num_activities;
    double percentage_of_goal = ((double)total_steps / (double)STEPS_PER_DAY) * 100;

    printf("\n---- Statistics ----\n");
    printf("Total steps: %d\n", total_steps);
    printf("Daily average: %d\n", daily_avg);
    printf("Percentage of goal: %.2f%%\n", percentage_of_goal);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                record_activity();
                break;
            case 2:
                view_activities();
                break;
            case 3:
                view_statistics();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}