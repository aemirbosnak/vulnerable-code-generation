//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct process {
  int process_id;
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turn_around_time;
} process;

void schedule(process **processes) {
  int i, j, quantum = 0, ready_queue[MAX_PROCESSES], completed_processes = 0;

  for (i = 0; i < MAX_PROCESSES; i++) {
    ready_queue[i] = 0;
  }

  while (completed_processes < MAX_PROCESSES) {
    for (i = 0; i < MAX_PROCESSES; i++) {
      if (processes[i] && processes[i]->arrival_time <= quantum) {
        ready_queue[i] = 1;
      }
    }

    int max_ready = -1;
    for (i = 0; i < MAX_PROCESSES; i++) {
      if (ready_queue[i] && max_ready < processes[i]->burst_time) {
        max_ready = processes[i]->burst_time;
      }
    }

    quantum += max_ready;

    for (i = 0; i < MAX_PROCESSES; i++) {
      if (processes[i] && processes[i]->arrival_time <= quantum && ready_queue[i] && processes[i]->burst_time == max_ready) {
        processes[i]->waiting_time = quantum - processes[i]->arrival_time;
        processes[i]->turn_around_time = processes[i]->waiting_time + processes[i]->burst_time;
        ready_queue[i] = 0;
        completed_processes++;
      }
    }
  }
}

int main() {
  process processes[MAX_PROCESSES] = {
    {1, 0, 5, 0, 0},
    {2, 2, 4, 0, 0},
    {3, 3, 3, 0, 0},
    {4, 4, 2, 0, 0},
    {5, 5, 6, 0, 0}
  };

  schedule(processes);

  for (int i = 0; i < MAX_PROCESSES; i++) {
    printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turn_around_time);
  }

  return 0;
}