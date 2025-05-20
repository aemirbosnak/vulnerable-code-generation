//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int process_id;
  char name[20];
  int arrival_time;
  int execution_time;
  int remaining_time;
  struct Queue* queue;
} Process;

typedef struct Queue {
  Process** processes;
  int size;
  int front;
  int rear;
} Queue;

void initialize_queue(Queue* queue) {
  queue->processes = NULL;
  queue->size = 0;
  queue->front = 0;
  queue->rear = -1;
}

void enqueue(Queue* queue, Process* process) {
  queue->processes = realloc(queue->processes, (queue->size + 1) * sizeof(Process*));
  queue->processes[queue->rear] = process;
  queue->rear++;
  queue->size++;
}

Process* dequeue(Queue* queue) {
  if (queue->size == 0) {
    return NULL;
  }
  queue->front++;
  return queue->processes[queue->front - 1];
}

void simulate_cpu_scheduling(Process* processes) {
  int time = 0;
  while (!processes[0].remaining_time) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
      if (processes[i].remaining_time > 0) {
        processes[i].remaining_time--;
        time++;
      }
    }

    printf("Time: %d\n", time);
    for (int i = 0; i < MAX_PROCESSES; i++) {
      printf("Process: %s, Remaining Time: %d\n", processes[i].name, processes[i].remaining_time);
    }
    printf("\n");
  }
}

int main() {
  Process processes[MAX_PROCESSES];

  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes[i].process_id = i + 1;
    processes[i].arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[i].execution_time = rand() % MAX_QUEUE_SIZE;
    processes[i].remaining_time = processes[i].execution_time;
  }

  initialize_queue(&processes[0].queue);

  for (int i = 0; i < MAX_PROCESSES; i++) {
    enqueue(processes[0].queue, &processes[i]);
  }

  simulate_cpu_scheduling(processes);

  return 0;
}