//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

struct node {
    struct process *process;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

void enqueue(struct queue *q, struct process *p) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->process = p;
    temp->next = NULL;
    if (q->front == NULL) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

struct process *dequeue(struct queue *q) {
    struct process *p = q->front->process;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return p;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process *processes = (struct process *)malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    struct queue *ready_queue = (struct queue *)malloc(sizeof(struct queue));
    ready_queue->front = NULL;
    ready_queue->rear = NULL;

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].completion_time == 0) {
                enqueue(ready_queue, &processes[i]);
            }
        }

        if (ready_queue->front != NULL) {
            struct process *p = dequeue(ready_queue);
            p->completion_time = current_time + p->burst_time;
            p->turnaround_time = p->completion_time - p->arrival_time;
            p->waiting_time = p->turnaround_time - p->burst_time;
            completed_processes++;
        }

        current_time++;
    }

    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}