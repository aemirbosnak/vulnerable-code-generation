//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct Task* next;
} Task;

Task* head = NULL;

void schedule_add(char* name, int priority, time_t start_time, time_t end_time) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->start_time = start_time;
  new_task->end_time = end_time;
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

void schedule_print() {
  Task* current = head;
  while (current) {
    printf("%s (priority: %d), start: %ld, end: %ld\n", current->name, current->priority, current->start_time, current->end_time);
    current = current->next;
  }
}

int main() {
  schedule_add("Task 1", 1, time(NULL) + 3600, time(NULL) + 3600 * 2);
  schedule_add("Task 2", 2, time(NULL) + 1800, time(NULL) + 1800 * 2);
  schedule_add("Task 3", 3, time(NULL) + 600, time(NULL) + 600 * 2);

  schedule_print();

  return 0;
}