//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>

// Function to find the activity selection problem
void activitySelection(int start[], int finish[], int n) {
    int i, j, max = 0, result[n];

    // Initializing result[] with -1
    for (i = 0; i < n; i++)
        result[i] = -1;

    // Initializing max with the smallest possible value
    max = start[0];

    // Iterating through all activities
    for (i = 0; i < n; i++) {
        // Finding the latest finishing time of the current activity
        for (j = i; j < n; j++) {
            if (finish[j] > max)
                max = finish[j];
        }

        // Updating result[] if a better sequence is found
        if (max - start[i] > 0)
            result[i] = max - start[i];
    }

    // Printing the optimal sequence
    printf("Optimal Sequence: ");
    for (i = 0; i < n; i++)
        printf("%d ", result[i]);
}

// Main function
int main() {
    int n, i;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Initializing start[] and finish[] arrays
    int start[n], finish[n];
    printf("Enter the start and finish times for each activity:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Calling activitySelection() function
    activitySelection(start, finish, n);

    return 0;
}