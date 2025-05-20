//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Function to compare two activities based on their finish times
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to select activities based on the greedy strategy
void selectActivities(Activity activities[], int n) {
    // Sort activities based on finish time
    qsort(activities, n, sizeof(Activity), compare);
    
    // The first activity always gets selected
    printf("Selected activities:\n");
    printf("Activity %d: Start: %d, Finish: %d\n", 1, activities[0].start, activities[0].finish);
    
    // The last finish time is the finish time of the first selected activity
    int lastFinishTime = activities[0].finish;

    // Iterate through the other activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected one finishes
        if (activities[i].start >= lastFinishTime) {
            printf("Activity %d: Start: %d, Finish: %d\n", i + 1, activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish; // Update the last finish time
        }
    }
}

int main() {
    int n;

    // User input for number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number of activities.\n");
        return 1;
    }

    Activity *activities = (Activity *)malloc(n * sizeof(Activity));
    
    // Input activities' start and finish times
    for (int i = 0; i < n; i++) {
        printf("Enter start and finish times for activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
        if (activities[i].start < 0 || activities[i].finish < activities[i].start) {
            printf("Invalid timings for activity %d. Start time: %d, Finish time: %d\n",
                    i + 1, activities[i].start, activities[i].finish);
            free(activities);
            return 1;
        }
    }

    // Select and display the activities
    selectActivities(activities, n);

    // Free allocated memory
    free(activities);

    return 0;
}