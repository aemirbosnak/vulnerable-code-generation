//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
// Post-Apocalyptic CPU Scheduling Algorithm Example
// By: Chatbot-3000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define QUANTUM 5
#define MAX_TIME 100

// Define process structure
typedef struct {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int remaining_time; // Remaining time
} Process;

// Define queue structure
typedef struct {
    Process *queue[MAX_PROCESSES];
    int front;
    int rear;
} Queue;

Queue *create_queue() {
    Queue *new_queue = (Queue *) malloc(sizeof(Queue));
    new_queue->front = -1;
    new_queue->rear = -1;
    return new_queue;
}

void enqueue(Queue *queue, Process *process) {
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->queue[queue->rear] = process;
}

Process *dequeue(Queue *queue) {
    Process *process = queue->queue[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return process;
}

int is_queue_empty(Queue *queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

int time_difference(struct timespec start, struct timespec end) {
    int seconds = end.tv_sec - start.tv_sec;
    int nanoseconds = end.tv_nsec - start.tv_nsec;
    return seconds * 1000 + nanoseconds / 1000000;
}

void print_process(Process *process) {
    printf("PID:%d Arrival Time:%d Burst Time:%d\n", process->pid, process->arrival_time, process->burst_time);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of processes
    Process processes[MAX_PROCESSES];
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = rand() % MAX_TIME;
        processes[i].burst_time = rand() % 15 + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Create a ready queue and add all the processes to it
    Queue *ready_queue = create_queue();
    for (int i = 0; i < MAX_PROCESSES; i++) {
        enqueue(ready_queue, &processes[i]);
    }

    // Simulate the CPU scheduling algorithm
    int current_time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    while (!is_queue_empty(ready_queue) && current_time < MAX_TIME) {
        Process *current_process = dequeue(ready_queue);
        if (current_process->remaining_time > QUANTUM) {
            // Process still has time remaining after this quantum
            current_process->remaining_time -= QUANTUM;
            current_time += QUANTUM;

            // Add process back to the queue
            enqueue(ready_queue, current_process);
        } else {
            // Process finishes
            current_time += current_process->remaining_time;
            waiting_time += current_time - current_process->arrival_time - current_process->burst_time;
            turnaround_time += current_time - current_process->arrival_time;
        }
    }

    // Calculate average waiting and turnaround time
    float avg_waiting_time = (float) waiting_time / MAX_PROCESSES;
    float avg_turnaround_time = (float) turnaround_time / MAX_PROCESSES;

    // Print results
    printf("Post-Apocalyptic CPU Scheduling Algorithm Results:\n");
    printf("Average Waiting Time: %.2f ms\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f ms\n", avg_turnaround_time);

    return 0;
}