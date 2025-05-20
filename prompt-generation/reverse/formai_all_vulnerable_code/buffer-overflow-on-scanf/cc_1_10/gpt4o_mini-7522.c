//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Comparator function for qsort to sort activities based on their finish time
int compareActivities(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to determine the maximum number of activities that can be performed
void printMaxActivities(Activity activities[], int n) {
    // Sort activities based on their finish time
    qsort(activities, n, sizeof(Activity), compareActivities);

    printf("Following activities can be performed:\n");

    // The first activity always gets selected
    int lastSelectedActivity = 0;
    printf("Activity %d: (%d, %d)\n", lastSelectedActivity + 1, activities[lastSelectedActivity].start, activities[lastSelectedActivity].finish);

    // Iterate through the sorted activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity finishes, select it
        if (activities[i].start >= activities[lastSelectedActivity].finish) {
            printf("Activity %d: (%d, %d)\n", i + 1, activities[i].start, activities[i].finish);
            lastSelectedActivity = i; // Update the last selected activity
        }
    }
}

int main() {
    // Define the number of activities
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Allocate memory for activities
    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    // Input activities from the user
    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time for activity %d (formatted as start finish): ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);

        // Validate input
        if (activities[i].start >= activities[i].finish) {
            printf("Invalid activity timings. Start time must be less than finish time.\n");
            free(activities);
            return -1;
        }
    }

    // Function call to print maximum number of activities
    printMaxActivities(activities, n);

    // Free allocated memory
    free(activities);

    return 0;
}