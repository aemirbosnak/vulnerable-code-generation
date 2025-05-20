//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct Task* next;
} Task;

void add_task(Task** head, char* name, int priority, time_t start, time_t end) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->start_time = start;
  new_task->end_time = end;
  new_task->next = NULL;

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void schedule_tasks(Task* head) {
  time_t current_time = time(NULL);
  Task* current_task = head;

  while (current_task) {
    if (current_time >= current_task->start_time && current_time < current_task->end_time) {
      printf("Currently executing: %s\n", current_task->name);
    }
    current_task = current_task->next;
  }
}

int main() {
  Task* task_head = NULL;

  add_task(&task_head, "Laundry", 1, time(NULL) + 3600, time(NULL) + 3900);
  add_task(&task_head, "Grocery Shopping", 2, time(NULL) + 1800, time(NULL) + 2100);
  add_task(&task_head, "Coding", 3, time(NULL) + 600, time(NULL) + 900);

  schedule_tasks(task_head);

  return 0;
}