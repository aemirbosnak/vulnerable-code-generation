//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESSES 100
#define QUANTUM 10

struct Process {
    int id;
    int arrival_time;
    int priority;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

struct ProcessQueue {
    struct Process *processes[MAX_PROCESSES];
    int front;
    int rear;
};

struct ProcessQueue *createQueue() {
    struct ProcessQueue *queue = (struct ProcessQueue*) malloc(sizeof(struct ProcessQueue));
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

bool isQueueEmpty(struct ProcessQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool isQueueFull(struct ProcessQueue *queue) {
    return (queue->rear == MAX_PROCESSES - 1);
}

void enqueue(struct ProcessQueue *queue, struct Process *process) {
    if (isQueueFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        ++queue->rear;
    }

    queue->processes[queue->rear] = process;
}

struct Process *dequeue(struct ProcessQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return NULL;
    }

    struct Process *process = queue->processes[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        ++queue->front;
    }

    return process;
}

struct Process *createProcess(int id) {
    srand(time(NULL));

    struct Process *process = (struct Process*) malloc(sizeof(struct Process));
    process->id = id;
    process->arrival_time = rand() % 50 + 1; // Random arrival time between 1 and 50
    process->priority = rand() % 5 + 1; // Random priority between 1 and 5
    process->burst_time = rand() % 30 + 1; // Random burst time between 1 and 30
    process->remaining_time = process->burst_time;
    process->waiting_time = 0;
    process->turnaround_time = 0;

    return process;
}

void displayProcess(struct Process *process) {
    printf("\nProcess ID: %d", process->id);
    printf("\nArrival Time: %d", process->arrival_time);
    printf("\nPriority: %d", process->priority);
    printf("\nBurst Time: %d", process->burst_time);
    printf("\nRemaining Time: %d", process->remaining_time);
    printf("\nWaiting Time: %d", process->waiting_time);
    printf("\nTurnaround Time: %d\n", process->turnaround_time);
}

float calculateAverageWaitingTime(struct Process **processes, int n) {
    int total_waiting_time = 0;
    for (int i = 0; i < n; ++i) {
        total_waiting_time += processes[i]->waiting_time;
    }

    return ((float) total_waiting_time) / n;
}

float calculateAverageTurnaroundTime(struct Process **processes, int n) {
    int total_turnaround_time = 0;
    for (int i = 0; i < n; ++i) {
        total_turnaround_time += processes[i]->turnaround_time;
    }

    return ((float) total_turnaround_time) / n;
}

void FIFO(struct Process **processes, int n) {
    int current_time = 0;
    for (int i = 0; i < n; ++i) {
        struct Process *process = processes[i];
        process->waiting_time = current_time - process->arrival_time;
        current_time += process->burst_time;
        process->turnaround_time = current_time - process->arrival_time;

        displayProcess(process);
    }

    printf("\nAverage Waiting Time: %f", calculateAverageWaitingTime(processes, n));
    printf("\nAverage Turnaround Time: %f\n", calculateAverageTurnaroundTime(processes, n));
}

void RoundRobin(struct Process **processes, int n) {
    struct ProcessQueue *queue = createQueue();
    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        for (int i = 0; i < n; ++i) {
            struct Process *process = processes[i];
            if (process->arrival_time <= current_time && process->remaining_time > 0) {
                enqueue(queue, process);
            }
        }

        if (!isQueueEmpty(queue)) {
            struct Process *process = dequeue(queue);
            process->remaining_time -= QUANTUM;
            current_time += QUANTUM;

            if (process->remaining_time <= 0) {
                process->turnaround_time = current_time - process->arrival_time;
                process->waiting_time = process->turnaround_time - process->burst_time;
                ++completed_processes;

                displayProcess(process);
            } else {
                enqueue(queue, process);
            }
        } else {
            ++current_time;
        }
    }

    printf("\nAverage Waiting Time: %f", calculateAverageWaitingTime(processes, n));
    printf("\nAverage Turnaround Time: %f\n", calculateAverageTurnaroundTime(processes, n));
}

void Priority(struct Process **processes, int n) {
    struct ProcessQueue *queue = createQueue();
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; ++i) {
            struct Process *process = processes[i];
            if (process->arrival_time <= current_time && process->remaining_time > 0) {
                enqueue(queue, process);
            }
        }

        if (!isQueueEmpty(queue)) {
            int highest_priority = -1;
            struct Process *highest_priority_process = NULL;

            for (int i = queue->front; i <= queue->rear; ++i) {
                struct Process *process = queue->processes[i];
                if (process->priority > highest_priority && process->remaining_time > 0) {
                    highest_priority = process->priority;
                    highest_priority_process = process;
                }
            }

            highest_priority_process->remaining_time -= 1;
            ++current_time;

            if (highest_priority_process->remaining_time <= 0) {
                highest_priority_process->turnaround_time = current_time - highest_priority_process->arrival_time;
                highest_priority_process->waiting_time = highest_priority_process->turnaround_time - highest_priority_process->burst_time;
                ++completed_processes;

                displayProcess(highest_priority_process);
            }
        } else {
            ++current_time;
        }
    }

    printf("\nAverage Waiting Time: %f", calculateAverageWaitingTime(processes, n));
    printf("\nAverage Turnaround Time: %f\n", calculateAverageTurnaroundTime(processes, n));
}

int main() {
    struct Process *processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; ++i) {
        processes[i] = createProcess(i + 1);
        displayProcess(processes[i]);
    }

    printf("\nFIFO Algorithm:\n");
    FIFO(processes, n);

    printf("\nRound Robin Algorithm:\n");
    RoundRobin(processes, n);

    printf("\nPriority Algorithm:\n");
    Priority(processes, n);

    return 0;
}