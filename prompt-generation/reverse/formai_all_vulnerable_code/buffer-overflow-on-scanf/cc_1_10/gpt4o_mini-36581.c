//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on their finish times
int compareActivities(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// Function to select maximum number of activities that can be performed by a single person
void selectActivities(struct Activity activities[], int n) {
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(struct Activity), compareActivities);

    // The first activity always gets selected
    int i = 0;
    printf("Selected activities: (%d, %d)\n", activities[i].start, activities[i].finish);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[j].start >= activities[i].finish) {
            printf("Selected activities: (%d, %d)\n", activities[j].start, activities[j].finish);
            i = j; // Update last selected activity
        }
    }
}

// Main function to drive the program
int main() {
    // Declare the number of activities
    int n;
    
    // Prompt the user for the total number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Dynamic allocation for the activities
    struct Activity *activities = (struct Activity *)malloc(n * sizeof(struct Activity));
    
    // Input the start and finish times of activities
    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &(activities[i].start), &(activities[i].finish));
    }

    // Call the function to select and display activities
    selectActivities(activities, n);

    // Free the allocated memory
    free(activities);
    
    return 0;
}