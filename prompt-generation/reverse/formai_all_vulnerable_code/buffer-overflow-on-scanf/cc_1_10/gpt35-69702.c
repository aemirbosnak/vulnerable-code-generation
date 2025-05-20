//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void rr_schedule(Process *processes, int n, int tq) {
    int q[MAX_PROCESSES];
    int front = 0, rear = -1;
    int time = 0;

    // sort processes by arrival time
    sort(processes, n);

    // loop until all processes are completed
    while (1) {
        // add arrived processes to queue
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                rear++;
                q[rear] = i;
            }
        }

        // if queue is empty, break the loop
        if (front > rear) {
            break;
        }

        // get the next process from queue
        int curr = q[front];
        front++;

        // execute the process for the time quantum
        if (processes[curr].remaining_time <= tq) {
            time += processes[curr].remaining_time;
            processes[curr].remaining_time = 0;
            printf("Process %d executed from %d to %d\n", processes[curr].id, time - processes[curr].burst_time, time);
        }
        else {
            time += tq;
            processes[curr].remaining_time -= tq;
            printf("Process %d executed from %d to %d\n", processes[curr].id, time - tq, time);

            // add the process back to queue
            rear++;
            q[rear] = curr;
        }
    }
}

int main() {
    int n; // number of processes
    int tq; // time quantum
    Process processes[MAX_PROCESSES]; // array of processes

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // read process details
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    rr_schedule(processes, n, tq);

    return 0;
}