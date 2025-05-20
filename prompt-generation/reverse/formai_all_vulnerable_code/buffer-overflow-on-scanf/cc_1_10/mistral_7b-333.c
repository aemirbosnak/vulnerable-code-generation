//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACTIVITIES 10
#define MAX_STEPS 10000

typedef struct {
    char name[50];
    int steps;
    time_t timestamp;
} Activity;

Activity activities[MAX_ACTIVITIES];
int activity_count = 0;

void print_menu() {
    printf("----------------------------------\n");
    printf("| Fitness Tracker v1.0            |\n");
    printf("----------------------------------\n");
    printf("| 1. Start new activity           |\n");
    printf("| 2. Display activities           |\n");
    printf("| 3. Display statistics           |\n");
    printf("| 4. Exit                         |\n");
    printf("----------------------------------\n");
}

int get_valid_option() {
    int choice;
    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("Invalid option, please try again: ");
        fflush(stdin);
    }
    return choice;
}

void start_activity(char *name) {
    time_t current_time = time(NULL);
    Activity new_activity = {name, 0, current_time};
    if (activity_count < MAX_ACTIVITIES) {
        activities[activity_count] = new_activity;
        activity_count++;
        printf("New activity started: %s\n", name);
    } else {
        printf("Maximum number of activities reached.\n");
    }
}

void display_activities() {
    if (activity_count == 0) {
        printf("No activities recorded.\n");
        return;
    }
    printf("Activities:\n");
    for (int i = 0; i < activity_count; i++) {
        printf("%d. %s - %s\n", i+1, activities[i].name, ctime(&activities[i].timestamp));
    }
}

void display_statistics() {
    int total_steps = 0;
    for (int i = 0; i < activity_count; i++) {
        total_steps += activities[i].steps;
    }
    printf("Total steps: %d\n", total_steps);
}

int main() {
    char activity_name[50];
    int choice;

    while (1) {
        print_menu();
        choice = get_valid_option();

        switch(choice) {
            case 1:
                printf("Enter name for new activity: ");
                scanf("%s", activity_name);
                start_activity(activity_name);
                break;
            case 2:
                display_activities();
                break;
            case 3:
                display_statistics();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                break;
        }
    }

    return 0;
}