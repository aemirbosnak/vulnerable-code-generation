//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char *name;
  int priority;
  time_t scheduled_time;
  struct Task *next;
} Task;

Task *scheduler_head = NULL;

void add_task(char *name, int priority, time_t scheduled_time) {
  Task *new_task = malloc(sizeof(Task));
  new_task->name = strdup(name);
  new_task->priority = priority;
  new_task->scheduled_time = scheduled_time;
  new_task->next = NULL;

  if (scheduler_head == NULL) {
    scheduler_head = new_task;
  } else {
    Task *curr_task = scheduler_head;
    while (curr_task->next) {
      curr_task = curr_task->next;
    }
    curr_task->next = new_task;
  }
}

void check_scheduler() {
  time_t now = time(NULL);
  Task *curr_task = scheduler_head;

  while (curr_task) {
    if (now >= curr_task->scheduled_time) {
      printf("Executing task: %s\n", curr_task->name);
      sleep(2);
      printf("Task completed: %s\n", curr_task->name);
      free(curr_task);
      curr_task = NULL;
    } else {
      curr_task = curr_task->next;
    }
  }
}

int main() {
  add_task("Pay bills", 1, time(NULL) + 3600);
  add_task("Do laundry", 2, time(NULL) + 1800);
  add_task("Buy groceries", 3, time(NULL) + 600);

  check_scheduler();

  return 0;
}