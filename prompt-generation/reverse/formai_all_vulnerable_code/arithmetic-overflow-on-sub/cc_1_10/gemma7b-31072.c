//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int id;
  int arrivalTime;
  int burstTime;
  int completionTime;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int burstTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->id = id;
  process->arrivalTime = arrivalTime;
  process->burstTime = burstTime;
  process->completionTime = -1;
  process->next = NULL;
  return process;
}

void addProcess(Process** head, int id, int arrivalTime, int burstTime) {
  Process* process = createProcess(id, arrivalTime, burstTime);
  if (*head == NULL) {
    *head = process;
  } else {
    (*head)->next = process;
  }
}

void roundRobin(Process** head) {
  time_t currentTime = time(NULL);
  Process* currentProcess = *head;
  while (currentProcess) {
    if (currentTime - currentProcess->arrivalTime >= currentProcess->burstTime) {
      currentProcess->completionTime = currentTime;
      currentProcess = currentProcess->next;
    }
    sleep(1);
  }
}

int main() {
  Process* processes = NULL;
  addProcess(&processes, 1, 0, 5);
  addProcess(&processes, 2, 2, 4);
  addProcess(&processes, 3, 3, 3);
  addProcess(&processes, 4, 4, 2);
  addProcess(&processes, 5, 5, 1);

  roundRobin(&processes);

  for (Process* process = processes; process; process = process->next) {
    printf("Process ID: %d, Completion Time: %d\n", process->id, process->completionTime);
  }

  return 0;
}