//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include<stdio.h>

struct Process {
    int pid; // process id
    int arrival_time; // arrival time
    int burst_time; // burst time
    int priority; // priority
    int completion_time; // completion time
    int turnaround_time; // turnaround time
    int waiting_time; // waiting time
};

// function to sort the processes based on arrival time
void sort_processes_by_arrival_time(struct Process *processes, int n) {
    int i, j;
    struct Process temp;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// function to print the process details
void print_process(struct Process process) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process.pid, process.arrival_time, process.burst_time, process.priority, process.completion_time, process.turnaround_time, process.waiting_time);
}

// function to calculate completion time, turnaround time and waiting time
void calculate_times(struct Process *processes, int n) {
    int i;
    int time = processes[0].arrival_time;
    for(i=0; i<n; i++) {
        // completion time
        if(i==0) {
            processes[i].completion_time = processes[i].arrival_time + processes[i].burst_time;
        } else {
            processes[i].completion_time = processes[i-1].completion_time + processes[i].burst_time;
        }
        // turnaround time
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        // waiting time
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

// function to calculate average turnaround time and waiting time
void calculate_average_times(struct Process *processes, int n, float *avg_tat, float *avg_wt) {
    int i;
    *avg_tat = 0;
    *avg_wt = 0;
    for(i=0; i<n; i++) {
        *avg_tat += processes[i].turnaround_time;
        *avg_wt += processes[i].waiting_time;
    }
    *avg_tat /= n;
    *avg_wt /= n;
}

// function to implement the Priority scheduling algorithm
void priority_scheduling(struct Process *processes, int n) {
    sort_processes_by_arrival_time(processes, n);
    int i, j;
    struct Process temp;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            // sort the processes with same arrival time based on priority
            if(processes[i].arrival_time == processes[j].arrival_time && processes[i].priority > processes[j].priority) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
            // execute the process with highest priority
            if(processes[i].completion_time < processes[j].arrival_time) {
                processes[i].burst_time -= processes[j].arrival_time - processes[i].completion_time;
                processes[i].completion_time = processes[j].arrival_time;
            }
        }
        // calculate the completion time, turnaround time and waiting time for each process after execution
        processes[i].completion_time += processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

int main() {
    int i, n;
    float avg_tat, avg_wt;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    // get the process details from the user
    for(i=0; i<n; i++) {
        printf("Enter the details for process %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }
    // calculate the completion time, turnaround time and waiting time using Priority scheduling algorithm
    priority_scheduling(processes, n);
    // print the process details with completion time, turnaround time and waiting time
    printf("PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i=0; i<n; i++) {
        print_process(processes[i]);
    }
    // calculate the average turnaround time and waiting time
    calculate_average_times(processes, n, &avg_tat, &avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);
    printf("Average waiting time: %.2f\n", avg_wt);
    return 0;
}