//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process* process_list, int n) {
    int quantum = TIME_QUANTUM;
    int current_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        process_list[i].waiting_time = 0;
        process_list[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        int max_index = -1;
        int max_burst_time = 0;

        for (i = 0; i < n; i++) {
            if (process_list[i].burst_time > max_burst_time &&
                process_list[i].burst_time - process_list[i].waiting_time <= quantum) {
                max_index = i;
                max_burst_time = process_list[i].burst_time;
            }
        }

        if (max_index!= -1) {
            process_list[max_index].waiting_time += quantum;
            current_time += quantum;
            process_list[max_index].turnaround_time = current_time - process_list[max_index].waiting_time + process_list[max_index].burst_time;

            if (process_list[max_index].burst_time - process_list[max_index].waiting_time > quantum) {
                process_list[max_index].burst_time -= quantum;
            } else {
                completed_processes++;
            }
        } else {
            current_time += quantum;
        }
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process_list[i].id, process_list[i].burst_time, process_list[i].waiting_time, process_list[i].turnaround_time);
    }
}

int main() {
    struct process process_list[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (int i = 0; i < n; i++) {
        printf("Process ID %d:\n", i+1);
        printf("Enter burst time: ");
        scanf("%d", &process_list[i].burst_time);
    }

    execute_processes(process_list, n);

    return 0;
}