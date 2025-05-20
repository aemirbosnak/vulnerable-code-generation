//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FCFS   0
#define SJF    1
#define RR     2
#define PRIO   3

typedef struct {
  int id;
  int arrival_time;
  int burst_time;
  int priority;
} process;

int compare_arrival_time(const void *a, const void *b) {
  const process *pa = (const process *)a;
  const process *pb = (const process *)b;
  return pa->arrival_time - pb->arrival_time;
}

int compare_burst_time(const void *a, const void *b) {
  const process *pa = (const process *)a;
  const process *pb = (const process *)b;
  return pa->burst_time - pb->burst_time;
}

int compare_priority(const void *a, const void *b) {
  const process *pa = (const process *)a;
  const process *pb = (const process *)b;
  return pa->priority - pb->priority;
}

void fcfs(process *processes, int n) {
  int i, current_time = 0;
  for (i = 0; i < n; i++) {
    current_time += processes[i].burst_time;
    printf("Process %d: %d %d\n", processes[i].id, processes[i].arrival_time, current_time);
  }
}

void sjf(process *processes, int n) {
  int i, j, current_time = 0;
  process temp;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (processes[j].burst_time < processes[i].burst_time) {
        temp = processes[i];
        processes[i] = processes[j];
        processes[j] = temp;
      }
    }
  }
  for (i = 0; i < n; i++) {
    current_time += processes[i].burst_time;
    printf("Process %d: %d %d\n", processes[i].id, processes[i].arrival_time, current_time);
  }
}

void rr(process *processes, int n) {
  int i, j, quantum = 2, current_time = 0;
  for (i = 0; i < n; i++) {
    if (processes[i].burst_time > quantum) {
      current_time += quantum;
      processes[i].burst_time -= quantum;
      for (j = i + 1; j < n; j++) {
        if (processes[j].arrival_time <= current_time) {
          current_time += quantum;
          processes[j].burst_time -= quantum;
        }
      }
      i--;
    } else {
      current_time += processes[i].burst_time;
      printf("Process %d: %d %d\n", processes[i].id, processes[i].arrival_time, current_time);
      processes[i].burst_time = 0;
    }
  }
}

void prio(process *processes, int n) {
  int i, j, current_time = 0;
  process temp;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (processes[j].priority > processes[i].priority) {
        temp = processes[i];
        processes[i] = processes[j];
        processes[j] = temp;
      }
    }
  }
  for (i = 0; i < n; i++) {
    current_time += processes[i].burst_time;
    printf("Process %d: %d %d\n", processes[i].id, processes[i].arrival_time, current_time);
  }
}

int main() {
  int i, n, algorithm;
  process processes[10];

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  printf("Enter the arrival time, burst time, and priority for each process:\n");
  for (i = 0; i < n; i++) {
    printf("Process %d: ", i + 1);
    scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    processes[i].id = i + 1;
  }

  printf("Which scheduling algorithm do you want to use?");
  printf("0 - FCFS, 1 - SJF, 2 - RR, 3 - PRIO\n");
  scanf("%d", &algorithm);

  switch (algorithm) {
    case FCFS:
      fcfs(processes, n);
      break;
    case SJF:
      sjf(processes, n);
      break;
    case RR:
      rr(processes, n);
      break;
    case PRIO:
      prio(processes, n);
      break;
    default:
      printf("Invalid algorithm\n");
  }

  return 0;
}