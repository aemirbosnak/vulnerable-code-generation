//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Process{
    int pID;             // Process ID
    int arrival_time;    // Arrival Time
    int burst_time;      // Burst Time
    int waiting_time;    // Waiting Time
    int turnaround_time; // Turnaround Time
}Process;

void FCFS(Process* p, int num_processes);
void SJF(Process* p, int num_processes);
void roundRobin(Process* p, int num_processes, int quantum);

int main(){
    int num_processes, quantum;
    printf("Enter the number of processes: ");
    scanf("%d",&num_processes);
    Process* process_list = (Process*)malloc(num_processes*sizeof(Process));

    // Input processes
    for(int i=0; i<num_processes; i++){
        process_list[i].pID = i+1;
        printf("Enter Arrival Time of P%d: ",i+1);
        scanf("%d",&process_list[i].arrival_time);
        printf("Enter Burst Time of P%d: ",i+1);
        scanf("%d",&process_list[i].burst_time);
    }

    // First Come First Serve Scheduling
    FCFS(process_list, num_processes);

    // Shortest Job First Scheduling
    SJF(process_list, num_processes);

    // Round Robin Scheduling
    printf("\nEnter time quantum for Round Robin Scheduling: ");
    scanf("%d",&quantum);
    roundRobin(process_list, num_processes, quantum);

    return 0;
}

void FCFS(Process* p, int num_processes){
    printf("\n\nFCFS Scheduling\n\n");
    int time_elapsed = 0;

    // Calculate waiting and turnaround time
    for(int i=0; i<num_processes; i++){
        if(p[i].arrival_time > time_elapsed){
            time_elapsed = p[i].arrival_time;
        }
        p[i].waiting_time = time_elapsed - p[i].arrival_time;
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        time_elapsed += p[i].burst_time;
    }

    // Print results
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pID,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    }
}

void SJF(Process* p, int num_processes){
    printf("\n\nShortest Job First Scheduling\n\n");
    Process temp;
    int i, j;

    // Sort processes based on burst time (selection sort)
    for(i=0; i<num_processes-1; i++){
        for(j=i+1; j<num_processes; j++){
            if(p[j].burst_time < p[i].burst_time){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time_elapsed = 0;

    // Calculate waiting and turnaround time
    for(int i=0; i<num_processes; i++){
        if(p[i].arrival_time > time_elapsed){
            time_elapsed = p[i].arrival_time;
        }
        p[i].waiting_time = time_elapsed - p[i].arrival_time;
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        time_elapsed += p[i].burst_time;
    }

    // Print results
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pID,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    }
}

void roundRobin(Process* p, int num_processes, int quantum){
    printf("\n\nRound Robin Scheduling\n\n");
    int* remaining_burst_time = (int*)malloc(num_processes*sizeof(int));

    // Copy burst time to remaining burst time
    for(int i=0; i<num_processes; i++){
        remaining_burst_time[i] = p[i].burst_time;
    }

    int time_elapsed = 0;

    // Calculate waiting and turnaround time
    while(1){
        int all_processes_completed = 1;
        for(int i=0; i<num_processes; i++){
            if(remaining_burst_time[i] > 0){
                all_processes_completed = 0;
                if(remaining_burst_time[i] <= quantum){
                    time_elapsed += remaining_burst_time[i];
                    p[i].waiting_time = time_elapsed - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time = time_elapsed - p[i].arrival_time;
                    remaining_burst_time[i] = 0;
                }
                else{
                    time_elapsed += quantum;
                    remaining_burst_time[i] -= quantum;
                }
            }
        }
        if(all_processes_completed){
            break;
        }
    }

    // Print results
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pID,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    }

    // Free memory
    free(remaining_burst_time);
}