//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_NAME_LENGTH 20

typedef struct {
    char name[MAX_ACTIVITY_NAME_LENGTH];
    int duration;
    int calories;
} Activity;

void add_activity(Activity* activities, int num_activities, char* name, int duration, int calories) {
    for (int i = 0; i < num_activities; i++) {
        if (strcmp(activities[i].name, name) == 0) {
            activities[i].duration += duration;
            activities[i].calories += calories;
            return;
        }
    }
    activities[num_activities] = (Activity) {.name = name,.duration = duration,.calories = calories};
    num_activities++;
}

void print_summary(Activity* activities, int num_activities) {
    printf("Total activities: %d\n", num_activities);
    printf("Total duration: %d minutes\n", 0);
    printf("Total calories burned: %d\n", 0);
    for (int i = 0; i < num_activities; i++) {
        printf("Activity %s: %d minutes, %d calories\n", activities[i].name, activities[i].duration, activities[i].calories);
        printf("Total duration: %d minutes\n", activities[i].duration);
        printf("Total calories burned: %d\n\n", activities[i].calories);
    }
}

int main() {
    srand(time(0));
    int num_activities = 0;
    Activity activities[MAX_ACTIVITIES];
    char activity_name[MAX_ACTIVITY_NAME_LENGTH];

    while (1) {
        printf("Enter activity name (or 'exit' to quit): ");
        scanf("%s", activity_name);
        if (strcmp(activity_name, "exit") == 0) {
            break;
        }
        printf("Enter duration in minutes: ");
        int duration = rand() % 60 + 1;
        printf("Enter calories burned: ");
        int calories = rand() % 100 + 1;
        add_activity(activities, num_activities, activity_name, duration, calories);
        num_activities++;
    }

    print_summary(activities, num_activities);

    return 0;
}