//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Defining structure for a process
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
};

// Function to sort processes by arrival time
void sort_by_arrival_time(struct Process *processes, int num_processes) {
    int i, j;
    struct Process temp;
    for (i = 0; i < num_processes - 1; i++) {
        for (j = 0; j < num_processes - 1 - i; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

// Function to sort processes by priority
void sort_by_priority(struct Process *processes, int num_processes) {
    int i, j;
    struct Process temp;
    for (i = 0; i < num_processes - 1; i++) {
        for (j = 0; j < num_processes - 1 - i; j++) {
            if (processes[j].priority > processes[j+1].priority) {
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time for each process
void calculate_waiting_and_turnaround_time(struct Process *processes, int num_processes, int *waiting_time, int *turnaround_time) {
    int i;
    waiting_time[0] = 0;
    for (i = 1; i < num_processes; i++) {
        waiting_time[i] = waiting_time[i-1] + processes[i-1].burst_time;
    }
    for (i = 0; i < num_processes; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
}

// Function to calculate average waiting time and average turnaround time for all processes
void calculate_average_time(struct Process *processes, int num_processes) {
    int waiting_time[num_processes], turnaround_time[num_processes];
    int total_waiting_time = 0, total_turnaround_time = 0, i;
    calculate_waiting_and_turnaround_time(processes, num_processes, waiting_time, turnaround_time);
    for (i = 0; i < num_processes; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Average Waiting Time = %f\n", (float)total_waiting_time / (float)num_processes);
    printf("Average Turnaround Time = %f\n", (float)total_turnaround_time / (float)num_processes);
}

// First Come First Serve (FCFS) scheduling algorithm
void fcfs(struct Process *processes, int num_processes) {
    int i, waiting_time[num_processes], turnaround_time[num_processes];
    calculate_waiting_and_turnaround_time(processes, num_processes, waiting_time, turnaround_time);
    printf("FCFS Scheduling Algorithm\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    calculate_average_time(processes, num_processes);
}

// Shortest Job First (SJF) scheduling algorithm
void sjf(struct Process *processes, int num_processes) {
    int i, j, waiting_time[num_processes], turnaround_time[num_processes];
    sort_by_arrival_time(processes, num_processes);
    for (i = 0; i < num_processes; i++) {
        int min_burst_time = processes[i].burst_time;
        int min_burst_time_index = i;
        for (j = i; j < num_processes; j++) {
            if (processes[j].arrival_time <= processes[i].burst_time) {
                if (processes[j].burst_time < min_burst_time) {
                    min_burst_time = processes[j].burst_time;
                    min_burst_time_index = j;
                }
            }
            else {
                break;
            }
        }
        struct Process temp = processes[i];
        processes[i] = processes[min_burst_time_index];
        processes[min_burst_time_index] = temp;
    }
    calculate_waiting_and_turnaround_time(processes, num_processes, waiting_time, turnaround_time);
    printf("Shortest Job First (SJF) Scheduling Algorithm\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    calculate_average_time(processes, num_processes);
}

// Priority scheduling algorithm
void priority(struct Process *processes, int num_processes) {
    int i, waiting_time[num_processes], turnaround_time[num_processes];
    sort_by_priority(processes, num_processes);
    calculate_waiting_and_turnaround_time(processes, num_processes, waiting_time, turnaround_time);
    printf("Priority Scheduling Algorithm\n");
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
    }
    calculate_average_time(processes, num_processes);
}

int main() {
    int num_processes, i;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct Process *processes = (struct Process*)malloc(num_processes * sizeof(struct Process));
    for (i = 0; i < num_processes; i++) {
        printf("Enter process %d details:\n", i+1);
        printf("Process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }
    printf("\n");
    fcfs(processes, num_processes);
    printf("\n");
    sjf(processes, num_processes);
    printf("\n");
    priority(processes, num_processes);
    free(processes);
    return 0;
}