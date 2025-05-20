//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// CPU Scheduling Algorithms
// Relaxed Style

// Structure for process
struct Process {
  int pid;
  int arrival_time;
  int burst_time;
  int priority;
};

// Function to print process information
void printProcess(struct Process *p) {
  printf("Process %d:\n", p->pid);
  printf("  Arrival time: %d\n", p->arrival_time);
  printf("  Burst time: %d\n", p->burst_time);
  printf("  Priority: %d\n", p->priority);
}

// Function to sort processes by arrival time
void sortByArrivalTime(struct Process *p, int n) {
  int i, j;
  struct Process temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (p[j].arrival_time > p[j + 1].arrival_time) {
        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
}

// Function to sort processes by priority
void sortByPriority(struct Process *p, int n) {
  int i, j;
  struct Process temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (p[j].priority > p[j + 1].priority) {
        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
}

// Function to sort processes by burst time
void sortByBurstTime(struct Process *p, int n) {
  int i, j;
  struct Process temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (p[j].burst_time > p[j + 1].burst_time) {
        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
}

// Function to execute a process
void executeProcess(struct Process *p) {
  printf("Executing process %d\n", p->pid);
  // Simulate process execution
  printf("  Execution time: %d\n", p->burst_time);
}

// Function to schedule processes
void scheduleProcesses(struct Process *p, int n) {
  int i, j;
  int currentTime = 0;
  int completedProcesses = 0;
  while (completedProcesses < n) {
    // Find next process to execute
    for (i = 0; i < n; i++) {
      if (p[i].arrival_time <= currentTime) {
        // Execute process
        executeProcess(&p[i]);
        // Update current time
        currentTime += p[i].burst_time;
        // Increment completed processes
        completedProcesses++;
        break;
      }
    }
  }
}

// Driver code
int main() {
  // Initialize processes
  struct Process p1 = {1, 0, 5, 3};
  struct Process p2 = {2, 1, 4, 2};
  struct Process p3 = {3, 2, 3, 1};
  struct Process p4 = {4, 3, 6, 4};
  struct Process p5 = {5, 5, 7, 5};
  struct Process p6 = {6, 6, 4, 3};
  struct Process p7 = {7, 7, 8, 1};
  struct Process p8 = {8, 9, 3, 2};
  struct Process p9 = {9, 10, 5, 3};
  struct Process p10 = {10, 11, 4, 4};

  // Print initial processes
  printf("Initial processes:\n");
  printProcess(&p1);
  printProcess(&p2);
  printProcess(&p3);
  printProcess(&p4);
  printProcess(&p5);
  printProcess(&p6);
  printProcess(&p7);
  printProcess(&p8);
  printProcess(&p9);
  printProcess(&p10);

  // Sort processes by arrival time
  sortByArrivalTime(&p1, 10);

  // Print sorted processes
  printf("\nSorted processes by arrival time:\n");
  printProcess(&p1);
  printProcess(&p2);
  printProcess(&p3);
  printProcess(&p4);
  printProcess(&p5);
  printProcess(&p6);
  printProcess(&p7);
  printProcess(&p8);
  printProcess(&p9);
  printProcess(&p10);

  // Sort processes by priority
  sortByPriority(&p1, 10);

  // Print sorted processes
  printf("\nSorted processes by priority:\n");
  printProcess(&p1);
  printProcess(&p2);
  printProcess(&p3);
  printProcess(&p4);
  printProcess(&p5);
  printProcess(&p6);
  printProcess(&p7);
  printProcess(&p8);
  printProcess(&p9);
  printProcess(&p10);

  // Sort processes by burst time
  sortByBurstTime(&p1, 10);

  // Print sorted processes
  printf("\nSorted processes by burst time:\n");
  printProcess(&p1);
  printProcess(&p2);
  printProcess(&p3);
  printProcess(&p4);
  printProcess(&p5);
  printProcess(&p6);
  printProcess(&p7);
  printProcess(&p8);
  printProcess(&p9);
  printProcess(&p10);

  // Schedule processes
  scheduleProcesses(&p1, 10);

  return 0;
}