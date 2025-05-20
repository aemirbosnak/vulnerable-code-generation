//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct process p[],int n){
    int i,j;
    float avg_waiting_time=0.0,avg_turnaround_time=0.0;

    p[0].waiting_time =0;
    p[0].turnaround_time = p[0].burst_time;
    for(i=1;i<n;i++){
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    for(i=0;i<n;i++){
        avg_waiting_time += (float)p[i].waiting_time;
        avg_turnaround_time += (float)p[i].turnaround_time;
    }
    avg_waiting_time = avg_waiting_time/(float)n;
    avg_turnaround_time = avg_turnaround_time/(float)n;

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].burst_time,p[i].arrival_time,p[i].waiting_time,p[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n",avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n",avg_turnaround_time);
}

void SJF(struct process p[],int n){
    int i,j,time=0;
    float avg_waiting_time=0.0,avg_turnaround_time=0.0;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].burst_time>p[j].burst_time){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    for(i=1;i<n;i++){
        time += p[i-1].burst_time;
        p[i].waiting_time = time - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    for(i=0;i<n;i++){
        avg_waiting_time += (float)p[i].waiting_time;
        avg_turnaround_time += (float)p[i].turnaround_time;
    }
    avg_waiting_time = avg_waiting_time/(float)n;
    avg_turnaround_time = avg_turnaround_time/(float)n;

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].burst_time,p[i].arrival_time,p[i].waiting_time,p[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n",avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n",avg_turnaround_time);
}

void RoundRobin(struct process p[],int n,int t){
    int i,j,time=0;
    float avg_waiting_time=0.0,avg_turnaround_time=0.0;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].arrival_time>p[j].arrival_time){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    //Finding the total burst time
    int total_burst_time = 0;
    for(i=0;i<n;i++){
        total_burst_time += p[i].burst_time;
    }

    while(time < total_burst_time){
        for(i=0;i<n;i++){
            if(p[i].burst_time > 0){
                if(p[i].burst_time <= t){
                    time += p[i].burst_time;
                    p[i].burst_time = 0;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                }
                else{
                    time += t;
                    p[i].burst_time -= t;
                }
            }
        }
    }

    for(i=0;i<n;i++){
        avg_waiting_time += (float)p[i].waiting_time;
        avg_turnaround_time += (float)p[i].turnaround_time;
    }
    avg_waiting_time = avg_waiting_time/(float)n;
    avg_turnaround_time = avg_turnaround_time/(float)n;

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].burst_time,p[i].arrival_time,p[i].waiting_time,p[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n",avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n",avg_turnaround_time);
}

int main(){
    int i,n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process p[MAX];
    printf("Enter the process details:\n");
    for(i=0;i<n;i++){
        p[i].pid = i+1;
        printf("Process %d:\n",p[i].pid);
        printf("Enter burst time: ");
        scanf("%d",&p[i].burst_time);
        printf("Enter arrival time: ");
        scanf("%d",&p[i].arrival_time);
    }

    printf("\nFCFS Scheduling:\n");
    FCFS(p,n);

    printf("\nSJF Scheduling:\n");
    SJF(p,n);

    int t;
    printf("\nEnter time quantum: ");
    scanf("%d",&t);
    printf("\nRound Robin Scheduling:\n");
    RoundRobin(p,n,t);

    return 0;
}