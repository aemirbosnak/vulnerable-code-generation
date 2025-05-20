//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS 10

typedef struct Process {
  int pid;
  char name[20];
  int burstTime;
  int waitingTime;
  int turnaroundTime;
} Process;

void roundRobin(Process processes[], int n) {
  int currentProcess = 0;
  int timeQuantum = 5;

  while (n > 0) {
    processes[currentProcess].waitingTime--;
    if (processes[currentProcess].waitingTime == 0) {
      processes[currentProcess].turnaroundTime = timeQuantum + processes[currentProcess].burstTime;
      n--;
      currentProcess = (currentProcess + 1) % n;
    } else {
      sleep(timeQuantum);
      currentProcess = (currentProcess + 1) % n;
    }
  }
}

int main() {
  Process processes[MAX_PROCESS];
  int n = 0;

  // Create processes
  while (n < MAX_PROCESS) {
    processes[n].pid = n + 1;
    printf("Enter process name: ");
    scanf("%s", processes[n].name);
    printf("Enter burst time: ");
    scanf("%d", &processes[n].burstTime);
    n++;
  }

  // Round robin scheduling
  roundRobin(processes, n);

  // Print results
  for (int i = 0; i < n; i++) {
    printf("Process name: %s\n", processes[i].name);
    printf("Waiting time: %d\n", processes[i].waitingTime);
    printf("Turnaround time: %d\n", processes[i].turnaroundTime);
    printf("\n");
  }

  return 0;
}