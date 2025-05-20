//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Function to compare two activities according to their finish times
int compare(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

// Function to select and print maximum number of activities
void selectActivities(Activity activities[], int n) {
    // Sort activities based on finish times
    qsort(activities, n, sizeof(Activity), compare);
    
    printf("Selected activities:\n");
    int lastSelected = 0; // The first activity is always selected
    printf("Activity %d : [%d, %d]\n", lastSelected + 1, activities[lastSelected].start, activities[lastSelected].finish);
    
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity ends, select it
        if (activities[i].start >= activities[lastSelected].finish) {
            printf("Activity %d : [%d, %d]\n", i + 1, activities[i].start, activities[i].finish);
            lastSelected = i; // Update last selected activity
        }
    }
}

void inputActivities(Activity activities[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter start time and finish time for activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }
}

void displayActivities(Activity activities[], int n) {
    printf("List of activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d : [%d, %d]\n", i + 1, activities[i].start, activities[i].finish);
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No activities to select.\n");
        return 0;
    }

    Activity *activities = (Activity *)malloc(n * sizeof(Activity));
    
    if (!activities) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    inputActivities(activities, n);
    displayActivities(activities, n);
    selectActivities(activities, n);
    
    free(activities);
    return 0;
}