//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_PROCESS 10
#define MAX_QUEUE 10

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

struct queue {
    int front;
    int rear;
    struct process queue[MAX_QUEUE];
};

void enqueue(struct queue *q, struct process p) {
    if ((q->rear + 1) % MAX_QUEUE == q->front) {
        printf("\nQueue is full!");
        exit(0);
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE;
        q->queue[q->rear] = p;
    }
}

struct process dequeue(struct queue *q) {
    struct process p;
    if (q->front == -1) {
        printf("\nQueue is empty!");
        exit(0);
    }
    else {
        p = q->queue[q->front];
        q->front = (q->front + 1) % MAX_QUEUE;
    }
    return p;
}

void execute_process(struct process p, int quantum) {
    int i;
    for (i = 0; i < p.burst_time; i++) {
        printf("\nProcess %d is executing", p.pid);
        fflush(stdout);
        sleep(1);
    }
}

void round_robin(int quantum) {
    int i, j;
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int count = 0;
    int sum_wt = 0;
    int sum_tat = 0;
    for (i = 0; i < MAX_PROCESS; i++) {
        if (i % 2 == 0) {
            struct process p;
            p.pid = i;
            p.burst_time = rand() % 10 + 1;
            p.waiting_time = 0;
            p.turnaround_time = 0;
            enqueue(&q, p);
        }
    }

    while (count < MAX_PROCESS) {
        struct process p = dequeue(&q);
        printf("\nProcess %d is selected", p.pid);
        execute_process(p, quantum);
        p.turnaround_time = p.waiting_time + p.burst_time;
        sum_wt += p.waiting_time;
        sum_tat += p.turnaround_time;
        count++;
        enqueue(&q, p);
    }

    printf("\nAverage waiting time: %f", (float)sum_wt / MAX_PROCESS);
    printf("\nAverage turnaround time: %f", (float)sum_tat / MAX_PROCESS);
}

int main() {
    int quantum;
    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);
    round_robin(quantum);
    return 0;
}