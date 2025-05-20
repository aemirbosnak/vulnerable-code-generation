//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the structure for an activity
typedef struct {
    char name[50];
    int duration;
    time_t start_time;
    time_t end_time;
} Activity;

// Function to compare two activities based on their start times
int compare_activities(const void *a, const void *b) {
    const Activity *activity_a = (const Activity *)a;
    const Activity *activity_b = (const Activity *)b;

    return difftime(activity_a->start_time, activity_b->start_time);
}

// Function to print the details of all tracked activities
void print_activities(Activity activities[], int num_activities) {
    qsort(activities, num_activities, sizeof(Activity), compare_activities);

    printf("Activity Log:\n");
    for (int i = 0; i < num_activities; i++) {
        printf("%s - %d minutes - %s to %s\n", activities[i].name, activities[i].duration, ctime(&activities[i].start_time), ctime(&activities[i].end_time));
    }
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Initialize the array of activities
    Activity activities[MAX_ACTIVITIES];
    int num_activities = 0;

    // Start the fitness tracker
    printf("Welcome to the Sherlock Holmes Fitness Tracker!\n");
    while (1) {
        printf("Enter an activity (or 'quit' to exit):\n");
        scanf("%s", activities[num_activities].name);

        if (strcmp(activities[num_activities].name, "quit") == 0) {
            break;
        }

        activities[num_activities].duration = rand() % 61 + 1; // Random duration between 1 and 60 minutes
        activities[num_activities].start_time = time(NULL);
        getchar(); // Consume newline character

        while (1) {
            printf("Press enter when finished with %s:\n", activities[num_activities].name);
            scanf("%*c");
            activities[num_activities].end_time = time(NULL);
            activities[num_activities].duration = difftime(activities[num_activities].end_time, activities[num_activities].start_time);
            num_activities++;
            break;
        }
    }

    // Print the summary of tracked activities
    printf("\nFitness Summary:\n");
    print_activities(activities, num_activities);

    return 0;
}