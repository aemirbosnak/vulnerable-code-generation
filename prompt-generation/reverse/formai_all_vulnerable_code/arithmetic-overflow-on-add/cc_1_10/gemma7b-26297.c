//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE 10

typedef struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority, time_t start_time, time_t end_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->start_time = start_time;
  newTask->end_time = end_time;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newTask;
  }

  return head;
}

void printSchedule(Task* head) {
  printf("Schedule:\n");
  while (head) {
    printf("%s (%d) - %s to %s\n", head->name, head->priority,
      ctime(&head->start_time), ctime(&head->end_time));
    head = head->next;
  }
}

int main() {
  Task* head = NULL;

  head = insertTask(head, "Task 1", 1, time(NULL) + 3600, time(NULL) + 3600 * 2);
  insertTask(head, "Task 2", 2, time(NULL) + 1800, time(NULL) + 1800 * 2);
  insertTask(head, "Task 3", 3, time(NULL) + 600, time(NULL) + 600 * 2);

  printSchedule(head);

  return 0;
}