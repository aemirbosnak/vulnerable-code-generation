//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// CPU scheduling algorithms
// But first, let's do a little dance! 

void cpuDance() {
  printf("CPU, CPU, let's get groovy!\n");
  printf("1, 2, cha-cha-cha!\n");
  printf("Round and round, we go\n");
  printf("Moving fast or moving slow\n");
  printf("1,2, cha-cha-cha!\n");
  printf("CPU is the star of the show!\n");
}

// First come, first served (FCFS) algorithm
// It's like waiting in line at the DMV

void FCFS(int burst_time[], int process_count) {
  int waiting_time[process_count], turnaround_time[process_count];
  int total_waiting_time = 0, total_turnaround_time = 0;
  int completion_time[process_count], i, j;
  completion_time[0] = burst_time[0];

  for (i = 1; i < process_count; i++) {
    completion_time[i] = completion_time[i-1] + burst_time[i];
  }

  for (i = 0; i < process_count; i++) {
    turnaround_time[i] = completion_time[i];
    waiting_time[i] = turnaround_time[i] - burst_time[i];
    total_waiting_time += waiting_time[i];
    total_turnaround_time += turnaround_time[i];
  }

  printf("First come, first served (FCFS):\n");

  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
  for (i = 0; i < process_count; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i], completion_time[i]);
  }

  float avg_waiting_time = (float)total_waiting_time/(float)process_count;
  float avg_turnaround_time = (float)total_turnaround_time / (float)process_count;
  printf("\nAverage waiting time: %.2f\n", avg_waiting_time);
  printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

// Shortest Job First (SJF) algorithm
// It's like trying to find the shortest checkout line at the grocery store

void SJF(int burst_time[], int process_count) {
  int i, j, temp;
  int waiting_time[process_count], turnaround_time[process_count];
  int completion_time[process_count], total_waiting_time = 0, total_turnaround_time = 0;
  float avg_waiting_time, avg_turnaround_time;
  bool finished[process_count];

  for (i = 0; i < process_count; i++) {
    finished[i] = false;
  }

  // Sort the processes by burst time
  for (i = 0; i < process_count; i++) {
    for (j = i + 1; j < process_count; j++) {
      if (burst_time[i] > burst_time[j]) {
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
      }
    }
  }

  completion_time[0] = burst_time[0];
  waiting_time[0] = 0;

  for (i = 1; i < process_count; i++) {
    waiting_time[i] = 0;
    for (j = 0; j < i; j++) {
      waiting_time[i] += burst_time[j];
    }
    completion_time[i] = waiting_time[i] + burst_time[i];
  }

  for (i = 0; i < process_count; i++) {
    turnaround_time[i] = completion_time[i];
    total_waiting_time += waiting_time[i];
    total_turnaround_time += turnaround_time[i];
  }

  printf("\nShortest Job First (SJF):\n");
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
  for (i = 0; i < process_count; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i], completion_time[i]);
  }

  avg_waiting_time = (float)total_waiting_time/ (float)process_count;
  avg_turnaround_time = (float)total_turnaround_time / (float)process_count;
  printf("\nAverage waiting time: %.2f\n", avg_waiting_time);
  printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

// Round Robin (RR) algorithm
// It's like passing a baton around a circuit

void RR(int burst_time[], int process_count, int time_quantum) {
  int i, j;
  int waiting_time[process_count], turnaround_time[process_count], remaining_time[process_count];
  int total_waiting_time = 0, total_turnaround_time = 0, t = 0, completion_time[process_count];

  for (i = 0; i < process_count; i++) {
    remaining_time[i] = burst_time[i];
  }

  while (true) {
    bool done = true;
    for (i = 0; i < process_count; i++) {
      if (remaining_time[i] > 0) {
        done = false;
        if (remaining_time[i] > time_quantum) {
          t += time_quantum;
          remaining_time[i] -= time_quantum;
        } else {
          t += remaining_time[i];
          waiting_time[i] = t - burst_time[i] - waiting_time[i];
          remaining_time[i] = 0;
          completion_time[i] = t;
        }
      }
    }
    if (done == true) {
      break;
    }
  }

  for (i = 0; i < process_count; i++) {
    turnaround_time[i] = completion_time[i] - burst_time[i];
    total_waiting_time += waiting_time[i];
    total_turnaround_time += turnaround_time[i];
  }

  printf("\nRound Robin (RR):\n");
  printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
  for (i = 0; i < process_count; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i], completion_time[i]);
  }

  float avg_waiting_time = (float)total_waiting_time/(float)process_count;
  float avg_turnaround_time = (float)total_turnaround_time / (float)process_count;
  printf("\nAverage waiting time: %.2f\n", avg_waiting_time);
  printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

int main() {
  cpuDance();

  int process_count, i, time_quantum;
  printf("\nEnter the number of processes: ");
  scanf("%d", &process_count);

  int burst_time[process_count];
  printf("\nEnter the burst times for each process:\n");
  for (i = 0; i < process_count; i++) {
    printf("Process %d: ", i+1);
    scanf("%d", &burst_time[i]);
  }

  printf("\nEnter the time quantum for the Round Robin algorithm: ");
  scanf("%d", &time_quantum);

  FCFS(burst_time, process_count);
  
  SJF(burst_time, process_count);

  RR(burst_time, process_count, time_quantum);

  return 0;
}