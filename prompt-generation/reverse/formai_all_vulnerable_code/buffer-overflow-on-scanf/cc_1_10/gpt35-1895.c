//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: automated
#include<stdio.h>

//Structure to hold the process details
struct process{
    int process_id; //Process ID
    int arrival_time; //Arrival time of the process
    int burst_time; //Burst time of the process
    int waiting_time; //Waiting time of the process
    int turnaround_time; //Turnaround time of the process
    int completion_time; //Completion time of the process
};

//Function to perform Round Robin scheduling
void round_robin_scheduling(struct process p[], int n, int quantum){
    int i,j,time = 0, remaining_time[n];
    for(i=0;i<n;i++)
        remaining_time[i] = p[i].burst_time;
    while(1){
        int done = 1;
        for(i=0;i<n;i++){
            if(remaining_time[i]>0){
                done = 0;
                if(remaining_time[i]>quantum){
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                else{
                    time += remaining_time[i];
                    p[i].completion_time = time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if(done == 1)
            break;
    }
}

//Function to print the process details including the scheduling algorithm used
void print_process_details(struct process p[], int n, char algo_name[]){
    int i,total_waiting_time=0,total_turnaround_time=0;
    float avg_waiting_time,avg_turnaround_time;
    printf("\n Scheduling Algorithm Used : %s \n",algo_name);
    printf(" Process ID \t Arrival Time \t Burst Time \t Waiting Time \t Turnaround Time \t Completion Time \n");
    for(i=0;i<n;i++){
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t\t %d \n",p[i].process_id,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time,p[i].completion_time);
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time = (float)total_waiting_time/(float)n;
    avg_turnaround_time = (float)total_turnaround_time/(float)n;
    printf("\n Average Waiting Time : %f ",avg_waiting_time);
    printf("\n Average Turnaround Time : %f ",avg_turnaround_time);
}

int main(){
    int i,n,quantum;
    printf(" Enter the number of processes : ");
    scanf("%d",&n);
    struct process p[n];
    printf("\n Enter the arrival and burst times of the processes : \n");
    for(i=0;i<n;i++){
        printf(" Arrival time for P%d : ",i+1);
        scanf("%d",&p[i].arrival_time);
        printf(" Burst time for P%d : ",i+1);
        scanf("%d",&p[i].burst_time);
        p[i].process_id = i+1;
    }
    printf("\n Enter the time quantum : ");
    scanf("%d",&quantum);
    round_robin_scheduling(p,n,quantum);
    print_process_details(p,n,"Round Robin");
    return 0;
}