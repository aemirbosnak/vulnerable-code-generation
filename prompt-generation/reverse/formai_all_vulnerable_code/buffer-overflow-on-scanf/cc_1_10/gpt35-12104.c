//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>

// defining structure for the processes
struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

// function for sorting the processes based on burst time
void sort_processes(struct process p[], int n) {
    int i, j;
    struct process temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(p[j].burst_time > p[j+1].burst_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

// function for implementing the Shortest Job First algorithm
void SJF(struct process p[], int n) {
    int i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    sort_processes(p, n); // sorting the processes based on burst time
    int completion_time[n];
    int remaining_burst_time[n];
    for(i=0; i<n; i++) {
        remaining_burst_time[i] = p[i].burst_time;
    }
    int t = 0, count = 0;
    while(count < n) {
        int min_bt = 9999, min_proc = -1;
        for(i=0; i<n; i++) {
            if(p[i].arrival_time <= t && remaining_burst_time[i] < min_bt && remaining_burst_time[i] > 0) {
                min_bt = remaining_burst_time[i];
                min_proc = i;
            }
        }
        if(min_proc == -1) {
            t++;
            continue;
        }
        completion_time[min_proc] = t + remaining_burst_time[min_proc];
        t = completion_time[min_proc];
        p[min_proc].waiting_time = completion_time[min_proc] - p[min_proc].burst_time - p[min_proc].arrival_time;
        if(p[min_proc].waiting_time < 0) {
            p[min_proc].waiting_time = 0;
        }
        p[min_proc].turnaround_time = p[min_proc].burst_time + p[min_proc].waiting_time;
        remaining_burst_time[min_proc] = 0;
        count++;
    }
    for(i=0; i<n; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Shortest Job First Scheduling Algorithm:\n");
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for(i=0; i<n; i++) {
        printf("Enter the arrival time and burst time for Process %d: ", i+1);
        scanf("%d%d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i+1;
    }
    SJF(p, n); // calling the SJF function
    return 0;
}