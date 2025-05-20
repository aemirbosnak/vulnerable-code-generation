//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NR_PROCESSORS 4
#define MAX_QUEUE_SIZE 5

typedef struct Process {
  int process_id;
  char state;
  int arrival_time;
  int burst_time;
  int quantum_time;
  int remaining_time;
  int queue_position;
} Process;

Process processes[MAX_QUEUE_SIZE];

void schedule() {
  int i, j, k;
  for (i = 0; i < MAX_QUEUE_SIZE; i++) {
    processes[i].state = 'S';
  }

  for (i = 0; i < NR_PROCESSORS; i++) {
    processes[i].remaining_time = processes[i].quantum_time;
    processes[i].queue_position = i;
  }

  for (j = 0; j < MAX_QUEUE_SIZE; j++) {
    for (k = 0; k < NR_PROCESSORS; k++) {
      if (processes[j].remaining_time > processes[k].remaining_time) {
        processes[j].remaining_time = processes[k].remaining_time;
        processes[j].queue_position = processes[k].queue_position;
      }
    }
  }

  for (i = 0; i < MAX_QUEUE_SIZE; i++) {
    if (processes[i].remaining_time == 0) {
      processes[i].state = 'C';
      printf("Process %d completed.\n", processes[i].process_id);
    }
  }
}

int main() {
  int i, n, arrival_time, burst_time, quantum_time;
  n = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter the arrival time for process %d: ", i + 1);
    scanf("%d", &arrival_time);

    printf("Enter the burst time for process %d: ", i + 1);
    scanf("%d", &burst_time);

    printf("Enter the quantum time for process %d: ", i + 1);
    scanf("%d", &quantum_time);

    processes[i].process_id = i + 1;
    processes[i].arrival_time = arrival_time;
    processes[i].burst_time = burst_time;
    processes[i].quantum_time = quantum_time;
    processes[i].remaining_time = quantum_time;
  }

  schedule();

  return 0;
}