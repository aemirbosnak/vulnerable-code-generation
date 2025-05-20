//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start; // Start time of the activity
    int end;   // End time of the activity
} Activity;

// Comparator function to sort activities by their end times
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->end - activityB->end;
}

// Function to perform the activity selection using a greedy approach
void activitySelection(Activity activities[], int n) {
    // Sort the activities based on their ending times
    qsort(activities, n, sizeof(Activity), compare);
    
    // The first activity always gets selected
    int i = 0;
    printf("Selected activities:\n");
    printf("Activity %d: [%d, %d]\n", i + 1, activities[i].start, activities[i].end);

    // Iterate through the sorted activities
    for (int j = 1; j < n; j++) {
        // If the start time of the current activity is greater than
        // or equal to the end time of the last selected activity
        if (activities[j].start >= activities[i].end) {
            // Select the current activity
            printf("Activity %d: [%d, %d]\n", j + 1, activities[j].start, activities[j].end);
            i = j; // Update the index of the last selected activity
        }
    }
}

// Function to take input for activities
Activity *inputActivities(int *n) {
    printf("Enter the number of activities: ");
    scanf("%d", n);
    
    Activity *activities = (Activity *)malloc((*n) * sizeof(Activity));

    printf("Enter the start and end times of the activities:\n");
    for (int i = 0; i < *n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }

    return activities;
}

// Main function to drive the program
int main() {
    int n; // Number of activities
    Activity *activities = inputActivities(&n);
    
    // Perform activity selection
    activitySelection(activities, n);

    // Free allocated memory
    free(activities);

    return 0;
}