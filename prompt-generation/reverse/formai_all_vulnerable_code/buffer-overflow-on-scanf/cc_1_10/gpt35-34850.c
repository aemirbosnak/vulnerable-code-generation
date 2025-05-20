//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
/* 
This program implements a CPU scheduling algorithm called First-Come, First-Served (FCFS). 
FCFS is a non-preemptive scheduling algorithm that schedules tasks based on their arrival time. 
The process that arrives first is executed first. If two processes arrive at the same time, 
the one with the lower process ID is executed first.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define a structure for process
struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    bool is_completed;
};

// define a function to compare two processes based on their arrival time
int compare_arrival_time(const void* a, const void* b){
    int arrival_time_a = ((struct process*)a)->arrival_time;
    int arrival_time_b = ((struct process*)b)->arrival_time;

    if (arrival_time_a < arrival_time_b){
        return -1;
    } else if (arrival_time_a > arrival_time_b){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int n; // number of processes

    // get input from user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // create an array of n processes
    struct process processes[n];

    // initialize the processes array
    for (int i=0; i<n; i++){
        processes[i].id = i;
        processes[i].is_completed = false;

        // get input from user
        printf("Enter the arrival time and burst time for process %d: ", i);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    // sort the processes array based on arrival time
    qsort(processes, n, sizeof(struct process), compare_arrival_time);

    // simulate the execution of processes
    int current_time = 0;
    for (int i=0; i<n; i++){
        // update the waiting time and turnaround time for the process
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        // update the current time
        current_time += processes[i].burst_time;

        // mark the process as completed
        processes[i].is_completed = true;
    }

    // print the output
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}