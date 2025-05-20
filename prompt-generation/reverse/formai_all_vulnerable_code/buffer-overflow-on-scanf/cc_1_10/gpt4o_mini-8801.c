//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Structure to hold details of each activity (start time and finish time)
struct Activity {
    int start;
    int finish;
};

// A utility function to sort activities in increasing order of their finish time
int activityCompare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// The function to perform the Activity Selection using a Greedy Approach
void activitySelection(struct Activity activities[], int n) {
    // The brave knight selects the first activity and prepares for adventure
    int i = 0;
    printf("The brave knight can partake in the following activities:\n");
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, activities[i].start, activities[i].finish);

    // Keeping track of the last finished activity
    for (int j = 1; j < n; j++) {
        // If the start time of the current activity is greater than or equal to the
        // finish time of the last selected activity, it can be selected
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, activities[j].start, activities[j].finish);
            i = j; // Update the last selected activity
        }
    }
}

int main() {
    // Gathering the bravest souls for the adventure ahead
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter the activities (start and finish times):\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // The knight prepares for battle against overlapping events!
    // Sorting the activities based on their finish times
    qsort(activities, n, sizeof(struct Activity), activityCompare);

    // The knight embarks on the journey of Activity Selection
    activitySelection(activities, n);

    // The adventure has concluded!
    return 0;
}