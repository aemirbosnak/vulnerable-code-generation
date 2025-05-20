//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void print_processes(struct Process p[], int n) {
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++) {
        printf("%d\t  %d\t\t    %d\t\t  %d\t\t    %d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
}

void average_time(struct Process p[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    for(int i=0; i<n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    float avg_wait_time = (float)total_waiting_time/(float)n;
    float avg_turnaround_time = (float)total_turnaround_time/(float)n;
    printf("Average Waiting Time: %0.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %0.2f\n", avg_turnaround_time);
}

void fcfs_scheduler(struct Process p[], int n) {
    int waiting_time = 0, turnaround_time = 0;
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;

    for(int i=1; i<n; i++) {
        waiting_time += p[i-1].burst_time;
        p[i].waiting_time = waiting_time;
        turnaround_time = waiting_time + p[i].burst_time;
        p[i].turnaround_time = turnaround_time;
    }

    print_processes(p, n);
    average_time(p, n);
}

void sjf_scheduler(struct Process p[], int n) {
    int waiting_time[n], turnaround_time[n], completion_time[n];
    int total_completion_time = 0, shortest, min_completion_time;
    float avg_wait_time, avg_turnaround_time;

    for(int i=0; i<n; i++) {
        completion_time[i] = 0;
        turnaround_time[i] = 0;
        waiting_time[i] = 0;
    }

    for(int i=0; i<n; i++) {
        min_completion_time = 9999;
        for(int j=0; j<n; j++) {
            if(p[j].arrival_time <= total_completion_time && completion_time[j] == 0) {
                if(p[j].burst_time < min_completion_time) {
                    min_completion_time = p[j].burst_time;
                    shortest = j;
                }
            }
        }
        completion_time[shortest] = total_completion_time + p[shortest].burst_time;
        total_completion_time += p[shortest].burst_time;
    }

    for(int i=0; i<n; i++) {
        turnaround_time[i] = completion_time[i] - p[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - p[i].burst_time;
    }

    for(int i=0; i<n; i++) {
        p[i].turnaround_time = turnaround_time[i];
        p[i].waiting_time = waiting_time[i];
    }

    print_processes(p, n);
    average_time(p, n);
}

int main() {
    int n, choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    printf("Enter burst time and arrival time for all processes:\n");
    for(int i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
        p[i].pid = i+1;
    }

    printf("Choose the CPU scheduling algorithm:\n1. FCFS\n2. SJF\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            fcfs_scheduler(p, n);
            break;
        case 2:
            sjf_scheduler(p, n);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}