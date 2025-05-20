#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct Task {
  char *name;
  struct Task *next;
} Task;

Task *head = NULL;

void sigusr1(int sig) {
  Task *task = malloc(sizeof(Task));
  task->name = "Task A";
  task->next = head;
  head = task;
  kill(getpid(), SIGCONT);
}

void execute_task() {
  if (head) {
    Task *current = head;
    head = head->next;
    free(current);
    execlp("/bin/sleep", "sleep", "5", NULL);
  }
}

int main() {
  signal(SIGUSR1, sigusr1);
  execute_task();
  return 0;
}
