//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define DELTA 0.001

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int process) {
    if ((rear + 1) % MAX == front) {
        printf("\nQueue is Full!!");
        exit(0);
    }
    else if (front == -1) {
        front = 0;
        rear = 0;
        queue[rear] = process;
    }
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = process;
    }
}

int dequeue() {
    int process;
    if (front == -1) {
        printf("\nQueue is Empty!!");
        exit(0);
    }
    else if (front == rear) {
        process = queue[front];
        front = -1;
        rear = -1;
    }
    else {
        process = queue[front];
        front = (front + 1) % MAX;
    }
    return process;
}

void execute(int quantum) {
    int time_slice = quantum / (double)DELTA;
    int time_left = quantum;
    while (time_left > 0) {
        int i;
        for (i = front; i <= rear; i++) {
            if (queue[i] <= time_slice) {
                printf("\nProcess %d executed", queue[i]);
                dequeue();
                time_left -= queue[i];
            }
            else {
                queue[i] -= time_slice;
                printf("\nProcess %d partially executed", queue[i]);
            }
        }
        printf("\nTime Slice Expired");
        enqueue(time_slice);
        time_left -= time_slice;
    }
}

int main() {
    int i, n, quantum;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);
    printf("\nEnter %d processes with their burst times:\n", n);
    for (i = 0; i < n; i++) {
        int burst_time;
        scanf("%d", &burst_time);
        enqueue(burst_time);
    }
    execute(quantum);
    return 0;
}