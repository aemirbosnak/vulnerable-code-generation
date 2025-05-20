#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct Task {
  char *command;
  struct Task *next;
} Task;

void execute_task(Task *task) {
  free(task->command); // Use-after-free vulnerability
  fork();
  execlp("/bin/bash", "bash", "-c", task->command, NULL);
  exit(1);
}

int main() {
  Task *head = NULL;
  signal(SIGINT, SIG_IGN);

  while (1) {
    char command[1024];
    printf("Enter command: ");
    scanf("%s", command);

    if (strcmp(command, "exit") == 0) {
      break;
    }

    Task *new_task = malloc(sizeof(Task));
    new_task->command = strdup(command);
    new_task->next = head;
    head = new_task;

    execute_task(new_task);
  }

  return 0;
}
