//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int completion_time;
};

void FCFS(struct Process process_table[], int n) {
    int current_time = 0;
    for(int i=0; i<n; i++) {
        if(current_time < process_table[i].arrival_time)
            current_time = process_table[i].arrival_time;
        process_table[i].completion_time = current_time + process_table[i].burst_time;
        current_time = process_table[i].completion_time;
        process_table[i].turnaround_time = process_table[i].completion_time - process_table[i].arrival_time;
        process_table[i].waiting_time = process_table[i].turnaround_time - process_table[i].burst_time;
    }
}

void SJF(struct Process process_table[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    while(completed_processes < n) {
        int shortest_burst_time = -1;
        int shortest_process_index = -1;
        for(int i=0; i<n; i++) {
            if(process_table[i].burst_time > 0 && process_table[i].arrival_time <= current_time) {
                if(shortest_burst_time == -1 || process_table[i].burst_time < shortest_burst_time) {
                    shortest_burst_time = process_table[i].burst_time;
                    shortest_process_index = i;
                }
            }
        }
        if(shortest_process_index == -1) {
            current_time++;
            continue;
        }
        process_table[shortest_process_index].completion_time = current_time + process_table[shortest_process_index].burst_time;
        current_time = process_table[shortest_process_index].completion_time;
        process_table[shortest_process_index].turnaround_time = process_table[shortest_process_index].completion_time - process_table[shortest_process_index].arrival_time;
        process_table[shortest_process_index].waiting_time = process_table[shortest_process_index].turnaround_time - process_table[shortest_process_index].burst_time;
        process_table[shortest_process_index].burst_time = 0;
        completed_processes++;
    }
}

int main() {

    printf("Enter the number of processes: ");
    int n;
    scanf("%d", &n);

    struct Process process_table[n];

    printf("Enter arrival and burst time for each process:\n");
    for(int i=0; i<n; i++) {
        process_table[i].process_id = i+1;
        printf("P%d: ", process_table[i].process_id);
        scanf("%d%d", &process_table[i].arrival_time, &process_table[i].burst_time);
    }

    printf("\nFCFS Scheduling:\n");
    FCFS(process_table, n);

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", process_table[i].process_id, process_table[i].arrival_time, process_table[i].burst_time, process_table[i].completion_time, process_table[i].turnaround_time, process_table[i].waiting_time);
    }

    printf("\n\nSJF Scheduling:\n");
    SJF(process_table, n);

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", process_table[i].process_id, process_table[i].arrival_time, process_table[i].burst_time, process_table[i].completion_time, process_table[i].turnaround_time, process_table[i].waiting_time);
    }

    return 0;
}