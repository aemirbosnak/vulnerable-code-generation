//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10
#define MAX_TASK_SIZE 20

typedef struct Task {
  char *name;
  time_t start_time;
  time_t end_time;
  struct Task *next;
} Task;

Task *head = NULL;

void schedule_add(char *name, time_t start_time, time_t end_time) {
  Task *new_task = malloc(sizeof(Task));
  new_task->name = strdup(name);
  new_task->start_time = start_time;
  new_task->end_time = end_time;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    Task *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_task;
  }
}

void check_schedule() {
  time_t now = time(NULL);

  Task *current = head;
  while (current) {
    if (now >= current->start_time && now < current->end_time) {
      printf("%s is running\n", current->name);
    }
    current = current->next;
  }
}

int main() {
  schedule_add("Task 1", time(NULL) + 60, time(NULL) + 90);
  schedule_add("Task 2", time(NULL) + 30, time(NULL) + 60);
  schedule_add("Task 3", time(NULL) + 0, time(NULL) + 30);

  check_schedule();

  return 0;
}