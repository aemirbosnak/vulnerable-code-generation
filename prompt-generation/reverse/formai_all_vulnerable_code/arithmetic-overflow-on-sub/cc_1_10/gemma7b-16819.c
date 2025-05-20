//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUMBER 5
#define MAX_PROCESS_TIME 10

typedef struct Process {
  int process_number;
  int arrival_time;
  int execution_time;
  struct Process* next;
} Process;

Process* createProcess(int process_number, int arrival_time, int execution_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_number = process_number;
  process->arrival_time = arrival_time;
  process->execution_time = execution_time;
  process->next = NULL;
  return process;
}

void addProcess(Process* head, int process_number, int arrival_time, int execution_time) {
  Process* process = createProcess(process_number, arrival_time, execution_time);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void roundRobin(Process* head) {
  time_t start_time = time(NULL);
  int current_time = 0;
  Process* current_process = head;

  while (current_process) {
    int remaining_time = current_process->execution_time - current_time;
    if (remaining_time > 0) {
      current_time++;
    } else {
      current_time = 0;
      current_process = current_process->next;
    }
  }

  time_t end_time = time(NULL);
  printf("Total time: %d seconds\n", end_time - start_time);
}

int main() {
  Process* head = NULL;
  addProcess(head, 1, 0, 5);
  addProcess(head, 2, 2, 4);
  addProcess(head, 3, 4, 3);
  addProcess(head, 4, 6, 2);
  addProcess(head, 5, 8, 1);

  roundRobin(head);

  return 0;
}