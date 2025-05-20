//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int remaining_time;
};

int is_all_done(struct process* processes, int n) {
    for (int i = 0; i < n; i++) {
        if (processes[i].remaining_time > 0) {
            return 0;
        }
    }
    return 1;
}

void run_fcfs(struct process* processes, int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;

        current_time += processes[i].burst_time;
        
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

void run_sjf(struct process* processes, int n) {
    int current_time = 0;
    int done_count = 0;

    while (!is_all_done(processes, n)) {
        int next_process_index = -1;
        int shortest_burst_time = 99999999;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                if (processes[i].burst_time < shortest_burst_time) {
                    shortest_burst_time = processes[i].burst_time;
                    next_process_index = i;
                }
            }
        }

        if (next_process_index != -1) {
            struct process* next_process = &processes[next_process_index];
            next_process->waiting_time = current_time - next_process->arrival_time;
            current_time += next_process->burst_time;
            next_process->remaining_time = 0;
            next_process->completion_time = current_time;
            next_process->turnaround_time = next_process->completion_time - next_process->arrival_time;
            done_count++;
        } else {
            current_time++;
        }
    }
}

void print_table(struct process* processes, int n) {
    printf("ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float average_waiting_time = 0;
    float average_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
            processes[i].id, processes[i].arrival_time, processes[i].burst_time,
            processes[i].waiting_time, processes[i].turnaround_time);
        
        average_waiting_time += processes[i].waiting_time;
        average_turnaround_time += processes[i].turnaround_time;
    }

    average_waiting_time /= n;
    average_turnaround_time /= n;

    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process* processes = (struct process*) malloc(sizeof(struct process) * n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i;
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    run_fcfs(processes, n);
    printf("First come, first served (FCFS):\n");
    print_table(processes, n);
    printf("\n");

    run_sjf(processes, n);
    printf("Shortest Job First (SJF):\n");
    print_table(processes, n);

    return 0;
}