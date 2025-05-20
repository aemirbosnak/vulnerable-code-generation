//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to find the activity selection problem using greedy algorithm
void activitySelection(int start[], int finish[], int n) {
    int i, j;
    int result[n];

    // Initialize all activities as not selected
    for (i = 0; i < n; i++)
        result[i] = 0;

    // One by one select the activity that finishes first
    for (i = 0; i < n; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (finish[j] < finish[minIndex])
                minIndex = j;
        }

        // Mark the selected activity
        result[minIndex] = 1;

        // Update the start times of the remaining activities
        for (j = 0; j < n; j++) {
            if (j!= minIndex && start[j] > finish[minIndex] &&
                start[j] < finish[minIndex + 1]) {
                start[j] = finish[minIndex] + 1;
            }
        }
    }

    // Print the result
    printf("Selected activities:\n");
    for (i = 0; i < n; i++) {
        if (result[i] == 1)
            printf("%d ", i + 1);
    }
}

// Driver code
int main() {
    int n, i;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Initialize start and finish times of all activities
    int start[n], finish[n];
    printf("Enter the start and finish times of each activity:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Find the optimal solution using greedy algorithm
    activitySelection(start, finish, n);

    return 0;
}