//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_ITEMS 10

typedef struct Task {
  char name[20];
  int priority;
  time_t scheduled_time;
  struct Task* next;
} Task;

void scheduler_add(Task** head, char* name, int priority, time_t scheduled_time) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->scheduled_time = scheduled_time;
  new_task->next = NULL;

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void scheduler_print(Task* head) {
  while (head) {
    printf("%s (priority: %d, scheduled time: %ld)\n", head->name, head->priority, head->scheduled_time);
    head = head->next;
  }
}

int main() {
  Task* head = NULL;

  // Add tasks
  scheduler_add(&head, "Romeo", 1, time(NULL) + 5);
  scheduler_add(&head, "Juliet", 2, time(NULL) + 10);
  scheduler_add(&head, "Mercutio", 3, time(NULL) + 15);

  // Print tasks
  scheduler_print(head);

  // Wait for tasks to complete
  time_t now = time(NULL);
  while (head) {
    if (head->scheduled_time <= now) {
      printf("%s has completed!\n", head->name);
      free(head);
      head = head->next;
    } else {
      sleep(1);
    }
  }

  return 0;
}