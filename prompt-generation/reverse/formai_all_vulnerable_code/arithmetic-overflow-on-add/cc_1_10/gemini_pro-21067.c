//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
  void (*function)(void *);
  void *arg;
  time_t time;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(void (*function)(void *), void *arg, time_t time) {
  if (num_tasks == MAX_TASKS) {
    fprintf(stderr, "Error: Maximum number of tasks reached.\n");
    return;
  }

  tasks[num_tasks].function = function;
  tasks[num_tasks].arg = arg;
  tasks[num_tasks].time = time;
  num_tasks++;
}

void run_tasks() {
  while (num_tasks > 0) {
    // Find the next task to run
    int next_task = -1;
    time_t now = time(NULL);
    for (int i = 0; i < num_tasks; i++) {
      if (tasks[i].time <= now && (next_task == -1 || tasks[i].time < tasks[next_task].time)) {
        next_task = i;
      }
    }

    // If no tasks are ready to run, wait for a while
    if (next_task == -1) {
      sleep(1);
      continue;
    }

    // Run the task
    tasks[next_task].function(tasks[next_task].arg);

    // Remove the task from the list
    for (int i = next_task; i < num_tasks - 1; i++) {
      tasks[i] = tasks[i + 1];
    }
    num_tasks--;
  }
}

void task1(void *arg) {
  printf("Task 1: %s\n", (char *)arg);
}

void task2(void *arg) {
  printf("Task 2: %d\n", *(int *)arg);
}

int main() {
  // Add some tasks
  add_task(task1, "Hello", time(NULL) + 5);
  add_task(task2, &num_tasks, time(NULL) + 10);

  // Run the tasks
  run_tasks();

  return 0;
}