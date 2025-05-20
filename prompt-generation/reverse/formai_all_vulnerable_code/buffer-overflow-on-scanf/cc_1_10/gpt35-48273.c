//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

// creating a process structure
struct process{
    int pid; // process id
    int burst_time; // burst time
    int priority; // priority of process
    int waiting_time; // waiting time
    int turnaround_time; // turnaround time
};
typedef struct process Process;

// function to find waiting and turnaround time of the processes
void find_waiting_time(int n, Process processes[], int wt[], int quantum){
    int remaining_time[n]; // array to store the remaining burst time of processes
    for(int i=0;i<n;i++){
        remaining_time[i] = processes[i].burst_time; // initializing remaining time array with burst time of processes
        wt[i] = 0; // initializing waiting time array with 0
    }
    int t=0; // initializing time
    while(1){
        int flag = 1;
        for(int i=0;i<n;i++){
            if(remaining_time[i]>0){
                flag = 0;
                if(remaining_time[i]>quantum){
                    t += quantum;
                    remaining_time[i] -= quantum;
                }
                else{
                    t += remaining_time[i];
                    wt[i] = t - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if(flag==1){
            break;
        }
    }
}

// function to find the turnaround time of the processes
void find_turnaround_time(int n, Process processes[], int wt[], int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = processes[i].burst_time + wt[i];
    }
}

// function to find the average waiting and turnaround time of the processes
void find_average_time(int n, Process processes[], int quantum){
    int wt[n], tat[n]; // arrays to store the waiting and turnaround time of the processes
    int total_waiting_time = 0, total_turnaround_time = 0; // initializing total_waiting_time and total_turnaround_time to 0
    find_waiting_time(n, processes, wt, quantum); // finding the waiting time of the processes
    find_turnaround_time(n, processes, wt, tat); // finding the turnaround time of the processes
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++){
        total_waiting_time += wt[i];
        total_turnaround_time += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, wt[i], tat[i]); // printing the details of the processes
    }
    float avg_waiting_time = (float)total_waiting_time/n; // finding the average waiting time of the processes
    float avg_turnaround_time = (float)total_turnaround_time/n; // finding the average turnaround time of the processes
    printf("\nAverage Waiting Time: %f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %f", avg_turnaround_time);
}

// function to compare priority of processes
int compare_priority(const void *p1, const void *p2){
    Process *process1 = (Process *)p1;
    Process *process2 = (Process *)p2;
    return process2->priority - process1->priority;
}

// main function
int main(){
    int n, quantum; // n is number of processes, quantum is time quantum
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process processes[n]; // array of processes
    printf("Enter the details of the processes:\n");
    for(int i=0;i<n;i++){
        printf("Process %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
    qsort(processes, n, sizeof(Process), compare_priority); // sorting the processes based on priority in descending order
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    find_average_time(n, processes, quantum); // finding the average waiting and turnaround time of the processes
    return 0;
}