//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the maximum number of tasks
#define MAX_TASKS 100

// Define the task structure
typedef struct {
  int arrival_time;
  int processing_time;
} task;

// Function to compare two tasks based on their arrival times
int compare_arrival_times(const void *a, const void *b) {
  task *task1 = (task *)a;
  task *task2 = (task *)b;

  return task1->arrival_time - task2->arrival_time;
}

// Function to find the minimum number of servers needed to schedule all tasks without any waiting time
int find_minimum_servers(task tasks[], int num_tasks) {
  // Sort the tasks based on their arrival times
  qsort(tasks, num_tasks, sizeof(task), compare_arrival_times);

  // Initialize the number of servers to 0
  int num_servers = 0;

  // Initialize the current time to 0
  int current_time = 0;

  // Iterate over the tasks
  for (int i = 0; i < num_tasks; i++) {
    // If the current time is less than the arrival time of the current task, then update the current time to the arrival time of the current task
    if (current_time < tasks[i].arrival_time) {
      current_time = tasks[i].arrival_time;
    }

    // Increment the number of servers
    num_servers++;

    // Update the current time to the current time plus the processing time of the current task
    current_time += tasks[i].processing_time;
  }

  // Return the number of servers
  return num_servers;
}

// Main function
int main() {
  // Define the number of tasks
  int num_tasks;

  // Get the number of tasks from the user
  printf("Enter the number of tasks: ");
  scanf("%d", &num_tasks);

  // Assert that the number of tasks is between 1 and MAX_TASKS
  assert(num_tasks >= 1 && num_tasks <= MAX_TASKS);

  // Define the array of tasks
  task tasks[num_tasks];

  // Get the arrival times and processing times of the tasks from the user
  for (int i = 0; i < num_tasks; i++) {
    printf("Enter the arrival time of task %d: ", i + 1);
    scanf("%d", &tasks[i].arrival_time);

    printf("Enter the processing time of task %d: ", i + 1);
    scanf("%d", &tasks[i].processing_time);
  }

  // Find the minimum number of servers needed to schedule all tasks without any waiting time
  int minimum_servers = find_minimum_servers(tasks, num_tasks);

  // Print the minimum number of servers
  printf("Minimum number of servers needed: %d\n", minimum_servers);

  return 0;
}