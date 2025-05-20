//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void sjf(struct process* proc, int n) {
    int curr_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (proc[i].burst_time <= curr_time) {
            curr_time += proc[i].burst_time;
            proc[i].turnaround_time = curr_time - proc[i].burst_time - proc[i].waiting_time;
            proc[i].waiting_time = curr_time - proc[i].burst_time;
            completed_processes++;
        } else {
            break;
        }
    }

    while (completed_processes < n) {
        int min_bt = INF;
        int min_index = -1;

        for (i = 0; i < n; i++) {
            if (proc[i].burst_time <= curr_time && proc[i].waiting_time < min_bt) {
                min_bt = proc[i].waiting_time;
                min_index = i;
            }
        }

        curr_time += min_bt;
        proc[min_index].turnaround_time = curr_time - proc[min_index].burst_time - proc[min_index].waiting_time;
        proc[min_index].waiting_time = curr_time - proc[min_index].burst_time;
        completed_processes++;
    }
}

void display(struct process* proc, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("PID: %d, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    int n;
    struct process proc[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);

    for (int i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter the process ID: ");
        scanf("%d", &proc[i].pid);
        printf("Enter the burst time: ");
        scanf("%d", &proc[i].burst_time);
    }

    sjf(proc, n);
    display(proc, n);

    return 0;
}