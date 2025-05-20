//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on their finish times
int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// Function to select the maximum number of activities
void selectActivities(struct Activity activities[], int n) {
    // Sort activities according to their finish times
    qsort(activities, n, sizeof(activities[0]), compare);
    
    printf("Selected Activities:\n");

    // The first activity is always selected
    int last_finish_time = activities[0].finish;
    printf("Activity %d (Start: %d, Finish: %d)\n", 0, activities[0].start, activities[0].finish);

    // Iterate through the sorted activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[i].start >= last_finish_time) {
            printf("Activity %d (Start: %d, Finish: %d)\n", i, activities[i].start, activities[i].finish);
            last_finish_time = activities[i].finish;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity *activities = (struct Activity *)malloc(n * sizeof(struct Activity));
    
    // Input activities
    printf("Enter the start and finish times of each activity (Start Finish):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Function call to select and display activities
    selectActivities(activities, n);

    // Clean up allocated memory
    free(activities);
    
    return 0;
}