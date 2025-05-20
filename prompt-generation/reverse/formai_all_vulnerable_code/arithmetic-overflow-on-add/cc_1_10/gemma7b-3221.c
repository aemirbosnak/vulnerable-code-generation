//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
} Task;

void scheduler_init(Task **tasks, int size) {
  for (int i = 0; i < size; i++) {
    tasks[i] = malloc(sizeof(Task));
    tasks[i]->name[0] = '\0';
    tasks[i]->priority = 0;
    tasks[i]->start_time = 0;
    tasks[i]->end_time = 0;
  }
}

void scheduler_add_task(Task **tasks, int size, char *name, int priority, time_t start_time, time_t end_time) {
  for (int i = 0; i < size; i++) {
    if (tasks[i]->name[0] == '\0') {
      strcpy(tasks[i]->name, name);
      tasks[i]->priority = priority;
      tasks[i]->start_time = start_time;
      tasks[i]->end_time = end_time;
      return;
    }
  }

  // If no free slot found, expand the scheduler
  Task **new_tasks = malloc(sizeof(Task *) * (size * 2));
  for (int i = 0; i < size * 2; i++) {
    new_tasks[i] = malloc(sizeof(Task));
    new_tasks[i]->name[0] = '\0';
    new_tasks[i]->priority = 0;
    new_tasks[i]->start_time = 0;
    new_tasks[i]->end_time = 0;
  }

  scheduler_init(new_tasks, size * 2);
  scheduler_add_task(new_tasks, size * 2, name, priority, start_time, end_time);

  free(tasks);
  tasks = new_tasks;
  size *= 2;
}

int main() {
  Task **tasks = NULL;
  int size = 0;

  scheduler_add_task(tasks, size, "Task 1", 1, time(NULL) + 60, time(NULL) + 90);
  scheduler_add_task(tasks, size, "Task 2", 2, time(NULL) + 30, time(NULL) + 60);
  scheduler_add_task(tasks, size, "Task 3", 3, time(NULL) + 15, time(NULL) + 30);

  for (int i = 0; i < size; i++) {
    printf("Name: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", tasks[i]->name, tasks[i]->priority, tasks[i]->start_time, tasks[i]->end_time);
  }

  return 0;
}