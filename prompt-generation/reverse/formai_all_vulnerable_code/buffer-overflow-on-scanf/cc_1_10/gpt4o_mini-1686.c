//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

// Comparison function to sort activities by their end time
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->end - activityB->end;
}

// Function to perform the activity selection
void selectActivities(Activity activities[], int n) {
    // Sort activities by end time
    qsort(activities, n, sizeof(Activity), compare);

    // The first activity always gets selected
    int i = 0;
    printf("Selected Activities:\n");
    printf("Activity %d (Start: %d, End: %d)\n", i + 1, activities[i].start, activities[i].end);

    // The last selected activity's end time
    int lastEndTime = activities[i].end;

    // Iterate over the remaining activities
    for (int j = 1; j < n; j++) {
        // If the start time of this activity is greater than or
        // equal to the end time of the last selected activity
        if (activities[j].start >= lastEndTime) {
            printf("Activity %d (Start: %d, End: %d)\n", j + 1, activities[j].start, activities[j].end);
            lastEndTime = activities[j].end; // Update last end time
            i++;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity *activities = malloc(n * sizeof(Activity));
    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input the start and end times of activities
    printf("Enter the start and end times of each activity (start end):\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }

    // Perform the activity selection
    selectActivities(activities, n);

    // Free allocated memory
    free(activities);

    return 0;
}