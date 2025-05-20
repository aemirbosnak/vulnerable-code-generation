//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_NAME_LENGTH 50
#define MAX_ACTIVITY_DURATION 24 * 60 * 60 // 1 day in seconds

typedef struct {
    char name[MAX_ACTIVITY_NAME_LENGTH];
    int duration;
} Activity;

int main() {
    int num_activities;
    Activity activities[MAX_ACTIVITIES];
    char input_buffer[100];
    int i, j;

    printf("Welcome to the Fitness Tracker!\n");
    printf("How many activities do you want to track? ");
    scanf("%d", &num_activities);

    for (i = 0; i < num_activities; i++) {
        printf("Enter activity name #%d: ", i + 1);
        scanf("%s", activities[i].name);
        activities[i].duration = 0;
    }

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Start an activity\n");
        printf("2. Stop an activity\n");
        printf("3. View activity report\n");
        printf("4. Exit\n");
        scanf("%d", &i);

        switch (i) {
        case 1:
            printf("Enter activity name: ");
            scanf("%s", input_buffer);
            for (j = 0; j < num_activities; j++) {
                if (strcmp(input_buffer, activities[j].name) == 0) {
                    activities[j].duration = 0;
                    break;
                }
            }
            if (j == num_activities) {
                printf("Activity not found.\n");
            }
            break;
        case 2:
            printf("Enter activity name: ");
            scanf("%s", input_buffer);
            for (j = 0; j < num_activities; j++) {
                if (strcmp(input_buffer, activities[j].name) == 0) {
                    printf("Duration: %d seconds\n", activities[j].duration);
                    break;
                }
            }
            if (j == num_activities) {
                printf("Activity not found.\n");
            }
            break;
        case 3:
            printf("Activity Report:\n");
            for (j = 0; j < num_activities; j++) {
                printf("Name: %s\n", activities[j].name);
                printf("Duration: %d seconds\n\n", activities[j].duration);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}