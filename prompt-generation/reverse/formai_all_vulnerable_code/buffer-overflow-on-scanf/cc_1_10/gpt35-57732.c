//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

// Defining a structure of processes
struct Process{
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
}processes[100];

// Function to execute the First-Come, First-Serve Algorithm
void FCFS(int n){
    // Sorting the processes based on their arrival time
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(processes[i].arrival_time>processes[j].arrival_time){
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    int current_time = 0;
    for(int i=0;i<n;i++){
        // If the process has arrived, execute it
        if(current_time>=processes[i].arrival_time){
            processes[i].waiting_time = current_time-processes[i].arrival_time;
            current_time+=processes[i].burst_time;
            processes[i].completion_time = current_time;
            processes[i].turnaround_time = processes[i].completion_time-processes[i].arrival_time;
        }
        // If the process has not arrived, skip it
        else{
            current_time = processes[i].arrival_time+processes[i].burst_time;
            processes[i].completion_time = current_time;
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].completion_time-processes[i].arrival_time;
        }
    }
}

// Function to execute the Shortest-Job-First Algorithm
void SJF(int n){
    // Sorting the processes based on their burst time
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(processes[i].burst_time>processes[j].burst_time){
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    int current_time = 0;
    for(int i=0;i<n;i++){
        // If the process has arrived, execute it
        if(current_time>=processes[i].arrival_time){
            processes[i].waiting_time = current_time-processes[i].arrival_time;
            current_time+=processes[i].burst_time;
            processes[i].completion_time = current_time;
            processes[i].turnaround_time = processes[i].completion_time-processes[i].arrival_time;
        }
        // If the process has not arrived, skip it
        else{
            current_time = processes[i].arrival_time+processes[i].burst_time;
            processes[i].completion_time = current_time;
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].completion_time-processes[i].arrival_time;
        }
    }
}

// Function to execute the Round-Robin Algorithm
void RR(int n, int quantum){
    int remaining_burst_time[100];
    for(int i=0;i<n;i++){
        remaining_burst_time[i] = processes[i].burst_time;
    }
    int current_time = 0;
    while(1){
        int all_finished = 1;
        for(int i=0;i<n;i++){
            // If the process has remaining burst time, execute it
            if(remaining_burst_time[i]>0){
                all_finished = 0;
                if(remaining_burst_time[i]>quantum){
                    current_time+=quantum;
                    remaining_burst_time[i]-=quantum;
                }
                else{
                    current_time+=(remaining_burst_time[i]);
                    processes[i].completion_time = current_time;
                    processes[i].waiting_time = current_time-processes[i].arrival_time-processes[i].burst_time;
                    remaining_burst_time[i] = 0;
                }
            }
        }
        // If all processes are finished, break the loop
        if(all_finished==1){
            break;
        }
    }
    for(int i=0;i<n;i++){
        processes[i].turnaround_time = processes[i].completion_time-processes[i].arrival_time;
    }
}


int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of each process:\n");
    for(int i=0;i<n;i++){
        processes[i].process_id = i+1;
        printf("Process %d: ",i+1);
        scanf("%d %d",&processes[i].arrival_time,&processes[i].burst_time);
    }
    int choice;
    printf("Choose the CPU Scheduling Algorithm:\n1. First-Come, First-Serve\n2. Shortest-Job-First\n3. Round-Robin\n");
    scanf("%d",&choice);
    int quantum;
    if(choice==3){
        printf("Enter the time quantum: ");
        scanf("%d",&quantum);
    }
    switch(choice){
        case 1: 
            FCFS(n);
            break;
        case 2:
            SJF(n);
            break;
        case 3:
            RR(n,quantum);
            break;
        default:
            printf("Invalid choice!");
            exit(0);
    }
    // Print the details of each process
    float avg_waiting_time=0.0,avg_turnaround_time=0.0;
    printf("------------------------------------------------------\n");
    printf("Process ID  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    printf("------------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%-12d%-14d%-12d%-14d%-16d\n",processes[i].process_id,processes[i].arrival_time,
                                                processes[i].burst_time,processes[i].waiting_time,
                                                processes[i].turnaround_time);
        avg_waiting_time+=processes[i].waiting_time;
        avg_turnaround_time+=processes[i].turnaround_time;
    }
    printf("------------------------------------------------------\n");
    avg_waiting_time/=n;
    avg_turnaround_time/=n;
    printf("Average Waiting Time: %.2f\n",avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n",avg_turnaround_time);
    return 0;
}