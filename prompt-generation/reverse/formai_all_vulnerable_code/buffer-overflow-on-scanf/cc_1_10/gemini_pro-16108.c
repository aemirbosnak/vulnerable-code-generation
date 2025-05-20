//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    struct process *next;
} process;

typedef struct queue {
    process *head;
    process *tail;
} queue;

void enqueue(queue *q, process *p) {
    if (q->head == NULL) {
        q->head = p;
        q->tail = p;
    } else {
        q->tail->next = p;
        q->tail = p;
    }
}

process *dequeue(queue *q) {
    if (q->head == NULL) {
        return NULL;
    } else {
        process *p = q->head;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        return p;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process *processes = (process *)malloc(n * sizeof(process));

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &processes[i].priority);

        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].next = NULL;
    }

    queue ready_queue;
    ready_queue.head = NULL;
    ready_queue.tail = NULL;

    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (ready_queue.head != NULL) {
        process *p = dequeue(&ready_queue);

        if (p->remaining_time <= 0) {
            continue;
        }

        int waiting_time = current_time - p->arrival_time;
        int turnaround_time = current_time + p->remaining_time - p->arrival_time;

        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;

        current_time += p->remaining_time;

        p->remaining_time = 0;

        printf("Process %d completed at time %d\n", p->pid, current_time);
        printf("Waiting time: %d\n", waiting_time);
        printf("Turnaround time: %d\n", turnaround_time);
        printf("\n");
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}