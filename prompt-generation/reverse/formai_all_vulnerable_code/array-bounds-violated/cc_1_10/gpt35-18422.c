//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>

// Custom Struct to represent Process
struct process {
  int pid;
  int burst_time;
  int arrival_time;
  int waiting_time;
  int turnaround_time;
};

// Function to accept input of details of all processes
void acceptProcessDetails(struct process proc[], int n) {
  for(int i=0; i<n; i++) {
    printf("\nEnter Process %d Details: ", i+1);
    printf("\n\tProcess ID: ");
    scanf("%d", &proc[i].pid);
    printf("\n\tBurst Time: ");
    scanf("%d", &proc[i].burst_time);
    printf("\n\tArrival Time: ");
    scanf("%d", &proc[i].arrival_time);
  }
}

// Function to apply FCFS Scheduling Algorithm
void applyFCFS(struct process proc[], int n) {
  int waiting_time[n], turnaround_time[n], completion_time[n];
  float avg_waiting_time = 0, avg_turnaround_time = 0;
  completion_time[0] = proc[0].burst_time;
  for(int i=1; i<n; i++) {
    completion_time[i] = completion_time[i-1] + proc[i].burst_time;
  }
  for(int i=0; i<n; i++) {
    turnaround_time[i] = completion_time[i] - proc[i].arrival_time;
    waiting_time[i] = turnaround_time[i] - proc[i].burst_time;
    avg_waiting_time += waiting_time[i];
    avg_turnaround_time += turnaround_time[i];
  }
  printf("\nFCFS Scheduling Algorithm:\n");
  printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
  for(int i=0; i<n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, waiting_time[i], turnaround_time[i], completion_time[i]);
  }
  printf("\nAverage Waiting Time: %f", avg_waiting_time/n);
  printf("\nAverage Turnaround Time: %f", avg_turnaround_time/n);
}

// Function to apply SRTF Scheduling Algorithm
void applySRTF(struct process proc[], int n) {
  int remaining_time[n], completion_time[n], t = 0, shortest = -1, prev_shortest = 0, flag = 0, count = 0, waiting_time[n], turnaround_time[n];
  float avg_waiting_time=0, avg_turnaround_time=0;
  for(int i=0; i<n; i++) {
    remaining_time[i] = proc[i].burst_time;
  }
  while(count != n) {
    for(int i=0; i<n; i++) {
      if(proc[i].arrival_time <= t && remaining_time[i] > 0 && (shortest == -1 || remaining_time[i] < remaining_time[shortest])) {
        shortest = i;
        flag = 1;
      }
    }
    if(flag == 0) {
      t++;
      continue;
    } 
    remaining_time[shortest]--;
    shortest = shortest;
    if(remaining_time[shortest] == 0) {
      count++;
      completion_time[shortest] = t+1;
      waiting_time[shortest] = completion_time[shortest] - proc[shortest].burst_time - proc[shortest].arrival_time;
      turnaround_time[shortest] = completion_time[shortest] - proc[shortest].arrival_time;
      avg_waiting_time += waiting_time[shortest];
      avg_turnaround_time += turnaround_time[shortest];
    }
    t++;
  }
  printf("\n\nSRTF Scheduling:\n");
  printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
  for(int i=0; i<n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, waiting_time[i], turnaround_time[i], completion_time[i]);
  }
  printf("\nAverage Waiting Time: %f", avg_waiting_time/n);
  printf("\nAverage Turnaround Time: %f", avg_turnaround_time/n);
}

// Main Function to drive the program
int main() {
  int n, choice;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  struct process proc[n];
  acceptProcessDetails(proc, n);
  printf("Which CPU Scheduling Algorithm would you like to apply?\n");
  printf("\n1. First Come First Serve (FCFS) Scheduling\n2. Shortest Remaining Time First (SRTF) Scheduling\n");
  printf("\nEnter your choice: ");
  scanf("%d", &choice);
  switch(choice) {
    case 1: applyFCFS(proc, n);
            break;
    case 2: applySRTF(proc, n);
            break;
    default: printf("\nInvalid Choice!");
             break;
  }
  return 0;
}