//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value among two integers
int max(int a, int b) {
    return (a > b)? a : b;
}

// Function to implement activity selection problem using greedy algorithm
void activitySelection(int start[], int finish[], int n) {
    // Create an array to store the earliest finish time of each activity
    int earliestFinishTime[n];

    // Initialize the earliest finish time of each activity to 0
    for (int i = 0; i < n; i++) {
        earliestFinishTime[i] = 0;
    }

    // Sort the activities based on their finish times
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && finish[j] < finish[i]) {
            j++;
        }
        int temp = finish[i];
        finish[i] = finish[j];
        finish[j] = temp;
    }

    // Calculate the earliest finish time of each activity
    for (int i = 0; i < n; i++) {
        int earliest = finish[i];
        for (int j = 0; j < n; j++) {
            if (start[j] <= earliest && finish[j] > earliest) {
                earliest = max(earliest, finish[j]);
            }
        }
        earliestFinishTime[i] = earliest;
    }

    // Print the earliest finish time of each activity
    printf("Earliest finish time of each activity: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", earliestFinishTime[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Declare arrays to store the start and finish times of each activity
    int start[n], finish[n];

    // Get the start and finish times of each activity from the user
    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Implement the activity selection problem using the greedy algorithm
    printf("Earliest finish time of each activity using greedy algorithm:\n");
    activitySelection(start, finish, n);

    return 0;
}