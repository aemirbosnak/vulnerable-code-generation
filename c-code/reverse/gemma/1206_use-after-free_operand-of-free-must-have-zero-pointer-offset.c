#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <signal.h>

typedef struct Task {
  char name[20];
  struct Task* next;
} Task;

Task* head = NULL;

void sigint_handler(int sig) {
  printf("Interrupt received. Stopping execution...\n");
  exit(0);
}

void add_task(char* name) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    head->next = new_task;
    head = new_task;
  }
}

void remove_task(char* name) {
  Task* prev = NULL;
  Task* current = head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (prev) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }

  printf("Task not found.\n");
}

int main() {
  signal(SIGINT, sigint_handler);

  add_task("Task 1");
  add_task("Task 2");
  add_task("Task 3");

  remove_task("Task 2");

  for (Task* current = head; current; current = current->next) {
    printf("%s\n", current->name);
  }

  return 0;
}
