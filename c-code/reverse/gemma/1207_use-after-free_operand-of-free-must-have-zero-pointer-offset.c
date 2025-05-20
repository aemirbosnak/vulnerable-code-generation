#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

struct Task {
  char *command;
  struct Task *next;
};

struct Task *addTask(struct Task *head, char *command) {
  struct Task *newTask = malloc(sizeof(struct Task));
  newTask->command = strdup(command);
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    head->next = newTask;
  }

  return head;
}

void executeTasks(struct Task *head) {
  struct Task *currentTask = head;

  while (currentTask) {
    printf("%s\n", currentTask->command);
    free(currentTask);
    currentTask = currentTask->next;
  }
}

int main() {
  struct Task *head = NULL;

  addTask(head, "echo hello");
  addTask(head, "sleep 2");
  addTask(head, "echo goodbye");

  executeTasks(head);

  return 0;
}
