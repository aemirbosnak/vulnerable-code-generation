//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  time_t scheduled_time;
  struct Task* next;
} Task;

Task* head = NULL;

void scheduleTask(char* name, int priority, time_t scheduled_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->scheduled_time = scheduled_time;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* currentTask = head;
    while (currentTask->next) {
      currentTask = currentTask->next;
    }
    currentTask->next = newTask;
  }
}

void executeTasks() {
  time_t now = time(NULL);
  Task* currentTask = head;

  while (currentTask) {
    if (now >= currentTask->scheduled_time) {
      printf("Executing task: %s\n", currentTask->name);
      currentTask->scheduled_time = now + 60; // reschedule after 60 seconds
    } else {
      break;
    }
    currentTask = currentTask->next;
  }
}

int main() {
  scheduleTask("Task 1", 1, time(NULL) + 30);
  scheduleTask("Task 2", 2, time(NULL) + 60);
  scheduleTask("Task 3", 3, time(NULL) + 90);

  executeTasks();

  return 0;
}