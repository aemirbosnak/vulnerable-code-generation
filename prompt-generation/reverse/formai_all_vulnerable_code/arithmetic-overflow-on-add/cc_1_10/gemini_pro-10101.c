//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the structure of a task
typedef struct task {
  int id;              // The ID of the task
  char *command;       // The command to be executed
  int interval;        // The interval at which the task should be executed (in seconds)
  int next_execution;  // The time at which the task should next be executed
} task;

// Define the list of tasks
task tasks[MAX_TASKS];

// Define the number of tasks in the list
int num_tasks = 0;

// Define the signal handler for SIGALRM
void alarm_handler(int signum) {
  // Loop through the list of tasks
  for (int i = 0; i < num_tasks; i++) {
    // Check if the task is due to be executed
    if (tasks[i].next_execution <= time(NULL)) {
      // Execute the task
      system(tasks[i].command);

      // Update the next execution time
      tasks[i].next_execution = tasks[i].next_execution + tasks[i].interval;
    }
  }

  // Set a new alarm for the next task execution time
  alarm(1);
}

// Define the main function
int main(int argc, char **argv) {
  // Check if the user has specified any tasks
  if (argc < 2) {
    printf("Usage: %s <task1> <task2> ...\n", argv[0]);
    return 1;
  }

  // Parse the tasks specified by the user
  for (int i = 1; i < argc; i++) {
    // Get the task ID, command, and interval
    int id, interval;
    char *command;
    sscanf(argv[i], "%d %s %d", &id, &command, &interval);

    // Create the task
    task task = {
      .id = id,
      .command = command,
      .interval = interval,
      .next_execution = time(NULL) + interval,
    };

    // Add the task to the list of tasks
    tasks[num_tasks++] = task;
  }

  // Set up the signal handler for SIGALRM
  signal(SIGALRM, alarm_handler);

  // Set the first alarm
  alarm(1);

  // Wait for the tasks to finish
  while (1) {
    pause();
  }

  return 0;
}