//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 100
#define MAX_TIME_SLICE 10

typedef struct {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  bool is_completed;
} Process;

typedef struct {
  int current_time;
  int total_waiting_time;
  int total_turnaround_time;
  int total_processes;
  Process processes[MAX_PROCESSES];
} Scheduler;

void print_scheduler(Scheduler *scheduler) {
  printf("Current time: %d\n", scheduler->current_time);
  printf("Total waiting time: %d\n", scheduler->total_waiting_time);
  printf("Total turnaround time: %d\n", scheduler->total_turnaround_time);
  printf("Total processes: %d\n", scheduler->total_processes);
  for (int i = 0; i < scheduler->total_processes; i++) {
    printf("Process %d:\n", scheduler->processes[i].pid);
    printf("  Arrival time: %d\n", scheduler->processes[i].arrival_time);
    printf("  Burst time: %d\n", scheduler->processes[i].burst_time);
    printf("  Remaining time: %d\n", scheduler->processes[i].remaining_time);
    printf("  Is completed: %s\n", scheduler->processes[i].is_completed ? "true" : "false");
  }
}

int main() {
  Scheduler scheduler;
  scheduler.current_time = 0;
  scheduler.total_waiting_time = 0;
  scheduler.total_turnaround_time = 0;
  scheduler.total_processes = 0;

  // Read the input data from the user.
  int num_processes;
  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  for (int i = 0; i < num_processes; i++) {
    Process process;
    printf("Enter the PID of process %d: ", i + 1);
    scanf("%d", &process.pid);
    printf("Enter the arrival time of process %d: ", i + 1);
    scanf("%d", &process.arrival_time);
    printf("Enter the burst time of process %d: ", i + 1);
    scanf("%d", &process.burst_time);
    process.remaining_time = process.burst_time;
    process.is_completed = false;
    scheduler.processes[i] = process;
    scheduler.total_processes++;
  }

  // Sort the processes by their arrival time.
  for (int i = 0; i < scheduler.total_processes; i++) {
    for (int j = 0; j < scheduler.total_processes - 1; j++) {
      if (scheduler.processes[j].arrival_time > scheduler.processes[j + 1].arrival_time) {
        Process temp = scheduler.processes[j];
        scheduler.processes[j] = scheduler.processes[j + 1];
        scheduler.processes[j + 1] = temp;
      }
    }
  }

  // Execute the processes using the round-robin scheduling algorithm.
  int time_slice = MAX_TIME_SLICE;
  while (scheduler.total_processes > 0) {
    for (int i = 0; i < scheduler.total_processes; i++) {
      if (scheduler.processes[i].is_completed) {
        continue;
      }
      if (scheduler.processes[i].arrival_time <= scheduler.current_time) {
        if (scheduler.processes[i].remaining_time > time_slice) {
          scheduler.processes[i].remaining_time -= time_slice;
          scheduler.current_time += time_slice;
          scheduler.total_waiting_time += time_slice;
        } else {
          scheduler.total_waiting_time += scheduler.processes[i].remaining_time;
          scheduler.total_turnaround_time += scheduler.current_time - scheduler.processes[i].arrival_time + scheduler.processes[i].remaining_time;
          scheduler.processes[i].is_completed = true;
          scheduler.total_processes--;
        }
      }
    }
  }

  // Print the scheduler statistics.
  print_scheduler(&scheduler);

  return 0;
}