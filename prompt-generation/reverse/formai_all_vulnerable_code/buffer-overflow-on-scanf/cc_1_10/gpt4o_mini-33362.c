//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int start;
    int finish;
} Activity;

// Compare function to sort activities by their finish times
int compare(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

// Greedy function to select maximum number of activities
void selectActivities(Activity activities[], int n) {
    // Sort activities by finish time
    qsort(activities, n, sizeof(Activity), compare);
    
    printf("Greedy Greg's Activity Selection:\n");
    
    // The first activity always gets selected
    int lastFinish = activities[0].finish;
    printf("Activity %d, Start: %d, Finish: %d\n", activities[0].id, activities[0].start, activities[0].finish);
    
    // Iterate through the sorted activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf("Activity %d, Start: %d, Finish: %d\n", activities[i].id, activities[i].start, activities[i].finish);
            lastFinish = activities[i].finish;  // Update last finish time
        }
    }
}

int main() {
    int n;
    printf("Welcome to Greedy Greg's Activity Selector!\n");
    printf("How many activities do you have? ");
    scanf("%d", &n);
    
    Activity *activities = malloc(n * sizeof(Activity));

    // Input for activities
    printf("Enter the activities in the format 'id start finish' (zero-indexed):\n");
    for (int i = 0; i < n; i++) {
        activities[i].id = i;
        printf("Activity %d: ", i);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Greedy algorithm to select activities
    selectActivities(activities, n);

    // Free allocated memory
    free(activities);
    printf("Thank you for using Greedy Greg's Activity Selector. Goodbye!\n");
    return 0;
}