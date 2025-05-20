//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_DELAY 5

struct Task {
  char name[20];
  int priority;
  time_t scheduled_time;
  struct Task* next;
};

struct Task* head = NULL;

void addTask(char* name, int priority, time_t scheduled_time) {
  struct Task* newTask = malloc(sizeof(struct Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->scheduled_time = scheduled_time;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    struct Task* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newTask;
  }
}

void scheduleTasks() {
  struct Task* currentTask = head;
  time_t now = time(NULL);

  while (currentTask) {
    if (currentTask->scheduled_time <= now) {
      printf("%s has started!\n", currentTask->name);
      sleep(TASK_DELAY);
      printf("%s has finished!\n", currentTask->name);
      free(currentTask);
      currentTask = NULL;
    } else {
      currentTask = currentTask->next;
    }
  }
}

int main() {
  addTask("Task 1", 1, time(NULL) + 10);
  addTask("Task 2", 2, time(NULL) + 15);
  addTask("Task 3", 3, time(NULL) + 20);

  scheduleTasks();

  return 0;
}