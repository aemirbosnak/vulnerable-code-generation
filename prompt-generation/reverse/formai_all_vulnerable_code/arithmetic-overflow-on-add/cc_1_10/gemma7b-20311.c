//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int id;
  int cpu_time;
  int waiting_time;
  int turnaround_time;
} Process;

void calculate_cpu_time(Process *process) {
  process->waiting_time = 0;
  process->turnaround_time = process->cpu_time + process->waiting_time;
}

void simulate_cpu_scheduling(Process *processes) {
  int i;
  int current_process = 0;
  int time = 0;

  for (i = 0; i < MAX_PROCESSES; i++) {
    processes[i].waiting_time++;
  }

  while (processes[current_process].waiting_time > 0) {
    processes[current_process].cpu_time--;
    time++;

    for (i = 0; i < MAX_PROCESSES; i++) {
      if (processes[i].waiting_time > processes[current_process].waiting_time) {
        processes[i].waiting_time--;
      }
    }

    current_process = (current_process + 1) % MAX_PROCESSES;
  }

  calculate_cpu_time(processes);

  for (i = 0; i < MAX_PROCESSES; i++) {
    printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
  }
}

int main() {
  Process processes[MAX_PROCESSES];

  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes[i].id = i + 1;
    processes[i].cpu_time = rand() % 10;
  }

  simulate_cpu_scheduling(processes);

  return 0;
}