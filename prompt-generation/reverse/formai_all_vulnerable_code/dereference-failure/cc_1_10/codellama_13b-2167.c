//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
  #include <stdlib.h>

  typedef struct Process {
    int pid;
    int burst_time;
    int arrival_time;
  } Process;

  typedef struct Queue {
    Process *processes;
    int num_processes;
    int current_time;
  } Queue;

  void enqueue(Queue *q, Process *p) {
    q->processes[q->num_processes++] = *p;
  }

  Process* dequeue(Queue *q) {
    Process *p = &q->processes[0];
    for (int i = 1; i < q->num_processes; i++) {
      if (p->arrival_time > q->processes[i].arrival_time) {
        p = &q->processes[i];
      }
    }
    q->num_processes--;
    return p;
  }

  void run_cpu_scheduler(Queue *q, int quantum) {
    while (q->num_processes > 0) {
      Process *p = dequeue(q);
      int current_time = p->arrival_time;
      int burst_time = p->burst_time;
      while (burst_time > 0) {
        if (burst_time > quantum) {
          current_time += quantum;
          burst_time -= quantum;
        } else {
          current_time += burst_time;
          burst_time = 0;
        }
        printf("Process %d is running for %d units of time\n", p->pid, quantum);
        if (q->num_processes > 0) {
          enqueue(q, p);
        }
      }
    }
  }

  int main() {
    Process p1 = {1, 10, 0};
    Process p2 = {2, 5, 2};
    Process p3 = {3, 3, 4};
    Process p4 = {4, 8, 6};
    Process p5 = {5, 4, 9};
    Queue q = {NULL, 0, 0};
    enqueue(&q, &p1);
    enqueue(&q, &p2);
    enqueue(&q, &p3);
    enqueue(&q, &p4);
    enqueue(&q, &p5);
    run_cpu_scheduler(&q, 2);
    return 0;
  }