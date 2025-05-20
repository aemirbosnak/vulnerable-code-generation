//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include<stdio.h> 

struct Process {
    int process_id, burst_time, wait_time, turnaround_time, response_time;
};

void round_robin(struct Process processes[], int n, int quantum) {
    int remaining_burst_time[n];
    for(int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }
    int t = 0;
    while(1) {
        int all_done = 1;
        for(int i = 0; i < n; i++) {
            if(remaining_burst_time[i] > 0) {
                all_done = 0;
                if(remaining_burst_time[i] > quantum) {
                    t += quantum;
                    remaining_burst_time[i] -= quantum;
                }
                else {
                    t += remaining_burst_time[i];
                    processes[i].turnaround_time = t;
                    processes[i].wait_time = t - processes[i].burst_time;
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if(all_done) {
            break;
        }
    }
}

void display(struct Process processes[], int n) {
    printf("Process ID \tBurst Time \tWait Time \tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d \t\t%d \t\t%d \t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].wait_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    struct Process processes[n];
    for(int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i+1;
    }
    round_robin(processes, n, quantum);
    display(processes, n);
    return 0;
}