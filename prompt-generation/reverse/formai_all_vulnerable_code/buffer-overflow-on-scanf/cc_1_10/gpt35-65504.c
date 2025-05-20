//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
struct process{
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
void fcfs(struct process p[],int n);
void sjf(struct process p[],int n);
void rr(struct process p[],int n);

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process p[n];
    int i;
    printf("\nEnter the details of the processes\n");
    for(i=0;i<n;i++){
        printf("Process %d: ",i+1);
        scanf("%d",&p[i].burst_time);
        p[i].id=i+1;
    }
    fcfs(p,n);
    sjf(p,n);
    rr(p,n);
    return 0;
}

void fcfs(struct process p[],int n){
    printf("\nFirst Come First Serve\n");
    int i;
    float avg_waiting_time=0,avg_turnaround_time=0;
    p[0].waiting_time=0;
    p[0].turnaround_time=p[0].burst_time;
    for(i=1;i<n;i++){
        p[i].waiting_time=p[i-1].turnaround_time;
        p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
    }
    for(i=0;i<n;i++){
        avg_waiting_time+=p[i].waiting_time;
        avg_turnaround_time+=p[i].turnaround_time;
        printf("Process %d: Waiting Time=%d,Turnaround Time=%d\n",p[i].id,p[i].waiting_time,p[i].turnaround_time);
    }
    printf("Average Waiting Time=%f, Average Turnaround Time=%f\n",(float)avg_waiting_time/n,(float)avg_turnaround_time/n);
}

void sjf(struct process p[],int n){
    printf("\nShortest Job First\n");
    int i,j,temp;
    float avg_waiting_time=0,avg_turnaround_time=0;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].burst_time>p[j+1].burst_time){
                temp=p[j].burst_time;
                p[j].burst_time=p[j+1].burst_time;
                p[j+1].burst_time=temp;
                temp=p[j].id;
                p[j].id=p[j+1].id;
                p[j+1].id=temp;
            }
        }
    }
    p[0].waiting_time=0;
    p[0].turnaround_time=p[0].burst_time;
    for(i=1;i<n;i++){
        p[i].waiting_time=p[i-1].turnaround_time;
        p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
    }
    for(i=0;i<n;i++){
        avg_waiting_time+=p[i].waiting_time;
        avg_turnaround_time+=p[i].turnaround_time;
        printf("Process %d: Waiting Time=%d,Turnaround Time=%d\n",p[i].id,p[i].waiting_time,p[i].turnaround_time);
    }
    printf("Average Waiting Time=%f, Average Turnaround Time=%f\n",(float)avg_waiting_time/n,(float)avg_turnaround_time/n);
}

void rr(struct process p[],int n){
    printf("\nRound Robin\n");
    int quantum,t,i,j;
    printf("\nEnter the time quantum: ");
    scanf("%d",&quantum);
    int remaining_times[n];
    for(i=0;i<n;i++){
        remaining_times[i]=p[i].burst_time;
    }
    int complete=0,time=0;
    float avg_waiting_time=0,avg_turnaround_time=0;
    while(1){
        int flag=1;
        for(i=0;i<n;i++){
            if(remaining_times[i]>0){
                flag=0;
                if(remaining_times[i]>quantum){
                    time+=quantum;
                    remaining_times[i]-=quantum;
                }
                else{
                    time+=remaining_times[i];
                    p[i].waiting_time=time-p[i].burst_time;
                    remaining_times[i]=0;
                }
            }
            if(remaining_times[i]==0 && p[i].turnaround_time==0){
                p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
            }
        }
        if(flag==1){
            break;
        }
    }
    for(i=0;i<n;i++){
        avg_waiting_time+=p[i].waiting_time;
        avg_turnaround_time+=p[i].turnaround_time;
        printf("Process %d: Waiting Time=%d,Turnaround Time=%d\n",p[i].id,p[i].waiting_time,p[i].turnaround_time);
    }
    printf("Average Waiting Time=%f, Average Turnaround Time=%f\n",(float)avg_waiting_time/n,(float)avg_turnaround_time/n);
}