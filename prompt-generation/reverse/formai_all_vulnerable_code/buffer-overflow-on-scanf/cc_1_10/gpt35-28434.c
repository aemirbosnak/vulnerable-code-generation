//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// structure to represent each activity
typedef struct activity {
  int start_time;
  int end_time;
} Activity;

// compare function for sorting activities by their end time
int compare(const void* a, const void* b) {
  Activity* activity_a = (Activity*) a;
  Activity* activity_b = (Activity*) b;

  return activity_a->end_time - activity_b->end_time;
}

// function to find the maximum number of activities that can be performed
void maximum_activities(Activity activities[], int num_activities) {
  // sort activities by end time
  qsort(activities, num_activities, sizeof(Activity), compare);

  int i = 0, j = 1, count = 1;

  // select the first activity
  printf("Selected Activity: (%d, %d)\n", activities[i].start_time, activities[i].end_time);

  // iterate through the remaining activities
  for (j = 1; j < num_activities; j++) {
    // check if the current activity can be performed
    if (activities[j].start_time >= activities[i].end_time) {
      // select the current activity
      printf("Selected Activity: (%d, %d)\n", activities[j].start_time, activities[j].end_time);
      i = j;
      count++;
    }
  }

  printf("Total number of activities selected: %d\n", count);
}

int main() {
  // input the number of activities
  int num_activities;
  printf("Enter the number of activities: ");
  scanf("%d", &num_activities);

  // allocate memory for the activities
  Activity* activities = malloc(sizeof(Activity) * num_activities);

  // input the start and end times for each activity
  for (int i = 0; i < num_activities; i++) {
    printf("Enter the start time and end time for activity %d: ", i + 1);
    scanf("%d %d", &activities[i].start_time, &activities[i].end_time);
  }

  // find the maximum number of activities that can be performed
  maximum_activities(activities, num_activities);

  // free memory
  free(activities);

  return 0;
}