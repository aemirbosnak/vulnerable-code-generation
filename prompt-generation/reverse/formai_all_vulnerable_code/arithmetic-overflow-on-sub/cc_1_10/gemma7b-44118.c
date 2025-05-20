//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME_SLICE 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  int remaining_time;
} Process;

Process processes[MAX_PROCESSES];

void schedule() {
  int i = 0;
  int min_remaining_time = MAX_TIME_SLICE;
  Process *current_process = NULL;

  for (i = 0; i < MAX_PROCESSES; i++) {
    if (processes[i].remaining_time < min_remaining_time) {
      min_remaining_time = processes[i].remaining_time;
      current_process = &processes[i];
    }
  }

  if (current_process) {
    current_process->remaining_time--;
    printf("Process %d is running\n", current_process->process_id);
  } else {
    printf("No processes are ready\n");
  }
}

int main() {
  int i = 0;
  time_t t;

  for (i = 0; i < MAX_PROCESSES; i++) {
    processes[i].process_id = i + 1;
    processes[i].arrival_time = rand() % MAX_TIME_SLICE;
    processes[i].execution_time = rand() % MAX_TIME_SLICE;
    processes[i].remaining_time = processes[i].execution_time;
  }

  t = time(NULL);
  while (time(NULL) - t < 10) {
    schedule();
    sleep(1);
  }

  return 0;
}