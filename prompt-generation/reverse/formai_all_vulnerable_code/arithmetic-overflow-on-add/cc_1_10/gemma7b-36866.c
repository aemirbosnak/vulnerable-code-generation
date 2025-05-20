//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[255];
  time_t start;
  time_t end;
  struct Task* next;
} Task;

void addTask(Task** head, char* name, time_t start, time_t end) {
  Task* newTask = malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->start = start;
  newTask->end = end;
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
    if (now >= currentTask->start && now < currentTask->end) {
      printf("Executing task: %s\n", currentTask->name);
    }
    currentTask = currentTask->next;
  }
}

int main() {
  Task* head = NULL;
  addTask(&head, "Task 1", time(NULL) + 60, time(NULL) + 90);
  addTask(&head, "Task 2", time(NULL) + 30, time(NULL) + 60);
  addTask(&head, "Task 3", time(NULL) + 15, time(NULL) + 30);

  scheduleTasks(&head);

  return 0;
}