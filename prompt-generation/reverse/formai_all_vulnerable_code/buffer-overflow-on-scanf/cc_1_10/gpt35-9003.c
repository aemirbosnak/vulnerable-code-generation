//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define QUANTUM 2

// Struct to represent a process
struct process {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int waiting_time;
  int turnaround_time;
};

// Function to initialize a process struct
void init_process(struct process *p, int pid, int arrival_time, int burst_time) {
  p->pid = pid;
  p->arrival_time = arrival_time;
  p->burst_time = burst_time;
  p->remaining_time = burst_time;
  p->waiting_time = 0;
  p->turnaround_time = 0;
}

// Function to find the process with the shortest remaining time
int find_shortest_remaining_time(struct process *processes, int n, int t) {
  int shortest_index = -1;
  int shortest_time = 1000;
  for (int i = 0; i < n; i++) {
    if (processes[i].arrival_time <= t && processes[i].remaining_time > 0) {
      if (processes[i].remaining_time < shortest_time) {
        shortest_index = i;
        shortest_time = processes[i].remaining_time;
      }
    }
  }
  return shortest_index;
}

// Function to implement the Shortest Remaining Time First (SRTF) algorithm
void srtf(struct process *processes, int n) {
  int t = 0; // Current time
  int completed = 0; // Number of completed processes
  while (completed < n) {
    int i = find_shortest_remaining_time(processes, n, t);
    if (i == -1) {
      printf("Idle for 1 second\n");
      t++;
    } else {
      processes[i].remaining_time--;
      if (processes[i].remaining_time == 0) {
        completed++;
        processes[i].turnaround_time = t + 1 - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        printf("Process %d completed at time %d\n", processes[i].pid, t + 1);
      }
      t++;
    }
  }
}

// Function to implement the Round Robin (RR) algorithm
void rr(struct process *processes, int n) {
  int t = 0; // Current time
  int completed = 0; // Number of completed processes
  int quantum_countdown[MAX_PROCESSES] = {0}; // Countdown for each process's quantum
  while (completed < n) {
    for (int i = 0; i < n; i++) {
      if (processes[i].arrival_time <= t && processes[i].remaining_time > 0) {
        printf("Process %d running at time %d\n", processes[i].pid, t);
        if (processes[i].remaining_time <= QUANTUM) {
          t += processes[i].remaining_time;
          processes[i].remaining_time = 0;
          completed++;
          processes[i].turnaround_time = t - processes[i].arrival_time;
          processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
          printf("Process %d completed at time %d\n", processes[i].pid, t);
        } else {
          t += QUANTUM;
          processes[i].remaining_time -= QUANTUM;
          quantum_countdown[i] = QUANTUM;
          printf("Process %d paused at time %d with remaining time %d\n", processes[i].pid, t, processes[i].remaining_time);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (quantum_countdown[i] > 0) {
        quantum_countdown[i]--;
        if (quantum_countdown[i] == 0 && processes[i].remaining_time > 0) {
          printf("Process %d resumed at time %d\n", processes[i].pid, t);
        }
      }
    }
  }
}

// Function to print the results of a scheduling algorithm
void print_results(struct process *processes, int n) {
  float avg_wait = 0;
  float avg_turnaround = 0;
  printf("PID  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("%-4d %-13d %-11d %-13d %-16d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    avg_wait += processes[i].waiting_time;
    avg_turnaround += processes[i].turnaround_time;
  }
  printf("Average waiting time: %.2f\n", avg_wait / n);
  printf("Average turnaround time: %.2f\n", avg_turnaround / n);
}

int main() {
  int n; // Number of processes
  int algorithm; // Algorithm to use (1 = SRTF, 2 = RR)

  // Read in number of processes and algorithm choice
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Choose an algorithm (1 = Shortest Remaining Time First, 2 = Round Robin): ");
  scanf("%d", &algorithm);

  // Read in process data
  struct process processes[MAX_PROCESSES];
  for (int i = 0; i < n; i++) {
    int arrival_time, burst_time;
    printf("Enter arrival time and burst time for process %d: ", i + 1);
    scanf("%d %d", &arrival_time, &burst_time);
    init_process(&processes[i], i + 1, arrival_time, burst_time);
  }

  // Run scheduling algorithm
  if (algorithm == 1) {
    srtf(processes, n);
  } else if (algorithm == 2) {
    rr(processes, n);
  } else {
    printf("Invalid algorithm choice\n");
    exit(1);
  }

  // Print results
  print_results(processes, n);

  return 0;
}