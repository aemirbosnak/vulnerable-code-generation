//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;       // Priority can be from 1 to 10
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void swap(struct process *a, struct process *b) {
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(struct process p[], int n) {
    int i, j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(p[j].priority > p[j+1].priority) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

void calculate_completion_time(struct process p[], int n) {
    int i;
    p[0].completion_time = p[0].burst_time + p[0].arrival_time;
    for(i=1; i<n; i++) {
        if(p[i].arrival_time > p[i-1].completion_time) {
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
        }
        else {
            p[i].completion_time = p[i-1].completion_time + p[i].burst_time;
        }
    }
}

void calculate_turnaround_time(struct process p[], int n) {
    int i;
    for(i=0; i<n; i++) {
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
    }
}

void calculate_waiting_time(struct process p[], int n) {
    int i;
    for(i=0; i<n; i++) {
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

void display(struct process p[], int n) {
    int i;
    printf("PID\tBurst Time\tArrival Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].priority, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
    printf("\n");
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for(i=0; i<n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i+1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        printf("Enter the priority of process %d (1 to 10): ", i+1);
        scanf("%d", &p[i].priority);
        p[i].pid = i+1;
    }

    bubble_sort(p, n);  // Sort the processes based on their priority
    calculate_completion_time(p, n);    // Calculate completion time of each process
    calculate_turnaround_time(p, n);    // Calculate turnaround time of each process
    calculate_waiting_time(p, n);       // Calculate waiting time of each process

    display(p, n);  // Display the table of processes with their details

    return 0;
}