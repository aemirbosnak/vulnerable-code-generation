//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TIME_QUANTUM 2

int queue[MAX];
int front = -1, rear = -1;
int nprocesses, i, j, temp, count = 0;
int waitingtime[MAX], turnaroundtime[MAX];
float avgwaitingtime, avgturnaroundtime;

void enqueue(int value) {
    if ((rear == MAX - 1) || (front == 0 && rear!= -1)) {
        printf("\nQueue is full!!");
        exit(0);
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    if (front == -1)
        front = 0;
}

int dequeue() {
    int value;

    if (front == -1 || front > rear) {
        printf("\nQueue is empty!!");
        exit(0);
    }

    value = queue[front];
    if (front == rear)
        rear = front = -1;
    else
        front++;

    return value;
}

void execute(int value) {
    int timeSlice;

    printf("\nProcess %d is being executed", value);
    timeSlice = TIME_QUANTUM;
    while (timeSlice > 0) {
        printf("\n");
        fflush(stdout);
        timeSlice--;
        count++;
    }
    printf("\n");
}

int main() {
    int choice, value;

    printf("\nEnter the number of processes: ");
    scanf("%d", &nprocesses);

    for (i = 0; i < nprocesses; i++) {
        printf("\nEnter the burst time of process %d: ", i + 1);
        scanf("%d", &value);
        enqueue(value);
    }

    printf("\nGantt chart:\n");
    system("clear");
    for (i = 0; i < nprocesses; i++) {
        value = dequeue();
        execute(value);
        waitingtime[i] = turnaroundtime[i] - value;
        turnaroundtime[i] += waitingtime[i];
        printf("\nProcess %d completed, waiting time: %d, turnaround time: %d", i + 1, waitingtime[i], turnaroundtime[i]);
    }

    avgwaitingtime = (float) count / nprocesses;
    avgturnaroundtime = (float) count / nprocesses;

    printf("\n\nAverage waiting time: %.2f", avgwaitingtime);
    printf("\nAverage turnaround time: %.2f", avgturnaroundtime);

    return 0;
}