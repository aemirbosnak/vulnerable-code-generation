//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hello, let's play a game of CPU Scheduling Algorithms!\n");
  printf("We will simulate the Round Robin algorithm, are you ready?\n\n");
  
  // Get user input for time quantum
  int timeQuantum;
  printf("What should the time quantum be? (in ms) ");
  scanf("%d", &timeQuantum);
  printf("\n");

  // Create process array with burst times
  int process[5] = {20, 10, 5, 15, 25};

  // Calculate number of processes
  int numProcesses = sizeof(process) / sizeof(process[0]);

  // Create array for waiting times and initialize to 0
  int waitingTimes[numProcesses];
  for (int i = 0; i < numProcesses; i++) {
    waitingTimes[i] = 0;
  }

  // Run Round Robin algorithm
  int time = 0;
  int i = 0;
  while (i < numProcesses) {
    if (process[i] > 0) {
      // Process haven't reached end
      printf("Time: %dms, Process %d running, Burst Time: %dms\n", time, i, process[i]);

      if (process[i] <= timeQuantum) {
        // Process will finish within time quantum
        time += process[i];
        process[i] = 0;
        waitingTimes[i] = time - process[i];
        printf("Time: %dms, Process %d finished, Waiting Time: %dms\n\n", time, i, waitingTimes[i]);
        i++;

      } else {
        // Process will not finish in time quantum
        time += timeQuantum;
        process[i] -= timeQuantum; 
        printf("Time: %dms, Quantum expired, Process %d preempted, Burst Time remaining: %dms\n\n", time, i, process[i]);

        // Move onto next process
        i = (i + 1) % numProcesses;

      }

    } else {
      // Process has finished already
      i++;

    }
  }

  // Calculate average waiting time
  int totalWaitingTime = 0;
  for (int i = 0; i < numProcesses; i++) {
    totalWaitingTime += waitingTimes[i];
  }
  float avgWaitingTime = (float) totalWaitingTime / numProcesses;

  // Print final summary
  printf("Game over! Average Waiting Time: %.2fms\n", avgWaitingTime);
  
  return 0;
}