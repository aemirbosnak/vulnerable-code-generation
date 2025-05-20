//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

//Structure for the process
struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
};

//Function to sort the processes based on priority
void sort_processes_by_priority(struct process *p, int n) {
    int i, j;
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(p[i].priority > p[j].priority) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

//Function to execute the processes based on Priority scheduling algorithm
void execute_processes(struct process *p, int n) {
    printf("\n");
    int current_time = 0;
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    sort_processes_by_priority(p, n);

    int *remaining_time = (int*)malloc(sizeof(int)*n);
    int *completion_time = (int*)malloc(sizeof(int)*n);
    int *waiting_time = (int*)malloc(sizeof(int)*n);
    int *turnaround_time = (int*)malloc(sizeof(int)*n);
    int *is_executed = (int*)malloc(sizeof(int)*n);

    //Initializing the remaining time of all processes and is_executed to 0 initially
    for(int i=0;i<n;i++) {
        remaining_time[i] = p[i].burst_time;
        is_executed[i] = 0;
    }

    int completed_processes = 0;
    while(completed_processes != n) {
        int min_priority_index = -1;
        for(int i=0;i<n;i++) {
            if(p[i].arrival_time <= current_time && is_executed[i] == 0) {
                if(min_priority_index == -1 || p[i].priority < p[min_priority_index].priority) {
                    min_priority_index = i;
                }
            }
        }
        if(min_priority_index == -1) {
            current_time++;
        }
        else {
            remaining_time[min_priority_index]--;
            current_time++;
            if(remaining_time[min_priority_index] == 0) {
                completion_time[min_priority_index] = current_time;
                turnaround_time[min_priority_index] = completion_time[min_priority_index] - p[min_priority_index].arrival_time;
                waiting_time[min_priority_index] = turnaround_time[min_priority_index] - p[min_priority_index].burst_time;
                avg_waiting_time += waiting_time[min_priority_index];
                avg_turnaround_time += turnaround_time[min_priority_index];
                is_executed[min_priority_index] = 1;
                completed_processes++;
            }
        }
    }
    printf("%-20s %-20s %-20s %-20s %-20s %-20s\n", "Process_ID", "Arrival_Time", "Burst_Time", "Priority", "Completion_time", "Turnaround_time");
    for(int i=0;i<n;i++) {
        printf("%-20d %-20d %-20d %-20d %-20d %-20d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].priority, completion_time[i], turnaround_time[i]);
    }
    printf("Average waiting time:%f\n", avg_waiting_time/n);
    printf("Average turnaround time:%f\n", avg_turnaround_time/n);
}

int main() {
    printf("Enter the number of processes:");
    int n;
    scanf("%d", &n);
    struct process *p = (struct process*)malloc(sizeof(struct process)*n);
    printf("\nEnter the arrival time, burst time and priority of %d processes:\n", n);
    for(int i=0;i<n;i++) {
        printf("Process %d:\n", i+1);
        p[i].process_id = i+1;
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
    }
    execute_processes(p, n);
    return 0;
}