//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX 100
#define INF INT_MAX

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void swap(struct process* a, struct process* b) {
    int temp = a->pid;
    a->pid = b->pid;
    b->pid = temp;
}

int compare(const void* a, const void* b) {
    struct process* p1 = (struct process*)a;
    struct process* p2 = (struct process*)b;

    if(p1->burst_time > p2->burst_time) {
        return 1;
    } else if(p1->burst_time < p2->burst_time) {
        return -1;
    } else {
        return 0;
    }
}

void sort(struct process arr[], int n) {
    qsort(arr, n, sizeof(struct process), compare);
}

void execute(struct process arr[], int n, int quantum) {
    int i, j, sum = 0, count = 0, temp = 0;
    int index = 0;

    for(i = 0; i < n; i++) {
        if(arr[i].burst_time <= quantum) {
            arr[i].turnaround_time = arr[i].waiting_time + arr[i].burst_time;
            arr[i].waiting_time = 0;
            sum += arr[i].burst_time;
            count++;
        } else {
            temp = quantum - arr[i].burst_time;
            arr[i].turnaround_time = arr[i].waiting_time + temp * (n - count);
            arr[i].waiting_time += temp;
            sum += temp;
        }
    }

    for(i = 0; i < n; i++) {
        printf("\nProcess %d executed for %d time units.\n", arr[i].pid, arr[i].burst_time);
    }

    printf("\nAverage waiting time: %.2f\n", (float)sum / n);
}

void main() {
    int n, i, quantum, sum = 0;
    struct process arr[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i].burst_time);
        sum += arr[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    sort(arr, n);

    execute(arr, n, quantum);
}