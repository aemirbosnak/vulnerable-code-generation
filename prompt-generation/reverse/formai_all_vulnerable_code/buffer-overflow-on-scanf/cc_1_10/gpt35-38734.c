//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESSES 10 // maximum number of processes
#define TIME_QUANTUM 2 // time quantum for round robin algorithm

// Process structure
struct process {
    char pid[5];
    int arrival_time; // process arrival time
    int burst_time; // process burst time
    int remaining_time; // remaining burst time
    int completion_time; // time when process is completed
    int waiting_time; // waiting time for process
    int turnaround_time; // turnaround time for process
};

// Function to swap two processes
void swap(struct process *xp, struct process *yp) {
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to sort processes by arrival time
void sortByArrivalTime(struct process processes[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

// Function to simulate FCFS scheduling algorithm
void fcfs(struct process processes[], int n) {
    int i, curr_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
  
    for (i = 0; i < n; i++) {
        if (curr_time < processes[i].arrival_time) {
            curr_time = processes[i].arrival_time; // wait till next process arrives
        }
        processes[i].completion_time = curr_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        curr_time = processes[i].completion_time; // update current time
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    printf("FCFS Scheduling Algorithm results:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time/n);
}

// Function to simulate SJF scheduling algorithm
void sjf(struct process processes[], int n) {
    int i, j, curr_time = 0, completed = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    bool flag = false; // flag to indicate if a process has been selected to execute
  
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= curr_time && processes[i].remaining_time > 0) {
                if (!flag) { // select process with minimum remaining time
                    j = i;
                    flag = true;
                } else if (processes[i].remaining_time < processes[j].remaining_time) {
                    j = i;
                }
            }
        }
        if (!flag) { 
            curr_time++; // if no process is available, increase current time
            continue;
        }
        processes[j].remaining_time--; // execute selected process for 1 unit of time
        if (processes[j].remaining_time == 0) { // if process is completed
            completed++;
            flag = false;
            processes[j].completion_time = curr_time + 1;
            processes[j].turnaround_time = processes[j].completion_time - processes[j].arrival_time;
            processes[j].waiting_time = processes[j].turnaround_time - processes[j].burst_time;
            avg_waiting_time += processes[j].waiting_time;
            avg_turnaround_time += processes[j].turnaround_time;
        }
        curr_time++; // update current time
    }
    printf("SJF Scheduling Algorithm results:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time/n);
}

// Function to simulate Round Robin scheduling algorithm
void roundRobin(struct process processes[], int n) {
    int i, curr_time = 0, completed = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
  
    while (completed < n) {
        bool flag = false;
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= curr_time && processes[i].remaining_time > 0) {
                flag = true; // mark process as available for execution
                if (processes[i].remaining_time > TIME_QUANTUM) {
                    curr_time += TIME_QUANTUM; // execute process for time quantum
                    processes[i].remaining_time -= TIME_QUANTUM;
                } else {
                    curr_time += processes[i].remaining_time; // execute process for its remaining burst time
                    processes[i].remaining_time = 0;
                    completed++;
                    processes[i].completion_time = curr_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    avg_waiting_time += processes[i].waiting_time;
                    avg_turnaround_time += processes[i].turnaround_time;
                }
            }
        }
        if (!flag) { 
            curr_time++; // if no process is available, increase current time
        }
    }
    printf("Round Robin Scheduling Algorithm results:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time/n);
}

// Main function
int main() {
    int i, n;
    struct process processes[MAX_PROCESSES];
  
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        printf("Process ID: ");
        scanf("%s", processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
  
    sortByArrivalTime(processes, n);
  
    fcfs(processes, n);
  
    sjf(processes, n);
  
    roundRobin(processes, n);
  
    return 0;
}