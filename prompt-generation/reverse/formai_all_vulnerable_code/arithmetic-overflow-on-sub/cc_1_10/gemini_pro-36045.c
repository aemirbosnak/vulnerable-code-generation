//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// FCFS (First Come, First Served)
void fcfs(int *processes, int n) {
  printf("FCFS:\n");
  for (int i = 0; i < n; i++) {
    printf("P%d ", processes[i]);
  }
  printf("\n");
}

// SJF (Shortest Job First)
void sjf(int *processes, int n) {
  printf("SJF:\n");
  // Sort the processes by burst time
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (processes[j] > processes[j + 1]) {
        int temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }
  // Schedule the processes
  for (int i = 0; i < n; i++) {
    printf("P%d ", processes[i]);
  }
  printf("\n");
}

// RR (Round Robin)
void rr(int *processes, int n) {
  printf("RR:\n");
  int quantum = 3;
  int t = 0; // Time
  while (1) {
    int done = 1;
    for (int i = 0; i < n; i++) {
      if (processes[i] > 0) {
        done = 0;
        if (processes[i] > quantum) {
          processes[i] -= quantum;
          printf("P%d ", i);
          t += quantum;
        } else {
          t += processes[i];
          printf("P%d ", i);
          processes[i] = 0;
        }
      }
    }
    if (done) {
      break;
    }
  }
  printf("\n");
}

int main() {
  // Input the processes and their burst times
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  int processes[n];
  printf("Enter the burst times of the processes:\n");
  for (int i = 0; i < n; i++) {
    printf("P%d: ", i);
    scanf("%d", &processes[i]);
  }

  // Schedule the processes using different algorithms
  fcfs(processes, n);
  sjf(processes, n);
  rr(processes, n);

  return 0;
}