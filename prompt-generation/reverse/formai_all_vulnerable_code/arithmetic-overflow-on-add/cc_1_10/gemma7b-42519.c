//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority, time_t start, time_t end) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->start_time = start;
  newTask->end_time = end;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newTask;
  }

  return head;
}

void printSchedule(Task* head) {
  while (head) {
    printf("%s (Priority: %d), Start: %s, End: %s\n", head->name, head->priority, ctime(&head->start_time), ctime(&head->end_time));
    head = head->next;
  }
}

int main() {
  Task* head = NULL;

  insertTask(head, "Task 1", 1, time(NULL) + 60 * 60, time(NULL) + 60 * 60 * 2);
  insertTask(head, "Task 2", 2, time(NULL) + 60 * 30, time(NULL) + 60 * 30 * 2);
  insertTask(head, "Task 3", 3, time(NULL) + 60 * 15, time(NULL) + 60 * 15 * 2);

  printSchedule(head);

  return 0;
}