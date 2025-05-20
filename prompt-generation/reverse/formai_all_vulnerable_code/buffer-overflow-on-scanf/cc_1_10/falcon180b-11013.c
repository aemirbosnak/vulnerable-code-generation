//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
// Greedy Algorithm Example Program
#include <stdio.h>

// Function to find the activity selection problem
int activitySelection(int *startTime, int *finishTime, int n) {
    int i, j, max = 0, end = 0;

    // Initialize the end variable with the first activity
    end = startTime[0];

    // Find the activity with the latest finish time
    for (i = 1; i < n; i++) {
        if (finishTime[i] > max) {
            max = finishTime[i];
        }
    }

    // Select the activity with the latest finish time
    for (i = 0; i < n; i++) {
        if (finishTime[i] == max) {
            if (startTime[i] > end) {
                end = startTime[i];
            }
        }
    }

    // Return the end time of the last selected activity
    return end;
}

int main() {
    int i, n, startTime[100], finishTime[100];

    // Read the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Read the start and finish time of each activity
    printf("Enter the start and finish time of each activity:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &startTime[i], &finishTime[i]);
    }

    // Find the end time of the last selected activity
    int endTime = activitySelection(startTime, finishTime, n);

    // Print the end time of the last selected activity
    printf("The latest finish time is: %d\n", endTime);

    return 0;
}