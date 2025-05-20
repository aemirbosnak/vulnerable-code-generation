//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the structure for an activity
typedef struct {
    int start;
    int finish;
} Activity;

// Function to compare two activities based on their finishing times
int compareActivities(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

// Function to select the maximum number of activities that can be performed
void selectActivities(Activity activities[], int n) {
    // Sort the activities based on their finish time
    qsort(activities, n, sizeof(Activity), compareActivities);

    // The first activity always gets selected
    int i = 0;
    printf("Selected activities: \n");
    printf("Activity [%d]: Start: %d, Finish: %d\n", i, activities[i].start, activities[i].finish);

    // Go through the remaining activities
    for (int j = 1; j < n; j++) {
        // If this activity starts after or when the last selected one finishes
        if (activities[j].start >= activities[i].finish) {
            printf("Activity [%d]: Start: %d, Finish: %d\n", j, activities[j].start, activities[j].finish);
            i = j; // Update the last selected activity
        }
    }
}

int main() {
    // Number of activities
    int n;

    // Input: Number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Dynamically allocate memory for activities
    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    // Input: Start and finish times of the activities
    for (int i = 0; i < n; i++) {
        printf("Enter start time and finish time for activity %d: ", i);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Select and print the maximum set of activities
    selectActivities(activities, n);

    // Free the dynamically allocated memory
    free(activities);

    return 0;
}