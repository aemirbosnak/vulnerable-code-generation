//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an activity
typedef struct activity
{
    int start;
    int finish;
} activity;

// Function to compare two activities based on their finish time
int compare(const void *a, const void *b)
{
    activity *a1 = (activity *)a;
    activity *a2 = (activity *)b;
    return a1->finish - a2->finish;
}

// Function to find the maximum number of activities that can be performed
int maxActivities(activity *arr, int n)
{
    // Sort the activities based on their finish time
    qsort(arr, n, sizeof(activity), compare);

    int count = 1;
    int prevFinishTime = arr[0].finish;

    // Iterate over the remaining activities
    for (int i = 1; i < n; i++)
    {
        // If the current activity's start time is greater than or equal to the previous activity's finish time, then it can be included
        if (arr[i].start >= prevFinishTime)
        {
            count++;
            prevFinishTime = arr[i].finish;
        }
    }

    return count;
}

// Driver code
int main()
{
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    activity *arr = (activity *)malloc(n * sizeof(activity));

    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    int maxActivitiesCount = maxActivities(arr, n);

    printf("The maximum number of activities that can be performed is: %d\n", maxActivitiesCount);

    return 0;
}