#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

struct Task {
  char *name;
  struct Task *next;
};

struct Task *addTask(struct Task *head, char *name) {
  struct Task *newTask = malloc(sizeof(struct Task));
  newTask->name = strdup(name);
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    head->next = newTask;
  }

  return head;
}

void executeTask(struct Task *task) {
  printf("Executing task: %s\n", task->name);
  // Simulate task execution
  sleep(1);
}

void handleSIGINT(int sig) {
  printf("Interrupt received. Stopping task execution.\n");
  exit(1);
}

int main() {
  struct Task *head = NULL;

  signal(SIGINT, handleSIGINT);

  while (1) {
    char name[20];
    printf("Enter task name: ");
    scanf("%s", name);

    if (strcmp(name, "quit") == 0) {
      break;
    }

    addTask(head, name);
  }

  for (struct Task *task = head; task; task = task->next) {
    executeTask(task);
  }

  return 0;
}
