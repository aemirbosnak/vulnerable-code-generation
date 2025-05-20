//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_PROCESSES 10
#define MAX_BURST_TIME 20

typedef struct {
  int pid;
  int burstTime;
  int arrivalTime;
  int waitingTime;
  int turnaroundTime;
} Process;

void assignRandomValues(Process *process) {
  process->burstTime = (rand() % MAX_BURST_TIME) + 1;
  process->arrivalTime = rand() % 20;
  process->waitingTime = 0;
  process->turnaroundTime = 0;
}

void calculateWaitingTime(Process *process, int *waitingTime) {
  process->waitingTime = *waitingTime;
  *waitingTime += process->burstTime;
}

void calculateTurnaroundTime(Process *process) {
  process->turnaroundTime = process->burstTime + process->waitingTime;
}

void printTableHeader() {
  printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
}

void printProcess(Process process) {
  printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", process.pid, process.burstTime, process.arrivalTime, process.waitingTime, process.turnaroundTime);
}

void schedule(Process processes[], int n) {
  int currentTime = 0;
  int waitingTime = 0;

  printf("Initial Process Table\n");
  printTableHeader();
  for(int i=0; i<n; i++) {
    processes[i].pid = i+1;
    assignRandomValues(&processes[i]);
    printProcess(processes[i]);
  }

  printf("\n\nAfter Applying Shortest Job First CPU Scheduling Algorithm\n");
  printTableHeader();
  for(int i=0; i<n; i++) {
    int shortestJobIndex = -1;
    int shortestJobTime = MAX_BURST_TIME + 1;

    for(int j=0; j<n; j++) {
      if(processes[j].burstTime != -1 && processes[j].arrivalTime <= currentTime) {
        if(processes[j].burstTime < shortestJobTime) {
          shortestJobIndex = j;
          shortestJobTime = processes[j].burstTime;
        }
      }
    }

    if(shortestJobIndex != -1) {
      calculateWaitingTime(&processes[shortestJobIndex], &waitingTime);
      calculateTurnaroundTime(&processes[shortestJobIndex]);
      currentTime += processes[shortestJobIndex].burstTime;
      processes[shortestJobIndex].burstTime = -1;
      printProcess(processes[shortestJobIndex]);
    }
  }
}

int main() {
  Process processes[MAX_PROCESSES];
  int n;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  if(n > MAX_PROCESSES) {
    printf("Error: Maximum number of processes allowed are %d", MAX_PROCESSES);
    return 0;
  }

  srand(getpid());
  schedule(processes, n);

  return 0;
}