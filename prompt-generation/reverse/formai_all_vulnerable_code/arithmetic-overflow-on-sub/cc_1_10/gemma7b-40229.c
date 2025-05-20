//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

struct process {
  int id;
  int burstTime;
  int waitingTime;
  int turnaroundTime;
};

void calculateTurnaroundTime(struct process *processes) {
  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
  }
}

int main() {
  struct process processes[MAX_PROCESSES];

  // Initialize processes
  processes[0].id = 1;
  processes[0].burstTime = 8;
  processes[0].waitingTime = 0;

  processes[1].id = 2;
  processes[1].burstTime = 12;
  processes[1].waitingTime = 0;

  processes[2].id = 3;
  processes[2].burstTime = 6;
  processes[2].waitingTime = 0;

  processes[3].id = 4;
  processes[3].burstTime = 4;
  processes[3].waitingTime = 0;

  processes[4].id = 5;
  processes[4].burstTime = 10;
  processes[4].waitingTime = 0;

  // Simulate CPU scheduling
  clock_t start = clock();
  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes[i].waitingTime++;
  }
  clock_t end = clock();

  // Calculate turnaround time
  calculateTurnaroundTime(processes);

  // Print results
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < MAX_PROCESSES; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
  }

  printf("\nTotal Time Taken: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}