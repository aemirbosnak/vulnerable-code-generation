//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
  char name[32];
  int priority;
  time_t deadline;
  time_t created_at;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int priority, time_t deadline) {
  if (num_tasks >= MAX_TASKS) {
    printf("Maximum number of tasks reached.\n");
    return;
  }
  strcpy(tasks[num_tasks].name, name);
  tasks[num_tasks].priority = priority;
  tasks[num_tasks].deadline = deadline;
  tasks[num_tasks].created_at = time(NULL);
  num_tasks++;
}

void remove_task(int index) {
  if (index < 0 || index >= num_tasks) {
    printf("Invalid task index.\n");
    return;
  }
  for (int i = index; i < num_tasks - 1; i++) {
    tasks[i] = tasks[i + 1];
  }
  num_tasks--;
}

void run_task(int index) {
  if (index < 0 || index >= num_tasks) {
    printf("Invalid task index.\n");
    return;
  }
  printf("Running task %s...\n", tasks[index].name);
  // Run the task here
}

void run_all_tasks() {
  for (int i = 0; i < num_tasks; i++) {
    run_task(i);
  }
}

int main() {
  add_task("Task 1", 3, time(NULL) + 60);
  add_task("Task 2", 2, time(NULL) + 30);
  add_task("Task 3", 1, time(NULL) + 10);
  remove_task(2);
  run_all_tasks();
  return 0;
}