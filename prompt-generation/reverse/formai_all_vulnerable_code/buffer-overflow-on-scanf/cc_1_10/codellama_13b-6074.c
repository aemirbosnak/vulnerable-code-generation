//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
// CPU Scheduling Algorithm: First-Come-First-Served (FCFS)

#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void print_processes(struct process processes[], int n) {
    printf("Processes: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i].pid);
    }
    printf("\n");
}

void print_results(struct process processes[], int n) {
    printf("Completion Times: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i].completion_time);
    }
    printf("\n");

    printf("Turnaround Times: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i].turnaround_time);
    }
    printf("\n");

    printf("Waiting Times: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i].waiting_time);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        int min_index = 0;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time > processes[min_index].burst_time) {
                min_index = i;
            }
        }

        current_time += processes[min_index].burst_time;
        processes[min_index].completion_time = current_time;
        processes[min_index].turnaround_time = processes[min_index].completion_time - processes[min_index].arrival_time;
        processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;

        completed_processes++;
    }

    print_processes(processes, n);
    print_results(processes, n);

    return 0;
}