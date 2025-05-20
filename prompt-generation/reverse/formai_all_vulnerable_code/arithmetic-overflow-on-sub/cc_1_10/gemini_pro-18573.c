//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct {
  char *name;
  int interval;
  time_t last_run;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int interval) {
  if (num_tasks >= MAX_TASKS) {
    fprintf(stderr, "Error: too many tasks\n");
    return;
  }

  tasks[num_tasks].name = strdup(name);
  tasks[num_tasks].interval = interval;
  tasks[num_tasks].last_run = 0;

  num_tasks++;
}

void run_tasks() {
  time_t now = time(NULL);

  for (int i = 0; i < num_tasks; i++) {
    if (now - tasks[i].last_run >= tasks[i].interval) {
      printf("Running task: %s\n", tasks[i].name);
      tasks[i].last_run = now;
    }
  }
}

int main() {
  add_task("task1", 1);
  add_task("task2", 2);
  add_task("task3", 3);

  while (1) {
    run_tasks();
    sleep(1);
  }

  return 0;
}