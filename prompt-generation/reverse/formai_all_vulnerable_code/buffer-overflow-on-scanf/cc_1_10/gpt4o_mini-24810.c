//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Function to compare two activities (used for sorting)
int compare(const void *a, const void *b) {
    Activity *activity1 = (Activity *)a;
    Activity *activity2 = (Activity *)b;
    return activity1->finish - activity2->finish;
}

// Function to find the maximum number of activities
void selectActivities(Activity activities[], int n) {
    // Let’s sort the activities based on their finishing times
    qsort(activities, n, sizeof(Activity), compare);
    
    printf("Awesome! Let's select the maximum number of activities:\n");

    // The first activity always gets selected
    int count = 1;
    int lastFinishTime = activities[0].finish;

    printf("Selected Activity %d: [%d, %d]\n", count, activities[0].start, activities[0].finish);
    
    // Iterate through the sorted activities
    for(int i = 1; i < n; i++) {
        // If the start time of the current activity is greater or equal 
        // to the finish time of the last selected activity, select it!
        if (activities[i].start >= lastFinishTime) {
            count++;
            lastFinishTime = activities[i].finish;
            printf("Selected Activity %d: [%d, %d]\n", count, activities[i].start, activities[i].finish);
        }
    }

    printf("Yay! We have selected %d activities!\n", count);
}

int main() {
    int n;

    printf("Welcome to the Amazing Activity Planner!\n");
    printf("How many activities do you want to schedule? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Oh no! Please enter a positive number of activities!\n");
        return 1;
    }

    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    // Input the activities
    printf("Great! Now, please enter the start and finish times of each activity:\n");
    for(int i = 0; i < n; i++) {
        printf("Activity %d (start finish): ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Call the function to select and display activities
    selectActivities(activities, n);

    // Free the dynamically allocated memory
    free(activities);
    
    printf("Thanks for using the Amazing Activity Planner! Until next time!\n");
    
    return 0;
}