//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Data structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on their finish times
int compare(const void *a, const void *b) {
    struct Activity *a1 = (struct Activity *)a;
    struct Activity *a2 = (struct Activity *)b;
    return a1->finish - a2->finish;
}

// Function to print maximum number of activities that can be performed
void printMaxActivities(struct Activity activities[], int n) {
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(struct Activity), compare);

    // Initialize the result to the first activity
    int i = 0;
    printf("%d ", i);

    // Iterate over the remaining activities
    for (int j = 1; j < n; j++) {
        // If the current activity does not overlap with the previous activity,
        // add it to the result
        if (activities[j].start >= activities[i].finish) {
            i = j;
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Input the number of activities
    int n;
    scanf("%d", &n);

    // Input the start and finish times of the activities
    struct Activity activities[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Print the maximum number of activities that can be performed
    printMaxActivities(activities, n);

    return 0;
}