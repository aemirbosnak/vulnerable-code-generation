#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef struct Task {
  char *name;
  struct Task *next;
} Task;

Task *head = NULL;

void sigint_handler(int sig) {
  Task *curr = head;
  while (curr) {
    free(curr->name);
    free(curr);
    curr = head;
  }
  exit(0);
}

void add_task(char *name) {
  Task *new_task = malloc(sizeof(Task));
  new_task->name = strdup(name);
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    Task *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new_task;
  }
}

int main() {
  signal(SIGINT, sigint_handler);

  add_task("Task 1");
  add_task("Task 2");
  add_task("Task 3");

  pause();

  return 0;
}
