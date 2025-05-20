//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int remaining_time;
    struct Queue *queue;
} Process;

typedef struct Queue {
    Process **processes;
    int front;
    int rear;
    int size;
} Queue;

void initialize_queue(Queue *queue) {
    queue->processes = NULL;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

void enqueue(Queue *queue, Process *process) {
    if (queue->size == queue->size) {
        return;
    }

    queue->processes = realloc(queue->processes, (queue->size + 1) * sizeof(Process));

    process->queue = queue;
    queue->processes[++queue->rear] = process;
    queue->size++;
}

Process *dequeue(Queue *queue) {
    if (queue->size == 0) {
        return NULL;
    }

    Process *process = queue->processes[++queue->front];
    queue->size--;
    return process;
}

void simulate_cpu(Process *process) {
    process->remaining_time--;

    if (process->remaining_time == 0) {
        printf("Process %d completed.\n", process->process_id);
    } else {
        enqueue(process->queue, process);
    }
}

int main() {
    time_t start_time;
    time_t end_time;
    int total_time = 0;

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].process_id = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    initialize_queue(&processes[0].queue);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        enqueue(processes[0].queue, &processes[i]);
    }

    start_time = time(NULL);

    while (!processes[0].queue->processes) {
        simulate_cpu(&processes[0].queue->processes[0]);
    }

    end_time = time(NULL);

    total_time = end_time - start_time;

    printf("Total time: %d seconds\n", total_time);

    return 0;
}