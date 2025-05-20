//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid, burst_time, arrival_time, priority;
    int waiting_time, turnaround_time, remaining_time;
    int completion_time, marked;
};

int now = 0;
int total_burst_time = 0;

//compare two processes based on arrival time
int compare_arrival_time(const void* a, const void* b){
    struct process* p1 = (struct process*)a;
    struct process* p2 = (struct process*)b;
    return p1->arrival_time - p2->arrival_time;
}

//compare two processes based on priority
int compare_priority(const void* a, const void* b){
    struct process* p1 = (struct process*)a;
    struct process* p2 = (struct process*)b;
    return p1->priority - p2->priority;
}

//function to get the process with the highest priority
int get_highest_priority(struct process* processes, int n){
    int idx = -1, max_priority = -1;
    for(int i=0; i<n; i++){
        if(processes[i].marked) continue;
        if(processes[i].arrival_time > now) continue;
        if(processes[i].priority > max_priority){
            max_priority = processes[i].priority;
            idx = i;
        }
    }
    return idx;
}

//function to calculate the waiting time and turnaround time for each process
void calculate_times(struct process* processes, int n){
    for(int i=0; i<n; i++){
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

//function to print the details of each process
void print_details(struct process* processes, int n){
    printf("PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, 
               processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time,
               processes[i].waiting_time);
    }
}

//main function
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process* processes = (struct process*)malloc(n*sizeof(struct process));
    printf("Enter the arrival time, burst time, and priority for each process:\n");
    for(int i=0; i<n; i++){
        processes[i].pid = i+1;
        scanf("%d%d%d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].marked = 0;
        total_burst_time += processes[i].burst_time;
    }
    qsort(processes, n, sizeof(struct process), compare_arrival_time);
    printf("\n\n");
    printf("FCFS Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<n; i++){
        now += processes[i].burst_time;
        processes[i].completion_time = now;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, 
               processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time,
               processes[i].waiting_time);
    }
    printf("\n\n");
    printf("SJF Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    now = 0;
    qsort(processes, n, sizeof(struct process), compare_arrival_time);
    int idx;
    while(now < total_burst_time){
        idx = -1;
        for(int i=0; i<n; i++){
            if(!processes[i].marked && processes[i].arrival_time <= now){
                if(idx == -1) idx = i;
                else if(processes[i].burst_time < processes[idx].burst_time) idx = i;
            }
        }
        processes[idx].marked = 1;
        processes[idx].completion_time = now + processes[idx].burst_time;
        now += processes[idx].burst_time;
        processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
        processes[idx].waiting_time = processes[idx].turnaround_time
                                       - processes[idx].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[idx].pid, processes[idx].arrival_time, 
               processes[idx].burst_time, processes[idx].completion_time, processes[idx].turnaround_time,
               processes[idx].waiting_time);
    }
    printf("\n\n");
    printf("Priority Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    now = 0;
    qsort(processes, n, sizeof(struct process), compare_priority);
    while(now < total_burst_time){
        idx = get_highest_priority(processes, n);
        if(idx == -1){
            now++;
            continue;
        }
        processes[idx].marked = 1;
        processes[idx].completion_time = now + processes[idx].burst_time;
        now += processes[idx].burst_time;
        processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
        processes[idx].waiting_time = processes[idx].turnaround_time
                                       - processes[idx].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[idx].pid, 
               processes[idx].arrival_time, processes[idx].burst_time, processes[idx].priority,
               processes[idx].completion_time, processes[idx].turnaround_time, processes[idx].waiting_time);
    }
    printf("\n\n");
    printf("Round Robin Scheduling\n");
    printf("Enter the time quantum: ");
    int quantum;
    scanf("%d", &quantum);
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    now = 0;
    for(int i=0; i<n; i++) processes[i].marked = 0;
    int total_remaining_time = total_burst_time;
    while(total_remaining_time){
        for(int i=0; i<n; i++){
            if(processes[i].marked) continue;
            if(processes[i].arrival_time > now) continue;
            if(processes[i].remaining_time <= quantum){
                total_remaining_time -= processes[i].remaining_time;
                processes[i].marked = 1;
                now += processes[i].remaining_time;
                processes[i].remaining_time = 0;
                processes[i].completion_time = now;
                processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, 
                       processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time,
                       processes[i].waiting_time);
            }
            else{
                total_remaining_time -= quantum;
                processes[i].remaining_time -= quantum;
                now += quantum;
            }
        }
    }
    return 0;
}