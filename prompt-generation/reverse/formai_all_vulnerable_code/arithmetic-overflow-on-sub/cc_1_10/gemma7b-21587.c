//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

struct Process {
  int id;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int waitingTime;
  int turnAroundTime;
};

void roundRobin(struct Process processes[], int n);

int main() {
  struct Process processes[MAX_PROCESS] = {
    {1, 0, 3, 0, 0, 0},
    {2, 2, 4, 0, 0, 0},
    {3, 4, 2, 0, 0, 0},
    {4, 6, 5, 0, 0, 0},
    {5, 8, 6, 0, 0, 0}
  };

  int n = 5;
  clock_t start, end;

  start = clock();
  roundRobin(processes, n);
  end = clock();

  printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}

void roundRobin(struct Process processes[], int n) {
  int currentProcess = 0;
  int quantum = 2;

  while (!processes[currentProcess].completionTime) {
    processes[currentProcess].waitingTime++;
    printf("Process %d is waiting...\n", processes[currentProcess].id);

    if (processes[currentProcess].burstTime > quantum) {
      processes[currentProcess].burstTime -= quantum;
      processes[currentProcess].completionTime = processes[currentProcess].arrivalTime + quantum;
    } else {
      processes[currentProcess].burstTime = 0;
      processes[currentProcess].completionTime = processes[currentProcess].arrivalTime + processes[currentProcess].burstTime;
    }

    currentProcess = (currentProcess + 1) % n;
  }
}