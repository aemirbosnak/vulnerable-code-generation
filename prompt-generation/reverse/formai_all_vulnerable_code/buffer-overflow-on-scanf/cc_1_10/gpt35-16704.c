//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

//Structure to represent a process
typedef struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
    int start_time;
} process_t;

//Function to read the input from the user
void read_input(process_t* processes, int n) {
    int i;
    printf("Enter the arrival time and burst time of each process:\n");
    for(i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }
}

//Function to implement the Shortest Job First scheduling algorithm
void sjf(process_t* processes, int n) {
    int i, time=0, completed=0, shortest_job, min_burst_time=9999999;
    float total_turnaround_time=0.0, total_waiting_time=0.0;
    printf("\n\nShortest Job First Scheduling Algorithm\n\n");
    //Run until all processes are completed
    while(completed < n) {
        //Select the process with the shortest burst time
        shortest_job = -1;
        min_burst_time = 9999999;
        for(i=0; i<n; i++) {
            if(processes[i].arrival_time <= time && processes[i].remaining_time < min_burst_time && processes[i].remaining_time > 0) {
                shortest_job = i;
                min_burst_time = processes[i].remaining_time;
            }
        }
        //If no process is available to be executed, move the time forward
        if(shortest_job == -1) {
            time++;
        }
        //Execute the selected process
        else {
            processes[shortest_job].start_time = time;
            processes[shortest_job].remaining_time--;
            time++;
            //If the process has been completed, update its completion time and calculate its turnaround time and waiting time
            if(processes[shortest_job].remaining_time == 0) {
                processes[shortest_job].completion_time = time;
                processes[shortest_job].turnaround_time = processes[shortest_job].completion_time - processes[shortest_job].arrival_time;
                processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
                total_turnaround_time += processes[shortest_job].turnaround_time;
                total_waiting_time += processes[shortest_job].waiting_time;
                completed++;
            }
        }
    }
    //Print the results
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time/n);
    printf("Average Waiting Time: %.2f\n\n", total_waiting_time/n);
}

//Function to implement the Round Robin scheduling algorithm
void round_robin(process_t* processes, int n) {
    int i, time=0, completed=0, time_quantum, remain_burst_time;
    float total_turnaround_time=0.0, total_waiting_time=0.0;
    printf("\n\nRound Robin Scheduling Algorithm\n\n");
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    //Run until all processes are completed
    while(completed < n) {
        //Execute each process for the time quantum or until it completes
        for(i=0; i<n; i++) {
            if(processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                remain_burst_time = processes[i].remaining_time;
                if(remain_burst_time <= time_quantum) {
                    time += remain_burst_time;
                    processes[i].remaining_time = 0;
                }
                else {
                    time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                }
                //If the process has been completed, update its completion time and calculate its turnaround time and waiting time
                if(processes[i].remaining_time == 0) {
                    processes[i].completion_time = time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    total_waiting_time += processes[i].waiting_time;
                    completed++;
                }
            }
        }
    }
    //Print the results
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time/n);
    printf("Average Waiting Time: %.2f\n\n", total_waiting_time/n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process_t *processes = malloc(n * sizeof(process_t));
    read_input(processes, n);
    sjf(processes, n);
    round_robin(processes, n);
    return 0;
}