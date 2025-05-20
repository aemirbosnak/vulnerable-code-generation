//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include<stdio.h> 
#include<stdlib.h> 

//defining the process structure
struct process 
{ 
    int pid; 
    int arrival_time; 
    int burst_time; 
    int priority; 
    int wait_time; 
    int turnaround_time;
    int completion_time; 
}; 

void input_processes(struct process p[], int n) {

    printf("Enter the process details as follows:\n");

    for(int i=0;i<n;i++) {
        printf("Process %d\n",i+1);
        printf("Enter arrival time, burst time and priority (separated by spaces): ");
        scanf("%d %d %d",&p[i].arrival_time,&p[i].burst_time,&p[i].priority);
        p[i].pid = i+1;
    }
}

void sort_processes_by_arrival_time(struct process p[], int n) {

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                //swap
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void execute_FCFS(struct process p[], int n) {
    //sort by arrival time (just in case not sorted already)
    sort_processes_by_arrival_time(p,n);

    int current_time = p[0].arrival_time;
    for(int i=0;i<n;i++) {
        if(p[i].arrival_time <= current_time) {
            p[i].completion_time = current_time + p[i].burst_time;
            p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
            p[i].wait_time = p[i].turnaround_time - p[i].burst_time;
        }
        else {
            // if the arrival of the process is later than the current_time, we just move ahead
            current_time = p[i].arrival_time;
            p[i].completion_time = current_time + p[i].burst_time;
            p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
            p[i].wait_time = p[i].turnaround_time - p[i].burst_time;
        }
        current_time = p[i].completion_time;
    }
}

void execute_SJF(struct process p[], int n) {

    //sort by arrival time (just in case not sorted already)
    sort_processes_by_arrival_time(p,n);

    int current_time = p[0].arrival_time;
    int completed = 0;
    while(completed < n) {
        int min_burst_time = -1;
        int min_index = -1;
        for(int i=0;i<n;i++) {
            if(p[i].arrival_time <= current_time && p[i].burst_time != 0) {
                if(min_burst_time == -1 || p[i].burst_time < min_burst_time) {
                    min_burst_time = p[i].burst_time;
                    min_index = i;
                }
            }
        }
        if(min_index != -1) {
            p[min_index].burst_time--;
            if(p[min_index].burst_time == 0) {
                completed++;
                p[min_index].completion_time = current_time+1;
                p[min_index].turnaround_time = p[min_index].completion_time - p[min_index].arrival_time;
                p[min_index].wait_time = p[min_index].turnaround_time - (int)(p[min_index].burst_time);
            }
        }
        current_time++;
    }
}

void execute_Priority(struct process p[], int n) {

    //sort by arrival time (just in case not sorted already)
    sort_processes_by_arrival_time(p,n);

    int current_time = p[0].arrival_time;
    int completed = 0;
    while(completed < n) {
        int min_priority = -1;
        int min_index = -1;
        for(int i=0;i<n;i++) {
            if(p[i].arrival_time <= current_time && p[i].burst_time != 0) {
                if(min_priority == -1 || p[i].priority < min_priority) {
                    min_priority = p[i].priority;
                    min_index = i;
                }
            }
        }
        if(min_index != -1) {
            p[min_index].burst_time--;
            if(p[min_index].burst_time == 0) {
                completed++;
                p[min_index].completion_time = current_time+1;
                p[min_index].turnaround_time = p[min_index].completion_time - p[min_index].arrival_time;
                p[min_index].wait_time = p[min_index].turnaround_time - (int)(p[min_index].burst_time);
            }
        }
        current_time++;
    }
}

void display_results(struct process p[], int n) {

    printf("PID Arrival Burst Priority Waiting Time Turnaround Time\n");
    for(int i=0;i<n;i++) {
        printf("%2d%6d%7d%8d%14d%15d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].priority,p[i].wait_time,p[i].turnaround_time);
    }
}

int main() 
{ 
    int n,choice;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    struct process p[n];

    input_processes(p,n);

    printf("Choose a CPU Scheduling Algorithm to execute:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Priority Scheduling\n");
    printf("Enter Your Choice: ");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            execute_FCFS(p,n);
            break;
        case 2:
            execute_SJF(p,n);
            break;
        case 3:
            execute_Priority(p,n);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            return -1;
    }

    display_results(p,n);

    return 0; 
}