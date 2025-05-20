//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct Activity {
    int start;
    int end;
} Activity;

// Function to compare two activities based on their finish time
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->end - activityB->end;
}

// Function to select the maximum number of activities that don't overlap
void activitySelection(Activity activities[], int n) {
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(Activity), compare);

    int count = 1;  // The first activity is always selected
    int lastSelectedEndTime = activities[0].end;

    printf("Selected activities:\n");
    printf("Activity 1: Start: %d, End: %d\n", activities[0].start, activities[0].end);

    // Iterate through the rest of the activities
    for (int i = 1; i < n; i++) {
        // If this activity's start time is greater than or equal to the last selected activity's end time
        if (activities[i].start >= lastSelectedEndTime) {
            printf("Activity %d: Start: %d, End: %d\n", i + 1, activities[i].start, activities[i].end);
            lastSelectedEndTime = activities[i].end;  // Update the end time
            count++;
        }
    }

    printf("Total number of activities selected: %d\n", count);
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Input activities
    printf("Enter activities (start time and end time):\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }

    // Call the activity selection function
    activitySelection(activities, n);

    // Free allocated memory
    free(activities);

    return 0;
}