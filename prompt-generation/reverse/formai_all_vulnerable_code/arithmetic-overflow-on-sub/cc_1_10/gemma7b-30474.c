//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUEUE_SIZE 5

typedef struct process {
  int process_id;
  int arrival_time;
  int service_time;
  int remaining_service_time;
  struct process* next;
} process;

process* create_process(int process_id, int arrival_time, int service_time) {
  process* new_process = (process*)malloc(sizeof(process));
  new_process->process_id = process_id;
  new_process->arrival_time = arrival_time;
  new_process->service_time = service_time;
  new_process->remaining_service_time = service_time;
  new_process->next = NULL;
  return new_process;
}

void add_process_to_queue(process* new_process, process** head) {
  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
    *head = new_process;
  }
}

void round_robin(process** head) {
  time_t start_time = time(NULL);
  process* current_process = (*head);
  while (current_process) {
    time_t end_time = time(NULL);
    int time_spent = end_time - start_time;
    current_process->remaining_service_time -= time_spent;
    if (current_process->remaining_service_time <= 0) {
      printf("Process %d completed.\n", current_process->process_id);
      free(current_process);
      current_process = (*head)->next;
    } else {
      start_time = end_time;
    }
  }
}

int main() {
  process* processes[MAX_PROCESSES];
  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes[i] = NULL;
  }

  // Create a few processes
  processes[0] = create_process(1, 0, 5);
  processes[1] = create_process(2, 2, 4);
  processes[2] = create_process(3, 4, 3);

  // Add the processes to the queue
  process* head = NULL;
  for (int i = 0; i < MAX_PROCESSES; i++) {
    if (processes[i] != NULL) {
      add_process_to_queue(processes[i], &head);
    }
  }

  // Round robin scheduling
  round_robin(&head);

  return 0;
}