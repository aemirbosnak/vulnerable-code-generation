//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Comparator function to sort activities by their finish times
int compare(const void *a, const void *b) {
    Activity *activity1 = (Activity *)a;
    Activity *activity2 = (Activity *)b;
    return activity1->finish - activity2->finish;
}

// Function to perform the activity selection process
void activitySelection(Activity activities[], int n) {
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(Activity), compare);

    printf("Selected Activities:\n");

    // The first activity always gets selected
    int i = 0;
    printf("Activity %d: Start %d, Finish %d\n", i, activities[i].start, activities[i].finish);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        // If the start time of the current activity is greater than or equal
        // to the finish time of the last selected activity, select the current one
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d: Start %d, Finish %d\n", j, activities[j].start, activities[j].finish);
            i = j;  // Update the last selected activity
        }
    }
}

// Main function
int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of activities must be positive.\n");
        return 1;
    }

    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    printf("Enter the start and finish times of the activities (start finish):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);

        // Validate input
        if (activities[i].finish < activities[i].start) {
            printf("Finish time must be greater than or equal to start time for activity %d.\n", i);
            free(activities);
            return 1;
        }
    }

    // Perform activity selection
    activitySelection(activities, n);

    // Free allocated memory
    free(activities);

    return 0;
}