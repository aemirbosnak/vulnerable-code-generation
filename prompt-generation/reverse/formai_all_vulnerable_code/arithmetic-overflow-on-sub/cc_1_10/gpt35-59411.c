//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// structure to represent a process
struct process {
    int pid;  // process ID
    int arrival_time;  // arrival time of the process
    int burst_time;  // burst time of the process
    int remaining_time;  // remaining time of the process
    int completion_time;  // completion time of the process
    int turnaround_time;  // turnaround time of the process
    int waiting_time;  // waiting time of the process
};

// function to swap two processes
void swap(struct process *xp, struct process *yp) {
    struct process temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

// function to sort the processes based on their arrival time
void sort_by_arrival_time(struct process processes[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
            if (processes[j].arrival_time > processes[j+1].arrival_time) 
                swap(&processes[j], &processes[j+1]);
}

// function to find the waiting time of each process
void find_waiting_time(struct process processes[], int n) {
    int i, total_time = 0, sum = 0;
    for (i = 0; i < n; i++) {
        processes[i].waiting_time = total_time - processes[i].arrival_time;
        sum += processes[i].waiting_time;
        total_time += processes[i].burst_time;
    }
}

// function to find the completion time of each process
void find_completion_time(struct process processes[], int n) {
    int i, total_time = 0;
    for (i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        processes[i].completion_time = total_time;
    }
}

// function to find the turnaround time of each process
void find_turnaround_time(struct process processes[], int n) {
    int i;
    for (i = 0; i < n; i++) 
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
}

// function to calculate the average waiting time and average turnaround time of all processes
void calculate_avg_time(struct process processes[], int n, float *avg_waiting_time_ptr, float *avg_turnaround_time_ptr) {
    int i;
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    *avg_waiting_time_ptr = total_waiting_time/n;
    *avg_turnaround_time_ptr = total_turnaround_time/n;
}

// function to implement the Shortest Job First (SJF) scheduling algorithm
void sjf(struct process processes[], int n, float *avg_waiting_time_ptr, float *avg_turnaround_time_ptr) {
    int i, j, current_time = 0, total_time = 0, shortest_job_index;
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = -1;
    }
    while (total_time < n) {
        shortest_job_index = -1;
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest_job_index == -1 || processes[i].remaining_time < processes[shortest_job_index].remaining_time) {
                    shortest_job_index = i;
                }
            }
        }
        if (shortest_job_index == -1) {
            current_time++;
            continue;
        }
        processes[shortest_job_index].remaining_time--;
        current_time++;
        if (processes[shortest_job_index].remaining_time == 0) {
            total_time++;
            processes[shortest_job_index].completion_time = current_time;
        }
    }
    find_waiting_time(processes, n);
    find_turnaround_time(processes, n);
    calculate_avg_time(processes, n, &total_waiting_time, &total_turnaround_time);
    *avg_waiting_time_ptr = total_waiting_time;
    *avg_turnaround_time_ptr = total_turnaround_time;   
}

int main() {
    int i, n;
    float avg_waiting_time, avg_turnaround_time;
    struct process processes[100];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i+1;
    }
    sort_by_arrival_time(processes, n);
    sjf(processes, n, &avg_waiting_time, &avg_turnaround_time);
    printf("\nPID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
    }
    printf("\nAverage waiting time: %f\n", avg_waiting_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);
    return 0;
}