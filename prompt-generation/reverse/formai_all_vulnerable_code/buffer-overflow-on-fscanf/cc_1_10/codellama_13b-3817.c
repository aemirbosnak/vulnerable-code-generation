//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

struct task {
  char name[100];
  time_t start_time;
  time_t end_time;
};

void schedule_task(struct task* task) {
  time_t current_time = time(NULL);
  time_t task_start_time = task->start_time;
  time_t task_end_time = task->end_time;

  if (task_start_time < current_time && task_end_time > current_time) {
    // Task is currently running
    printf("Task %s is running\n", task->name);
  } else if (task_start_time > current_time) {
    // Task is scheduled to run in the future
    printf("Task %s is scheduled to run in the future\n", task->name);
  } else if (task_end_time < current_time) {
    // Task has already finished
    printf("Task %s has already finished\n", task->name);
  }
}

int main() {
  struct task tasks[MAX_TASKS];
  int num_tasks = 0;

  // Read tasks from file
  FILE* file = fopen("tasks.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  while (fscanf(file, "%s %ld %ld", tasks[num_tasks].name, &tasks[num_tasks].start_time, &tasks[num_tasks].end_time) == 3) {
    num_tasks++;
  }

  fclose(file);

  // Schedule tasks
  for (int i = 0; i < num_tasks; i++) {
    schedule_task(&tasks[i]);
  }

  return 0;
}