//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int pid;    // process ID
    int arr_t;  // arrival time
    int bur_t;  // burst time
    int wt_t;   // waiting time
    int tat_t;  // turnaround time
} Process;

// function to sort an array of Processes by arrival time (ascending order)
void sortArrivalTime(Process *processes, int num_processes) {
    Process temp;
    for(int i=0; i<num_processes-1; i++) {
        for(int j=0; j<num_processes-1-i; j++) {
            if(processes[j].arr_t > processes[j+1].arr_t) {
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

// function to calculate wait time, turnaround time, and average wait time
void calculateTime(Process *processes, int num_processes) {
    int total_wait_time = 0, total_tat_time = 0;
    for(int i=0; i<num_processes; i++) {
        if(i == 0) {
            processes[i].wt_t = 0;
            processes[i].tat_t = processes[i].bur_t;
        } else {
            processes[i].wt_t = processes[i-1].tat_t - processes[i].arr_t;
            if(processes[i].wt_t < 0)
                processes[i].wt_t = 0;
            processes[i].tat_t = processes[i].wt_t + processes[i].bur_t;
        }
        total_wait_time += processes[i].wt_t;
        total_tat_time += processes[i].tat_t;
    }
    printf("Average wait time: %.2f\n", (float)total_wait_time/num_processes);
}

int main() {
    int num_processes;
    Process processes[MAX_PROCESSES];

    // input number of processes
    printf("Enter number of processes (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    // input process details
    printf("Enter arrival time and burst time for each process:\n");
    for(int i=0; i<num_processes; i++) {
        printf("Process %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Arrival Time = ");
        scanf("%d", &processes[i].arr_t);
        printf("Burst Time   = ");
        scanf("%d", &processes[i].bur_t);
    }

    // sort processes by arrival time
    sortArrivalTime(processes, num_processes);

    // print details of all the processes
    printf("\nProcess Chart:\n");
    printf("PID   Arrival Time   Burst Time\n");
    for(int i=0; i<num_processes; i++) {
        printf("%-5d%-15d%d\n", processes[i].pid, processes[i].arr_t, processes[i].bur_t);
    }

    // calculate wait time, turnaround time, and average wait time
    calculateTime(processes, num_processes);

    return 0;
}