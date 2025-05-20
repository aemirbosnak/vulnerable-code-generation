//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  time_t scheduled_time;
  struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, int priority, time_t scheduled_time) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->scheduled_time = scheduled_time;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    Task* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = new_task;
  }
}

void schedule_tasks() {
  time_t now = time(NULL);

  for (Task* current_task = head; current_task; current_task = current_task->next) {
    if (current_task->scheduled_time <= now) {
      printf("Task: %s, Priority: %d, Scheduled Time: %ld\n", current_task->name, current_task->priority, current_task->scheduled_time);
      sleep(current_task->priority);
    }
  }
}

int main() {
  add_task("Wash dishes", 3, time(NULL) + 60);
  add_task("Do laundry", 2, time(NULL) + 30);
  add_task("Cook dinner", 1, time(NULL) + 15);

  schedule_tasks();

  return 0;
}