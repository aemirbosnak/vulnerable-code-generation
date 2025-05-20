//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include<stdio.h> 
#include<stdlib.h> 
 
int max_time = 100; 
  
struct process {
    int pid; 
    int arrival_time;
    int burst_time;  
}; 

void print_average_turnaround(int n, struct process arr[], int turnaround_time[]) {
    int sum = 0; 
    for (int i = 0; i < n; i++) 
        sum += turnaround_time[i]; 
    printf("\nAverage Turnaround Time: %f\n", (float)sum / (float)n); 
} 
  
void print_gantt_chart(int n, struct process arr[]) {
    // find total burst time 
    int total_burst_time = 0; 
    for (int i = 0; i < n; i++) 
        total_burst_time += arr[i].burst_time; 
  
    int current_time = 0; 
    printf("Gantt Chart:\n");
  
    while(current_time < total_burst_time) {
        int next_process_index = -1; 
        int min_completion_time = max_time; 
        for(int i = 0; i < n; i++) {
            if(arr[i].arrival_time <= current_time && arr[i].burst_time > 0) {
                if(arr[i].burst_time < min_completion_time) {
                    min_completion_time = arr[i].burst_time; 
                    next_process_index = i; 
                }
            }
        }
  
        // no process found, increase time 
        if(next_process_index == -1) {
            printf("|%d Idle |", current_time); 
            current_time += 1; 
        }
  
        // process found, execute it 
        else { 
            printf("| %d P%d |", current_time, arr[next_process_index].pid); 
            arr[next_process_index].burst_time -= 1; 
            current_time += 1; 
        }
    }
    printf("\n");
} 
  
void SJF_non_preemptive(int n, struct process arr[]) {
    printf("\nSJF Non-Preemptive:\n"); 
    int turnaround_time[n], total_wait_time = 0; 
  
    // execute processes by shortest job first order 
    for(int i = 0; i < n; i++) {
        int min_burst_time = max_time; 
        int process_index = -1; 
        for(int j = 0; j < n; j++) {
            if(arr[j].arrival_time <= i && arr[j].burst_time > 0) {
                if(arr[j].burst_time < min_burst_time) {
                    min_burst_time = arr[j].burst_time; 
                    process_index = j; 
                }
            }
        }
  
        if(process_index != -1) {
            arr[process_index].burst_time = 0; 
            turnaround_time[process_index] = i - arr[process_index].arrival_time + 1; 
            total_wait_time += turnaround_time[process_index] - arr[process_index].burst_time; 
        }
    }
    print_gantt_chart(n, arr); 
    printf("Total Wait Time: %d\n", total_wait_time); 
    print_average_turnaround(n, arr, turnaround_time); 
} 
  
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n); 
    struct process arr[n]; 
  
    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1); 
        printf("Enter Arrival Time: ");
        scanf("%d", &arr[i].arrival_time); 
        printf("Enter Burst Time: ");
        scanf("%d", &arr[i].burst_time); 
        arr[i].pid = i + 1; 
    }
  
    // execute SJF non preemptive
    SJF_non_preemptive(n, arr); 
    return 0; 
}