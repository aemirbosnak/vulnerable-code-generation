//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_processes, i, j, total_burst_time = 0;
  float avg_waiting_time = 0, avg_turnaround_time = 0;
  int process_id[100], burst_time[100], waiting_time[100], turnaround_time[100];
  srand(time(0));

  printf("Welcome to the CPU scheduling algorithm simulator!\n\n");
  printf("How many processes do you want to simulate? ");
  scanf("%d", &num_processes);

  printf("\nInitializing random burst times...\n\n");

  // Generate random burst times for each process
  for (i = 0; i < num_processes; i++) {
    process_id[i] = i + 1;
    burst_time[i] = rand() % 20 + 1;  // Generate random burst time between 1-20
    total_burst_time += burst_time[i];
  }

  printf("Total burst time of all processes: %d\n\n", total_burst_time);

  // First come, first served (FCFS) scheduling algorithm
  printf("First come, first served (FCFS) scheduling algorithm:\n\n");

  // Calculate waiting time and turnaround time for each process
  for (i = 0; i < num_processes; i++) {
    if (i == 0)
      waiting_time[i] = 0;
    else
      waiting_time[i] = turnaround_time[i - 1];

    turnaround_time[i] = burst_time[i] + waiting_time[i];
    avg_waiting_time += waiting_time[i];
    avg_turnaround_time += turnaround_time[i];
  }

  // Print process table
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < num_processes; i++)
    printf("%d\t%d\t\t%d\t\t%d\n", process_id[i], burst_time[i], waiting_time[i], turnaround_time[i]);

  // Calculate average waiting time and average turnaround time
  avg_waiting_time /= num_processes;
  avg_turnaround_time /= num_processes;

  printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
  printf("Average Turnaround Time: %.2f\n\n", avg_turnaround_time);

  // Shortest job first (SJF) scheduling algorithm
  printf("Shortest job first (SJF) scheduling algorithm:\n\n");

  // Sort processes based on burst time (bubble sort algorithm)
  for (i = 0; i < num_processes - 1; i++) {
    for (j = 0; j < num_processes - i - 1; j++) {
      if (burst_time[j] > burst_time[j + 1]) {
        int temp_proc_id = process_id[j];
        process_id[j] = process_id[j + 1];
        process_id[j + 1] = temp_proc_id;

        int temp_burst_time = burst_time[j];
        burst_time[j] = burst_time[j + 1];
        burst_time[j + 1] = temp_burst_time;
      }
    }
  }

  // Calculate waiting time and turnaround time for each process
  for (i = 0; i < num_processes; i++) {
    if (i == 0)
      waiting_time[i] = 0;
    else
      waiting_time[i] = turnaround_time[i - 1];

    turnaround_time[i] = burst_time[i] + waiting_time[i];
    avg_waiting_time += waiting_time[i];
    avg_turnaround_time += turnaround_time[i];
  }

  // Print process table
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < num_processes; i++)
    printf("%d\t%d\t\t%d\t\t%d\n", process_id[i], burst_time[i], waiting_time[i], turnaround_time[i]);

  // Calculate average waiting time and average turnaround time
  avg_waiting_time /= num_processes;
  avg_turnaround_time /= num_processes;

  printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
  printf("Average Turnaround Time: %.2f\n\n", avg_turnaround_time);

  // Round robin (RR) scheduling algorithm
  printf("Round robin (RR) scheduling algorithm:\n\n");

  int t_quantum = 4;  // Time quantum for round robin algorithm
  int remaining_burst_time[num_processes];

  // Initialize remaining burst time for each process
  for (i = 0; i < num_processes; i++)
    remaining_burst_time[i] = burst_time[i];

  int current_time = 0;
  int done = 0;

  while (!done) {
    done = 1;

    // Traverse all processes
    for (i = 0; i < num_processes; i++) {
      if (remaining_burst_time[i] > 0) {
        done = 0;

        if (remaining_burst_time[i] > t_quantum) {
          current_time += t_quantum;
          remaining_burst_time[i] -= t_quantum;
        } else {
          current_time += remaining_burst_time[i];
          waiting_time[i] = current_time - burst_time[i] - waiting_time[i];
          remaining_burst_time[i] = 0;
        }
      }
    }
  }

  // Calculate waiting time and turnaround time for each process
  for (i = 0; i < num_processes; i++) {
    turnaround_time[i] = burst_time[i] + waiting_time[i];
    avg_waiting_time += waiting_time[i];
    avg_turnaround_time += turnaround_time[i];
  }

  // Print process table
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < num_processes; i++)
    printf("%d\t%d\t\t%d\t\t%d\n", process_id[i], burst_time[i], waiting_time[i], turnaround_time[i]);

  // Calculate average waiting time and average turnaround time
  avg_waiting_time /= num_processes;
  avg_turnaround_time /= num_processes;

  printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
  printf("Average Turnaround Time: %.2f\n\n", avg_turnaround_time);

  return 0;
}