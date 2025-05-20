//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>

// Function to find the maximum number of activities that can be performed
int activitySelection(int start[], int finish[], int n) {
    int count = 1;
    int lastFinishTime = finish[0];

    // Iterate through the activities and check if they can be included
    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinishTime) {
            lastFinishTime = finish[i];
            count++;
        }
    }

    return count;
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter the start and finish times for each activity:\n");

    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort the activities by their finish times
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                int temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    int maxActivities = activitySelection(start, finish, n);

    printf("The maximum number of activities that can be performed is: %d", maxActivities);

    return 0;
}