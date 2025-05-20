//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, sum = 0, temp;
    for(i=0; i<n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n-1; j++) {
            if(processes[j].burst_time > processes[j+1].burst_time) {
                temp = processes[j].burst_time;
                processes[j].burst_time = processes[j+1].burst_time;
                processes[j+1].burst_time = temp;
            }
        }
        sum += processes[i].burst_time;
    }
    int quantum = sum / n;
    int count = 0;
    int completed_processes = 0;
    while(completed_processes < n) {
        for(i=0; i<n; i++) {
            if(processes[i].burst_time > quantum && processes[i].burst_time > 0) {
                processes[i].burst_time -= quantum;
                processes[i].waiting_time += quantum;
                count += quantum;
            }
            else if(processes[i].burst_time > 0) {
                processes[i].burst_time = 0;
                processes[i].waiting_time += processes[i].burst_time;
                processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                completed_processes++;
            }
        }
    }
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int i, n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    struct process processes[n];
    printf("\nEnter the process ID and burst time for %d processes:\n", n);
    for(i=0; i<n; i++) {
        scanf("%d %d", &processes[i].pid, &processes[i].burst_time);
    }
    execute_processes(processes, n);
    return 0;
}