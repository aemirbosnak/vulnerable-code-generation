//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct fitness_activity {
    char name[MAX_SIZE];
    int duration;
    int calories_burned;
};

void print_menu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Activity\n");
    printf("2. View Activities\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    int num_activities = 0;
    struct fitness_activity activities[MAX_SIZE];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_activities >= MAX_SIZE) {
                printf("Cannot add more activities.\n");
            } else {
                char name[MAX_SIZE];
                int duration, calories_burned;

                printf("Enter activity name: ");
                scanf("%s", name);

                printf("Enter activity duration (in minutes): ");
                scanf("%d", &duration);

                printf("Enter activity calories burned: ");
                scanf("%d", &calories_burned);

                strcpy(activities[num_activities].name, name);
                activities[num_activities].duration = duration;
                activities[num_activities].calories_burned = calories_burned;

                num_activities++;
            }
            break;

        case 2:
            if (num_activities == 0) {
                printf("No activities found.\n");
            } else {
                printf("Fitness Activities:\n");
                for (int i = 0; i < num_activities; i++) {
                    printf("%s: %d minutes, %d calories\n", activities[i].name, activities[i].duration, activities[i].calories_burned);
                }
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}