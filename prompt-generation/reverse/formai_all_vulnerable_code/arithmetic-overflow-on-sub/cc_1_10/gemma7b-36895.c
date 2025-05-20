//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

struct Process {
  int id;
  int arrivalTime;
  int executionTime;
  int remainingTime;
  int state;
  struct Process* next;
};

struct RoundRobin {
  struct Process* head;
  struct Process* tail;
  int currentProcess;
  int timeQuantum;
  struct RoundRobin* next;
};

void createProcess(struct Process** head, int id, int arrivalTime, int executionTime) {
  struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
  newProcess->id = id;
  newProcess->arrivalTime = arrivalTime;
  newProcess->executionTime = executionTime;
  newProcess->remainingTime = executionTime;
  newProcess->state = 0;
  newProcess->next = NULL;

  if (*head == NULL) {
    *head = newProcess;
  } else {
    (*head)->next = newProcess;
  }
}

void scheduleProcess(struct RoundRobin* roundRobin) {
  time_t currentTime = time(NULL);
  struct Process* currentProcess = roundRobin->head;

  // Check if the current process has finished execution or if the time quantum has elapsed
  if (currentProcess->remainingTime == 0 || currentTime - currentProcess->arrivalTime >= roundRobin->timeQuantum) {
    currentProcess->state = 0;
    roundRobin->currentProcess = (roundRobin->currentProcess + 1) % MAX_PROCESSES;
    currentProcess = roundRobin->head;
  } else {
    currentProcess->remainingTime--;
  }

  roundRobin->head = currentProcess;
}

int main() {
  struct RoundRobin* roundRobin = (struct RoundRobin*)malloc(sizeof(struct RoundRobin));
  roundRobin->head = NULL;
  roundRobin->tail = NULL;
  roundRobin->currentProcess = 0;
  roundRobin->timeQuantum = MAX_TIME;

  createProcess(&roundRobin->head, 1, 0, 5);
  createProcess(&roundRobin->head, 2, 2, 3);
  createProcess(&roundRobin->head, 3, 4, 4);
  createProcess(&roundRobin->head, 4, 6, 2);
  createProcess(&roundRobin->head, 5, 8, 3);

  for (int i = 0; i < MAX_TIME; i++) {
    scheduleProcess(roundRobin);
  }

  return 0;
}