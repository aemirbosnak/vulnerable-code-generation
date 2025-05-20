//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, sum_wt = 0, sum_tat = 0, curr_time = 0, prev_complete = 0;
    int index = 0;

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time <= QUANTUM) {
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
            curr_time += processes[i].burst_time;
        } else {
            for (j = 0; j < i; j++) {
                if (processes[j].burst_time > QUANTUM && processes[j].waiting_time + processes[j].turnaround_time > processes[i].waiting_time + processes[i].turnaround_time) {
                    index = j;
                }
            }

            processes[i].waiting_time = curr_time - processes[i].burst_time + processes[index].waiting_time + processes[index].turnaround_time;
            curr_time += processes[i].burst_time;
            sum_wt += processes[i].waiting_time;
            sum_tat += processes[i].turnaround_time;
            prev_complete = curr_time;
        }
    }

    printf("\nAverage waiting time: %.2f", (float) sum_wt / n);
    printf("\nAverage turnaround time: %.2f", (float) sum_tat / n);
}

int main() {
    struct process processes[MAX];
    int n, i, sum_bt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the details of %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        sum_bt += processes[i].burst_time;
    }

    execute_processes(processes, n);

    return 0;
}