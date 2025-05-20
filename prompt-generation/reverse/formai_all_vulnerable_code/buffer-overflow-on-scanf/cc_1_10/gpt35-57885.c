//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct process{
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void round_robin_scheduling(struct process p[],int n,int quantum){
    int remaining_burst_time[n];
    for(int i=0;i<n;i++) remaining_burst_time[i]=p[i].burst_time;
    int current_time=0;
    while(1){
        int done=1;
        for(int i=0;i<n;i++){
            if(remaining_burst_time[i]>0){
                done=0;
                if(remaining_burst_time[i]>quantum){
                    current_time+=quantum;
                    remaining_burst_time[i]-=quantum;
                }
                else{
                    current_time+=remaining_burst_time[i];
                    p[i].completion_time=current_time;
                    p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
                    p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
                    remaining_burst_time[i]=0;
                }
            }
        }
        if(done==1) break;
    }
}

void print_results(struct process p[],int n){
    printf("\n\nPID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0;i<n;i++) printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turnaround_time,p[i].waiting_time);
    float avg_waiting_time=0,avg_turnaround_time=0;
    for(int i=0;i<n;i++){
        avg_waiting_time+=p[i].waiting_time;
        avg_turnaround_time+=p[i].turnaround_time;
    }
    avg_waiting_time/=n;
    avg_turnaround_time/=n;
    printf("\n\nAverage Waiting Time : %f\n",avg_waiting_time);
    printf("Average Turnaround Time : %f\n",avg_turnaround_time);
}

int main(){
    int n,quantum;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    struct process p[n];
    printf("\n\nEnter the arrival time and burst time for each process\n");
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        printf("Process %d : ",i+1);
        scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
    }
    printf("\n\nEnter the time quantum for Round Robin Scheduling : ");
    scanf("%d",&quantum);
    system("clear");
    printf("Loading...\n");
    sleep(2);
    round_robin_scheduling(p,n,quantum);
    print_results(p,n);
    return 0;
}