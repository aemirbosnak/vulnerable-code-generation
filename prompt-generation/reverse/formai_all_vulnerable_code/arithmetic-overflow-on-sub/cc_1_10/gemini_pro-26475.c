//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
  char *command;
  int interval;
  int last_run;
} task_t;

task_t tasks[MAX_TASKS];

int num_tasks = 0;

void add_task(char *command, int interval) {
  if (num_tasks >= MAX_TASKS) {
    fprintf(stderr, "Error: Too many tasks.\n");
    return;
  }

  tasks[num_tasks].command = command;
  tasks[num_tasks].interval = interval;
  tasks[num_tasks].last_run = 0;

  num_tasks++;
}

void run_tasks() {
  while (1) {
    for (int i = 0; i < num_tasks; i++) {
      if (time(NULL) - tasks[i].last_run >= tasks[i].interval) {
        pid_t pid = fork();

        if (pid == 0) {
          execlp(tasks[i].command, tasks[i].command, NULL);
          _exit(1);
        }

        tasks[i].last_run = time(NULL);
      }
    }

    sleep(1);
  }
}

void signal_handler(int signum) {
  if (signum == SIGINT) {
    fprintf(stderr, "Exiting...\n");
    exit(0);
  }
}

int main() {
  signal(SIGINT, signal_handler);

  add_task("/bin/echo Hello world", 5);
  add_task("/bin/date", 10);
  add_task("/bin/uptime", 15);

  run_tasks();

  return 0;
}