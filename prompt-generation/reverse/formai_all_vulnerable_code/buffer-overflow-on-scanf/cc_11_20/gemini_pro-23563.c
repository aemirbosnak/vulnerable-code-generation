//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
};

int main() {
    int n, i, j;
    struct process p[MAX_SIZE];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time, burst time and priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }

    // Sort the processes according to their arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Initialize the time quantum
    int time_quantum = 1;
    float avg_waiting_time = 0.0;
    float avg_turnaround_time = 0.0;

    // Create a queue to store the processes that are ready to run
    struct queue {
        int front, rear;
        int size;
        struct process *array;
    };

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    q->size = MAX_SIZE;
    q->array = (struct process *)malloc(q->size * sizeof(struct process));

    // Run the processes using the round robin algorithm
    int current_time = 0;
    while (q->front != -1 || q->rear != -1) {
        if (q->front == -1) {
            q->front = q->rear = 0;
            q->array[q->rear] = p[current_time];
            current_time++;
        } else {
            struct process *process = &q->array[q->front];
            q->front++;
            if (process->remaining_time <= time_quantum) {
                current_time += process->remaining_time;
                process->remaining_time = 0;
                avg_waiting_time += current_time - process->arrival_time - process->burst_time;
                avg_turnaround_time += current_time - process->arrival_time;
            } else {
                process->remaining_time -= time_quantum;
                current_time += time_quantum;
                q->rear++;
                q->array[q->rear] = *process;
            }
        }

        // Check if all the processes have been completed
        int completed = 1;
        for (i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                completed = 0;
                break;
            }
        }

        if (completed) {
            break;
        }
    }

    // Calculate the average waiting time and average turnaround time
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print the results
    printf("The average waiting time is: %.2f\n", avg_waiting_time);
    printf("The average turnaround time is: %.2f\n", avg_turnaround_time);

    return 0;
}