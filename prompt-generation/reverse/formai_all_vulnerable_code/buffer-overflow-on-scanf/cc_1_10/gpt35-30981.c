//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
};

void fcfs(struct process p[], int n)
{
    printf("\nFCFS scheduling algorithm\n");
    printf("PID \t AT \t BT \t CT \t TAT \t WT\n");

    int completion_time = 0;
    int turnaround_time;
    int waiting_time;

    for(int i=0; i<n; i++) {
        completion_time += p[i].burst_time;
        turnaround_time = completion_time - p[i].arrival_time;
        waiting_time = turnaround_time - p[i].burst_time;

        printf("%d \t %d \t %d \t %d \t %d \t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, completion_time, turnaround_time, waiting_time);
    }
}

void sjf(struct process p[], int n)
{
    printf("\nSJF scheduling algorithm\n");
    printf("PID \t AT \t BT \t CT \t TAT \t WT\n");

    int completion_time = 0;
    int turnaround_time;
    int waiting_time;

    for(int i=0; i<n; i++) {
        int shortest_time = p[i].burst_time;
        int shortest_index = i;

        for(int j=i+1; j<n; j++) {
            if(p[j].arrival_time <= completion_time && p[j].burst_time < shortest_time) {
                shortest_time = p[j].burst_time;
                shortest_index = j;
            }
        }

        struct process temp = p[i];
        p[i] = p[shortest_index];
        p[shortest_index] = temp;

        completion_time += p[i].burst_time;
        turnaround_time = completion_time - p[i].arrival_time;
        waiting_time = turnaround_time - p[i].burst_time;

        printf("%d \t %d \t %d \t %d \t %d \t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, completion_time, turnaround_time, waiting_time);
    }
}

void round_robin(struct process p[], int n, int quantum)
{
    printf("\nRound Robin scheduling algorithm\n");
    printf("PID \t AT \t BT \t CT \t TAT \t WT\n");

    int completion_time = 0;
    int remaining_time[n];
    int turnaround_time;
    int waiting_time;

    for(int i=0; i<n; i++) {
        remaining_time[i] = p[i].burst_time;
    }

    while(1) {
        int done = 1;

        for(int i=0; i<n; i++) {
            if(remaining_time[i] > 0) {
                done = 0;

                if(remaining_time[i] <= quantum) {
                    completion_time += remaining_time[i];
                    turnaround_time = completion_time - p[i].arrival_time;
                    waiting_time = turnaround_time - p[i].burst_time;
                    remaining_time[i] = 0;

                    printf("%d \t %d \t %d \t %d \t %d \t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, completion_time, turnaround_time, waiting_time);
                } else {
                    completion_time += quantum;
                    remaining_time[i] -= quantum;

                    printf("%d \t %d \t %d \t %d \t %d \t %d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, completion_time, (-1), (-1));
                }
            }
        }

        if(done == 1) {
            break;
        }
    }
}

int main()
{
    int n, choice, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(int i=0; i<n; i++) {
        printf("Enter Arrival time and Burst time for process %d: ", i);
        scanf("%d", &p[i].arrival_time);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i;
    }

    printf("\nSelect a scheduling algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin with fixed time quantum\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            fcfs(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        case 3:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            round_robin(p, n, quantum);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}