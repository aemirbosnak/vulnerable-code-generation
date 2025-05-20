//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int burst_time;
    int process_id;
}Process;

void fcfs(Process processes[],int n){
    int waiting_time[n],turn_around_time[n],total_waiting_time=0,total_turn_around_time=0,i;
    waiting_time[0]=0;
    for(i=1;i<n;i++){
        waiting_time[i]=processes[i-1].burst_time+waiting_time[i-1];
    }
    for(i=0;i<n;i++){
        turn_around_time[i]=processes[i].burst_time+waiting_time[i];
        total_turn_around_time+=turn_around_time[i];
        total_waiting_time+=waiting_time[i];
    }
    printf("First Come First Serve Scheduling Algorithm:\n\n");
    printf("Process ID \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d \t\t %d \t\t %d \t\t %d\n",processes[i].process_id,processes[i].burst_time,waiting_time[i],turn_around_time[i]);
    }
    printf("\nAverage Wait Time: %f\n",(float)total_waiting_time/n);
    printf("Average Turnaround Time: %f\n",(float)total_turn_around_time/n);
}

void sjf(Process processes[],int n){
    int i,j,temp,temp2,total_waiting_time=0,total_turn_around_time=0,current_time=0;
    float avg_waiting_time,avg_turn_around_time;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(processes[i].burst_time>processes[j].burst_time){
                temp=processes[i].burst_time;
                processes[i].burst_time=processes[j].burst_time;
                processes[j].burst_time=temp;
                temp2=processes[i].process_id;
                processes[i].process_id=processes[j].process_id;
                processes[j].process_id=temp2;
            }
        }
    }
    printf("Shortest Job First Scheduling Algorithm:\n\n");
    printf("Process ID \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for(i=0;i<n;i++){
        total_waiting_time+=current_time;
        current_time+=processes[i].burst_time;
        total_turn_around_time+=current_time;
        printf("%d \t\t %d \t\t %d \t\t %d\n",processes[i].process_id,processes[i].burst_time,current_time-processes[i].burst_time,current_time);
    }
    avg_waiting_time=(float)total_waiting_time/n;
    avg_turn_around_time=(float)total_turn_around_time/n;
    printf("\nAverage Wait Time: %f\n",avg_waiting_time);
    printf("Average Turnaround Time: %f\n",avg_turn_around_time);
}

int main(){
    int i,n,choice;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    Process processes[n];
    for(i=0;i<n;i++){
        processes[i].process_id=i+1;
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&processes[i].burst_time);
    }
    printf("\nChoose a CPU scheduling algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: fcfs(processes,n); break;
        case 2: sjf(processes,n); break;
        default: printf("Invalid choice.\n");
    }
    return 0;
}