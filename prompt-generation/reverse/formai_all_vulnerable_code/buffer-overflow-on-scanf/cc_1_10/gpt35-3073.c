//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include <stdio.h>

// Definition of process struct
struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

// Function to implement FCFS scheduling
void fcfs(struct process p[], int n) {
    int i;
    int total_wait = 0;
    int total_turnaround = 0;
  
    printf("\nFCFS Scheduling Algorithm:");
    printf("\nProcess ID\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for(i = 0; i < n; i++) {
        if(i == 0) {
            p[i].waiting_time = 0;
            p[i].turnaround_time = p[i].burst_time;
        } else {
            p[i].waiting_time = p[i - 1].turnaround_time;
            p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        }
      
        total_wait += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
      
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
  
    printf("\nAverage waiting time: %f", (float)total_wait / n);
    printf("\nAverage turnaround time: %f", (float)total_turnaround / n);
}

// Function to implement Round Robin scheduling
void round_robin(struct process p[], int n, int quantum) {
    int i, j;
    int total_wait = 0;
    int total_turnaround = 0;
  
    printf("\nRound Robin Scheduling Algorithm:");
    printf("\nProcess ID\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
  
    int remaining_time[n];
    for(i = 0; i < n; i++) {
        remaining_time[i] = p[i].burst_time;
    }
  
    int time = 0;
    while(1) {
        int done = 1;
        for(i = 0; i < n; i++) {
            if(remaining_time[i] > 0) {
                done = 0;
              
                if(remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    p[i].turnaround_time = time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    remaining_time[i] = 0;
                  
                    total_wait += p[i].waiting_time;
                    total_turnaround += p[i].turnaround_time;
                  
                    printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
                }
            }
        }
      
        if(done == 1) {
            break;
        }
    }
  
    printf("\nAverage waiting time: %f", (float)total_wait / n);
    printf("\nAverage turnaround time: %f", (float)total_turnaround / n);
}

// Function to implement Priority scheduling
void priority(struct process p[], int n) {
    int i, j;
    int total_wait = 0;
    int total_turnaround = 0;
    struct process temp;
  
    printf("\nPriority Scheduling Algorithm:");
    printf("\nProcess ID\t Arrival Time\t Burst Time\t Priority\t Waiting Time\t Turnaround Time\n");
  
    // Sorts the processes in ascending order of their priorities
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
  
    for(i = 0; i < n; i++) {
        if(i == 0) {
            p[i].waiting_time = 0;
            p[i].turnaround_time = p[i].burst_time;
        } else {
            p[i].waiting_time = p[i - 1].turnaround_time;
            p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        }
      
        total_wait += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
      
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }
  
    printf("\nAverage waiting time: %f", (float)total_wait / n);
    printf("\nAverage turnaround time: %f", (float)total_turnaround / n);
}

int main() {
    int n;
    int i;
  
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
  
    struct process p[n];
  
    for(i = 0; i < n; i++) {
        printf("\nEnter details of process #%d", i + 1);
        printf("\nEnter arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Enter priority: ");
        scanf("%d", &p[i].priority);
        p[i].process_id = i + 1;
    }
  
    fcfs(p, n);
    round_robin(p, n, 2);
    priority(p, n);
  
    return 0;
}