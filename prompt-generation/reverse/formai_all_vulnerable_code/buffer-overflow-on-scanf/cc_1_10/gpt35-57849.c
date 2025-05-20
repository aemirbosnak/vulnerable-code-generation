//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include <stdio.h>

// structure to represent a process
struct process {
    int pid;     // process id
    int burst_time;   // burst time
    int arrival_time; // arrival time
    int waiting_time;  // waiting time
    int turnaround_time; // turnaround time
};

// function to sort an array of processes based on their arrival time
void sort_by_arrival_time(struct process *processes, int n) {
    int i, j;
    struct process temp;

    for(i = 0; i < n; ++i) {
        for(j = i+1; j < n; ++j) {
            if(processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// function to implement FCFS scheduling algorithm
void fcfs(struct process *processes, int n) {
    int total_time = 0;
    float average_wait_time = 0, average_turnaround_time = 0;

    printf("\nFCFS Scheduling\n\n");

    for(int i = 0; i < n; ++i) {
        if(total_time < processes[i].arrival_time) {
            total_time = processes[i].arrival_time;
        }

        total_time += processes[i].burst_time;
        processes[i].turnaround_time = total_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        average_wait_time += processes[i].waiting_time;
        average_turnaround_time += processes[i].turnaround_time;

        printf("Process[%d]\tBurst Time = %d\tArrival Time = %d\tWaiting Time = %d\tTurnaround Time = %d\n", 
                processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    average_wait_time /= n;
    average_turnaround_time /= n;

    printf("\nAverage Waiting Time = %.2f\n", average_wait_time);
    printf("Average Turnaround Time = %.2f\n", average_turnaround_time);
}

// function to implement Round Robin scheduling algorithm
void round_robin(struct process *processes, int n, int quantum) {
    int total_time = 0;
    int completed_process_count = 0;
    float average_wait_time = 0, average_turnaround_time = 0;

    printf("\nRound Robin Scheduling (Quantum = %d)\n\n", quantum);

    while(completed_process_count < n) {
        for(int i = 0; i < n; ++i) {
            if(processes[i].burst_time == 0) {
                continue;
            }

            if(processes[i].arrival_time <= total_time) {
                int remaining_time = processes[i].burst_time;
                if(remaining_time > quantum) {
                    processes[i].burst_time -= quantum;
                    total_time += quantum;
                    remaining_time -= quantum;
                } else {
                    total_time += remaining_time;
                    processes[i].burst_time = 0;
                    remaining_time = 0;
                    completed_process_count++;
                }

                for(int j = 0; j < n; ++j) {
                    if(j != i && processes[j].burst_time > 0 && processes[j].arrival_time <= total_time) {
                        processes[j].waiting_time += remaining_time;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        average_wait_time += processes[i].waiting_time;
        average_turnaround_time += processes[i].turnaround_time;

        printf("Process[%d]\tBurst Time = %d\tArrival Time = %d\tWaiting Time = %d\tTurnaround Time = %d\n", 
                processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    average_wait_time /= n;
    average_turnaround_time /= n;

    printf("\nAverage Waiting Time = %.2f\n", average_wait_time);
    printf("Average Turnaround Time = %.2f\n", average_turnaround_time);
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for(int i = 0; i < n; ++i) {
        printf("\nEnter the process id for process %d: ", i+1);
        scanf("%d", &processes[i].pid);

        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);

        printf("Enter the arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
    }

    sort_by_arrival_time(processes, n);

    printf("\nInput Values\n\n");
    printf("Process\tBurst Time\tArrival Time\n");
    for(int i = 0; i < n; ++i) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time);
    }

    printf("\nSelect the scheduling algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Round Robin (RR)\n");

    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            printf("\nEnter the quantum for Round Robin (RR) scheduling algorithm: ");
            scanf("%d", &quantum);
            round_robin(processes, n, quantum);
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }

    return 0;
}