//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define QANTUM 2

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void swap(Process *a, Process *b) {
    int temp = a->burst_time;
    a->burst_time = b->burst_time;
    b->burst_time = temp;
}

void sort(Process process[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (process[j].burst_time > process[j + 1].burst_time) {
                swap(&process[j], &process[j + 1]);
            }
        }
    }
}

void roundRobinScheduling(Process process[], int n) {
    int i = 0, time = 0;
    for (; i < n; i++) {
        if (process[i].burst_time > 0) {
            if (process[i].burst_time <= QANTUM) {
                time += process[i].burst_time;
                process[i].burst_time = 0;
                process[i].waiting_time = time - process[i].pid;
                process[i].turnaround_time = time + process[i].burst_time;
            } else {
                process[i].burst_time -= QANTUM;
                time += QANTUM;
            }
        }
    }
}

int main() {
    Process process[MAX_PROCESS];
    int i, n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i].burst_time);
        process[i].pid = i + 1;
    }
    sort(process, n);
    roundRobinScheduling(process, n);
    printf("\nProcess\t\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", process[i].pid, process[i].waiting_time, process[i].turnaround_time);
    }
    return 0;
}