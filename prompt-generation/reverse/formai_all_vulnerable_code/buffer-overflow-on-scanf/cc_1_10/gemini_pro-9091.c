//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int priority;
} process;

typedef struct node {
  process p;
  struct node *next;
} node;

typedef struct queue {
  node *head;
  node *tail;
} queue;

void init_queue(queue *q) {
  q->head = NULL;
  q->tail = NULL;
}

void enqueue(queue *q, process p) {
  node *new_node = malloc(sizeof(node));
  new_node->p = p;
  new_node->next = NULL;
  if (q->tail == NULL) {
    q->head = q->tail = new_node;
  } else {
    q->tail->next = new_node;
    q->tail = new_node;
  }
}

process dequeue(queue *q) {
  if (q->head == NULL) {
    printf("Error: Queue is empty\n");
    exit(1);
  }
  node *temp = q->head;
  q->head = q->head->next;
  if (q->head == NULL) {
    q->tail = NULL;
  }
  process p = temp->p;
  free(temp);
  return p;
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  process processes[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the arrival time of process %d: ", i + 1);
    scanf("%d", &processes[i].arrival_time);
    printf("Enter the burst time of process %d: ", i + 1);
    scanf("%d", &processes[i].burst_time);
    processes[i].remaining_time = processes[i].burst_time;
    printf("Enter the priority of process %d: ", i + 1);
    scanf("%d", &processes[i].priority);
  }

  queue ready_queue;
  init_queue(&ready_queue);

  int t = 0;
  while (!ready_queue.head == NULL) {
    int i = 0;
    while (i < n && processes[i].arrival_time <= t) {
      enqueue(&ready_queue, processes[i]);
      i++;
    }

    process p = dequeue(&ready_queue);
    p.remaining_time--;
    t++;
    if (p.remaining_time == 0) {
      printf("Process %d completed at time %d\n", p.pid, t);
    } else {
      enqueue(&ready_queue, p);
    }
  }

  return 0;
}