//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ACTIVITIES 5
#define MAX_NAME_LENGTH 20
#define MAX_CALORIES 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int calories_consumed;
    int calories_burned;
} Activity;

void print_menu();
void add_activity(Activity activities[], int *num_activities);
int get_calorie_balance(Activity activities[], int num_activities);

int main() {
    Activity activities[MAX_ACTIVITIES];
    int num_activities = 0;

    while (true) {
        print_menu();
        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_activity(activities, &num_activities);
                break;
            case 2:
                printf("Total Calorie Balance: %d\n", get_calorie_balance(activities, num_activities));
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add an activity\n");
    printf("2. View total calorie balance\n");
    printf("3. Exit\n");
}

void add_activity(Activity activities[], int *num_activities) {
    if (*num_activities >= MAX_ACTIVITIES) {
        printf("Maximum number of activities reached. Please add or remove activities to continue.\n");
        return;
    }

    printf("Enter the name of the activity: ");
    scanf("%s", activities[*num_activities].name);

    printf("Enter the calories consumed for this activity: ");
    scanf("%d", &activities[*num_activities].calories_consumed);

    printf("Enter the calories burned during this activity: ");
    scanf("%d", &activities[*num_activities].calories_burned);

    (*num_activities)++;
}

int get_calorie_balance(Activity activities[], int num_activities) {
    int total_calories_consumed = 0;
    int total_calories_burned = 0;

    for (int i = 0; i < num_activities; i++) {
        total_calories_consumed += activities[i].calories_consumed;
        total_calories_burned += activities[i].calories_burned;
    }

    return total_calories_burned - total_calories_consumed;
}