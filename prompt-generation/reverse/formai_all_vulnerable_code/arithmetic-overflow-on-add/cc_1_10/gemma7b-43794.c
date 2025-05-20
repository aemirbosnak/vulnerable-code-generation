//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10
#define MAX_TASK_SIZE 20

typedef struct Task {
  char name[MAX_TASK_SIZE];
  int priority;
  time_t scheduled_time;
  struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority, time_t scheduled_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->scheduled_time = scheduled_time;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task** head) {
  time_t now = time(NULL);
  Task* currentTask = *head;

  while (currentTask) {
    if (currentTask->scheduled_time <= now) {
      printf("Task: %s, Priority: %d\n", currentTask->name, currentTask->priority);
      currentTask = currentTask->next;
    } else {
      break;
    }
  }
}

int main() {
  Task* head = NULL;

  addTask(&head, "Task 1", 1, time(NULL) + 3600);
  addTask(&head, "Task 2", 2, time(NULL) + 1800);
  addTask(&head, "Task 3", 3, time(NULL) + 900);

  scheduleTasks(&head);

  return 0;
}