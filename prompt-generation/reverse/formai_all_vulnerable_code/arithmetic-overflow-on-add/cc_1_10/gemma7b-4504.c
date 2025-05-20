//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  time_t scheduled_time;
  struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int priority, time_t scheduled_time) {
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

void scheduleTasks() {
  time_t now = time(NULL);
  Task* currentTask = head;

  while (currentTask) {
    if (now >= currentTask->scheduled_time) {
      printf("Task: %s, Priority: %d, Time Scheduled: %s\n", currentTask->name, currentTask->priority, asctime(localtime(&currentTask->scheduled_time)));
      currentTask = currentTask->next;
    } else {
      break;
    }
  }
}

int main() {
  addTask("Gather supplies", 3, time(NULL) + 60 * 60);
  addTask("Fortify shelter", 2, time(NULL) + 60 * 30);
  addTask("Hunt for water", 1, time(NULL) + 60 * 15);

  scheduleTasks();

  return 0;
}