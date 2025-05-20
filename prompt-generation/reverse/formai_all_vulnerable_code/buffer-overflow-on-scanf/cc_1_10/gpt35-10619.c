//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid;        // process ID
    int burst_time; // burst time of process
    int arrival_time; // arrival time of process
    int completion_time; // completion time of process
    int waiting_time; // waiting time of process
    int turnaround_time; // turnaround time of process
};

// function to calculate completion, waiting, and turnaround time for each process
void calculate_times(struct process p[], int n) {
    int total_time = 0;
    for(int i=0; i<n; i++) {
        total_time += p[i].burst_time;
        p[i].completion_time = total_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

// function to print gantt chart for execution
void print_gantt_chart(struct process p[], int n) {
    int total_time = 0;
    printf("\nGantt Chart:\n\n");
    
    // print top line of gantt chart
    printf("|");
    for(int i=0; i<n; i++) {
        printf(" P%d ",p[i].pid);
        if(p[i].burst_time > 9) printf("|");
        else printf(" |");
    }
    printf("\n");
    
    // print bottom line of gantt chart
    printf("0");
    for(int i=0; i<n; i++) {
        if(p[i].burst_time > 9) printf(" %d ",p[i].completion_time);
        else printf(" %d  ",p[i].completion_time);
    }
    printf("\n");
}

// function to print table with process details and times
void print_table(struct process p[], int n) {
    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].burst_time,p[i].arrival_time,p[i].completion_time,p[i].waiting_time,p[i].turnaround_time);
    }
}

// function to perform FCFS scheduling algorithm
void fcfs(struct process p[], int n) {
    printf("\n--- First-Come-First-Served Scheduling Algorithm ---\n\n");
    calculate_times(p,n);
    print_gantt_chart(p,n);
    print_table(p,n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    struct process p[n];
    for(int i=0; i<n; i++) {
        printf("Enter the burst time for process %d: ",i+1);
        scanf("%d",&p[i].burst_time);
        p[i].pid = i+1;
        p[i].arrival_time = 0;
    }
    
    fcfs(p,n);
    
    return 0;
}