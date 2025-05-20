//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include<stdio.h>

//Structure to represent a computer process
typedef struct process {
    int pid; //Process ID
    int arrival_time; //Arrival Time
    int burst_time; //Burst Time
    int completion_time; //Completion Time
    int waiting_time; //Waiting Time
    int turnaround_time; //Turnaround Time
} process;

//Function to perform First Come First Serve scheduling algorithm
void fcfs(process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    //Calculate completion time of first process
    processes[0].completion_time = processes[0].burst_time;
    total_turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    total_waiting_time = total_waiting_time + total_turnaround_time - processes[0].burst_time;

    //Calculate completion time, waiting time and turnaround time of remaining processes
    for(int i = 1; i < n; i++) {
        processes[i].completion_time = processes[i-1].completion_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    //Calculate average waiting time and turnaround time
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

    //Print Results
    printf("\nFCFS Scheduling Algorithm Results:\n\n");
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %0.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %0.2f\n", avg_turnaround_time);
}

//Function to perform Round Robin scheduling algorithm
void round_robin(process processes[], int n, int quantum) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int remaining_burst_time[n]; //Array to store remaining burst time of processes
    int current_time = 0; //Current time

    //Initialize remaining burst time array
    for(int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    //Loop till all processes are completed
    while(1) {
        int completed = 1;

        //Loop through all processes
        for(int i = 0; i < n; i++) {
            if(remaining_burst_time[i] > 0) {
                completed = 0;

                //If remaining burst time is less than or equal to quantum, process will complete
                if(remaining_burst_time[i] <= quantum) {
                    current_time += remaining_burst_time[i];
                    processes[i].completion_time = current_time;
                    remaining_burst_time[i] = 0;
                }

                //If remaining burst time is greater than quantum, process will get preempted
                else {
                    current_time += quantum;
                    remaining_burst_time[i] -= quantum;
                }
            }
        }

        //If all processes completed, break the loop
        if(completed) {
            break;
        }
    }

    //Calculate waiting time and turnaround time of all processes
    for(int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    //Calculate average waiting time and average turnaround time
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

    //Print Results
    printf("\nRound Robin Scheduling Algorithm Results:\n\n");
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %0.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %0.2f\n", avg_turnaround_time);
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    process processes[n];
    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i+1;
    }

    printf("\nEnter quantum for Round Robin Algorithm: ");
    scanf("%d", &quantum);

    fcfs(processes, n);
    round_robin(processes, n, quantum);

    return 0;
}