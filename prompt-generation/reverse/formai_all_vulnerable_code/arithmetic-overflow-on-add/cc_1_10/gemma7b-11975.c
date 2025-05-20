//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task_t {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct task_t* next;
} task_t;

task_t* head = NULL;

void add_task(char* name, int priority, time_t start_time, time_t end_time) {
  task_t* new_task = malloc(sizeof(task_t));

  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->start_time = start_time;
  new_task->end_time = end_time;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    head->next = new_task;
  }
}

void print_tasks() {
  task_t* current = head;

  while (current) {
    printf("Name: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", current->name, current->priority, current->start_time, current->end_time);
    current = current->next;
  }
}

int main() {
  add_task("Task 1", 1, time(NULL) + 60, time(NULL) + 90);
  add_task("Task 2", 2, time(NULL) + 30, time(NULL) + 60);
  add_task("Task 3", 3, time(NULL) + 0, time(NULL) + 30);

  print_tasks();

  return 0;
}