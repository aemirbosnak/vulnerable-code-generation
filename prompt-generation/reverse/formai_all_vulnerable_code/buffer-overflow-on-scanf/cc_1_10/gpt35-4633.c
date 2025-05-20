//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define QUANTUM 2

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

struct process_queue {
    struct process queue[MAX_PROCESSES];
    int front;
    int rear;
    int size;
};

void init_queue(struct process_queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(struct process_queue* q, struct process p) {
    if (q->size == MAX_PROCESSES) {
        printf("Error: Queue is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_PROCESSES;
    q->queue[q->rear] = p;
    q->size++;
}

struct process dequeue(struct process_queue* q) {
    if (q->size == 0) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }

    struct process p = q->queue[q->front];
    q->front = (q->front + 1) % MAX_PROCESSES;
    q->size--;
    return p;
}

int is_empty(struct process_queue* q) {
    return q->size == 0;
}

int main() {
    int i, j, n, total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;
    struct process processes[MAX_PROCESSES], p;
    struct process_queue ready_queue;
    init_queue(&ready_queue);

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of process %d: ", i);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_burst_time = processes[i].burst_time;
        processes[i].pid = i;
    }

    int current_time = 0;
    i = 0;

    while (!is_empty(&ready_queue) || i < n) {
        while (i < n && processes[i].arrival_time <= current_time) {
            enqueue(&ready_queue, processes[i]);
            i++;
        }

        if (!is_empty(&ready_queue)) {
            p = dequeue(&ready_queue);

            if (p.remaining_burst_time <= QUANTUM) {
                current_time += p.remaining_burst_time;
                p.completion_time = current_time;
                p.turnaround_time = p.completion_time - p.arrival_time;
                p.waiting_time = p.turnaround_time - p.burst_time;
                total_waiting_time += p.waiting_time;
                total_turnaround_time += p.turnaround_time;
            } else {
                p.remaining_burst_time -= QUANTUM;
                current_time += QUANTUM;
                enqueue(&ready_queue, p);
            }
        }
        else {
            current_time++;
        }
    }

    avg_waiting_time = (float) total_waiting_time / n;
    avg_turnaround_time = (float) total_turnaround_time / n;

    printf("PID\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n",
            processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
            processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}