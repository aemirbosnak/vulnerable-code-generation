//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_TIME 100

typedef struct {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int waiting_time;
  int turnaround_time;
} process;

int compare_arrival_time(const void *a, const void *b) {
  process *process_a = (process *)a;
  process *process_b = (process *)b;
  return process_a->arrival_time - process_b->arrival_time;
}

int compare_remaining_time(const void *a, const void *b) {
  process *process_a = (process *)a;
  process *process_b = (process *)b;
  return process_a->remaining_time - process_b->remaining_time;
}

void print_gantt_chart(process *processes, int n) {
  int i, j;
  printf("Gantt Chart:\n");
  printf("---------------------------------------------------------------------\n");
  for (i = 0; i < n; i++) {
    printf("| P%d |", processes[i].pid);
  }
  printf("\n---------------------------------------------------------------------\n");
  for (i = 0; i < MAX_TIME; i++) {
    printf("|");
    for (j = 0; j < n; j++) {
      if (processes[j].remaining_time > 0 && processes[j].arrival_time <= i) {
        printf(" %d ", processes[j].pid);
      } else {
        printf("    ");
      }
    }
    printf("|");
  }
  printf("\n---------------------------------------------------------------------\n");
}

void print_process_details(process *processes, int n) {
  int i;
  printf("\nProcess Details:\n");
  printf("---------------------------------------------------------------------\n");
  printf("| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
  for (i = 0; i < n; i++) {
    printf("| P%d | %d | %d | %d | %d |\n", processes[i].pid, processes[i].arrival_time,
           processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
  }
  printf("---------------------------------------------------------------------\n");
}

void calculate_waiting_time(process *processes, int n) {
  int i, j;
  processes[0].waiting_time = 0;
  for (i = 1; i < n; i++) {
    processes[i].waiting_time = 0;
    for (j = 0; j < i; j++) {
      processes[i].waiting_time += processes[j].burst_time;
    }
  }
}

void calculate_turnaround_time(process *processes, int n) {
  int i;
  for (i = 0; i < n; i++) {
    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
  }
}

void fcfs(process *processes, int n) {
  qsort(processes, n, sizeof(process), compare_arrival_time);
  calculate_waiting_time(processes, n);
  calculate_turnaround_time(processes, n);
  print_gantt_chart(processes, n);
  print_process_details(processes, n);
}

void sjf(process *processes, int n) {
  int i, j;
  process temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (processes[j].arrival_time > processes[j + 1].arrival_time ||
          (processes[j].arrival_time == processes[j + 1].arrival_time &&
           processes[j].burst_time > processes[j + 1].burst_time)) {
        temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }
  qsort(processes, n, sizeof(process), compare_remaining_time);
  calculate_waiting_time(processes, n);
  calculate_turnaround_time(processes, n);
  print_gantt_chart(processes, n);
  print_process_details(processes, n);
}

int main() {
  int n, i;
  process processes[MAX_PROCESSES];
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter the arrival time and burst time for each process:\n");
  for (i = 0; i < n; i++) {
    printf("Process %d:\n", i + 1);
    printf("Arrival Time: ");
    scanf("%d", &processes[i].arrival_time);
    printf("Burst Time: ");
    scanf("%d", &processes[i].burst_time);
    processes[i].pid = i + 1;
    processes[i].remaining_time = processes[i].burst_time;
    processes[i].waiting_time = 0;
    processes[i].turnaround_time = 0;
  }
  printf("\nCPU Scheduling Algorithms:\n");
  printf("---------------------------------------------------------------------\n");
  printf("1. First Come First Serve (FCFS)\n");
  printf("2. Shortest Job First (SJF)\n");
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch (choice) {
  case 1:
    fcfs(processes, n);
    break;
  case 2:
    sjf(processes, n);
    break;
  default:
    printf("Invalid choice!\n");
  }
  return 0;
}