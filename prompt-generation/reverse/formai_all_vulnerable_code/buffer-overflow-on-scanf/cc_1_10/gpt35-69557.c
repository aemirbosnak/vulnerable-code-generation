//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include<stdio.h>

struct Process {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void SJF(struct Process p[], int n) {
    int i, j;
    struct Process temp;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].burst_time > p[j].burst_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int total_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    for(i=0; i<n; i++) {
        total_time += p[i].burst_time;
        p[i].completion_time = total_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }

    avg_waiting_time = avg_waiting_time/n;
    avg_turnaround_time = avg_turnaround_time/n;
    printf("\nSJF CPU Scheduling Algorithm\n");
    printf("| Process ID | Burst Time | Waiting Time | Turn Around Time | Completion Time |\n");
    for(i=0; i<n; i++) {
        printf("| %10d | %10d | %12d | %16d | %15d |\n",
               p[i].process_id, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].completion_time);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n\n", avg_turnaround_time);
}

void RoundRobin(struct Process p[], int n, int quantum) {
    int i, j, total_time = 0, total_burst_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int remaining_time[n];
    for(i=0; i<n; i++) {
        remaining_time[i] = p[i].burst_time;
        total_burst_time += p[i].burst_time;
    }
    while(total_time != total_burst_time) {
        for(i=0; i<n; i++) {
            if(remaining_time[i] > 0) {
                if(remaining_time[i] > quantum) {
                    total_time += quantum;
                    remaining_time[i] -= quantum;
                }
                else {
                    total_time += remaining_time[i];
                    p[i].completion_time = total_time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    avg_waiting_time += p[i].waiting_time;
                    avg_turnaround_time += p[i].turnaround_time;
                    remaining_time[i] = 0;
                }
            }
        }
    }
    avg_waiting_time = avg_waiting_time/n;
    avg_turnaround_time = avg_turnaround_time/n;
    printf("\nRound Robin CPU Scheduling Algorithm with Quantum %d\n", quantum);
    printf("| Process ID | Burst Time | Waiting Time | Turn Around Time | Completion Time |\n");
    for(i=0; i<n; i++) {
        printf("| %10d | %10d | %12d | %16d | %15d |\n",
               p[i].process_id, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].completion_time);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n\n", avg_turnaround_time);
}

int main() {
    int n, i, j, choice, quantum;
    struct Process p[50];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Enter the details of process %d\n", i+1);
        p[i].process_id = i+1;
        printf("Enter the burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].arrival_time);
    }
    printf("Select the CPU Scheduling Algorithm\n");
    printf("1. SJF\n2. Round Robin\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: SJF(p, n);
                break;
        case 2: printf("Enter the quantum for Round Robin: ");
                scanf("%d", &quantum);
                RoundRobin(p, n, quantum);
                break;
        default: printf("Invalid Choice\n");
                 break;
    }
    return 0;
}