//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Function to compare two activities based on their finish times
int compareActivities(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to select the maximum number of activities
void selectActivities(Activity arr[], int n) {
    // Sort activities by finish time
    qsort(arr, n, sizeof(Activity), compareActivities);
    
    // The first activity always gets selected
    int lastFinish = arr[0].finish;
    printf("Selected activities:\n");
    printf("Activity [%d, %d]\n", arr[0].start, arr[0].finish);
    
    // Iterate through the remaining activities
    for (int i = 1; i < n; i++) {
        // If this activity's start time is greater than or equal to
        // the last selected activity's finish time, select it
        if (arr[i].start >= lastFinish) {
            printf("Activity [%d, %d]\n", arr[i].start, arr[i].finish);
            lastFinish = arr[i].finish;
        }
    }
}

// Secure memory allocation function
Activity *allocateActivities(int n) {
    Activity *activities = (Activity *)malloc(n * sizeof(Activity));
    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return activities;
}

int main() {
    int n;

    // Input number of activities
    printf("Enter number of activities: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    Activity *activities = allocateActivities(n);

    // Input activities
    printf("Enter the start and finish times of the activities:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &activities[i].start, &activities[i].finish) != 2 ||
            activities[i].start < 0 || activities[i].finish <= activities[i].start) {
            fprintf(stderr, "Invalid activity times. Please enter valid start and finish times.\n");
            free(activities);
            return EXIT_FAILURE;
        }
    }

    // Selecting the maximum number of activities
    selectActivities(activities, n);
    
    // Free allocated memory
    free(activities);
    
    return EXIT_SUCCESS;
}