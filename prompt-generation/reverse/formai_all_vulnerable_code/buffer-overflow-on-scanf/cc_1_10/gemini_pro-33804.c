//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int priority;
  int completed;
} process;

process processes[MAX_PROCESSES];

int num_processes;

void get_processes() {
  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  for (int i = 0; i < num_processes; i++) {
    printf("Enter the PID, arrival time, burst time, and priority of process %d: ", i + 1);
    scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    processes[i].remaining_time = processes[i].burst_time;
    processes[i].completed = 0;
  }
}

void print_processes() {
  printf("\nProcesses:\n");
  printf("PID\tArrival Time\tBurst Time\tRemaining Time\tPriority\tCompleted\n");
  for (int i = 0; i < num_processes; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].remaining_time, processes[i].priority, processes[i].completed);
  }
}

void fcfs() {
  int time = 0;
  int completed_processes = 0;

  while (completed_processes < num_processes) {
    for (int i = 0; i < num_processes; i++) {
      if (processes[i].arrival_time <= time && processes[i].completed == 0) {
        printf("Executing process %d\n", processes[i].pid);
        processes[i].remaining_time--;
        time++;

        if (processes[i].remaining_time == 0) {
          processes[i].completed = 1;
          completed_processes++;
        }
      }
    }
  }
}

void sjf() {
  int time = 0;
  int completed_processes = 0;

  while (completed_processes < num_processes) {
    int shortest_remaining_time = -1;
    int shortest_process_index = -1;

    for (int i = 0; i < num_processes; i++) {
      if (processes[i].arrival_time <= time && processes[i].completed == 0) {
        if (shortest_remaining_time == -1 || processes[i].remaining_time < shortest_remaining_time) {
          shortest_remaining_time = processes[i].remaining_time;
          shortest_process_index = i;
        }
      }
    }

    if (shortest_process_index != -1) {
      printf("Executing process %d\n", processes[shortest_process_index].pid);
      processes[shortest_process_index].remaining_time--;
      time++;

      if (processes[shortest_process_index].remaining_time == 0) {
        processes[shortest_process_index].completed = 1;
        completed_processes++;
      }
    } else {
      time++;
    }
  }
}

void priority() {
  int time = 0;
  int completed_processes = 0;

  while (completed_processes < num_processes) {
    int highest_priority = -1;
    int highest_priority_process_index = -1;

    for (int i = 0; i < num_processes; i++) {
      if (processes[i].arrival_time <= time && processes[i].completed == 0) {
        if (highest_priority == -1 || processes[i].priority > highest_priority) {
          highest_priority = processes[i].priority;
          highest_priority_process_index = i;
        }
      }
    }

    if (highest_priority_process_index != -1) {
      printf("Executing process %d\n", processes[highest_priority_process_index].pid);
      processes[highest_priority_process_index].remaining_time--;
      time++;

      if (processes[highest_priority_process_index].remaining_time == 0) {
        processes[highest_priority_process_index].completed = 1;
        completed_processes++;
      }
    } else {
      time++;
    }
  }
}

int main() {
  get_processes();
  print_processes();

  printf("\nFCFS:\n");
  fcfs();
  print_processes();

  printf("\nSJF:\n");
  sjf();
  print_processes();

  printf("\nPriority:\n");
  priority();
  print_processes();

  return 0;
}