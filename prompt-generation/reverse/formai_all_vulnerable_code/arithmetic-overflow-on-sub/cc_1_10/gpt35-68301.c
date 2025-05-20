//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#define QUANTUM 4

struct Process{
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void roundRobin(struct Process* p,int n){
    int i,j=0,time=0,left=n;
    int* flag=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        flag[i]=0;
    while(left){
        if(p[j].remaining_time>QUANTUM && !flag[j]){
            time+=QUANTUM;
            p[j].remaining_time-=QUANTUM;
            if(p[j].remaining_time==0){
                left--;
                flag[j]=1;
                p[j].completion_time=time;
                p[j].turnaround_time=p[j].completion_time-p[j].arrival_time;
                p[j].waiting_time=p[j].turnaround_time-p[j].burst_time;
            }
            j=(j+1)%n;
        }
        else if(p[j].remaining_time<=QUANTUM && !flag[j]){
            time+=p[j].remaining_time;
            p[j].remaining_time=0;
            left--;
            flag[j]=1;
            p[j].completion_time=time;
            p[j].turnaround_time=p[j].completion_time-p[j].arrival_time;
            p[j].waiting_time=p[j].turnaround_time-p[j].burst_time;
            j=(j+1)%n;
        }
        else{
            j=(j+1)%n;
        }
    }
    free(flag);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turnaround_time,p[i].waiting_time);
    printf("\nAverage Turnaround Time: ");
    float sum=0;
    for(i=0;i<n;i++)
        sum+=p[i].turnaround_time;
    printf("%.2f\n",sum/n);
    printf("Average Waiting Time: ");
    sum=0;
    for(i=0;i<n;i++)
        sum+=p[i].waiting_time;
    printf("%.2f\n",sum/n);
}

int main(){
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct Process* p=malloc(n*sizeof(struct Process));
    printf("Enter the process details: \n");
    for(i=0;i<n;i++){
        printf("Process %d:\n",i+1);
        p[i].pid=i+1;
        printf("\tArrival Time: ");
        scanf("%d",&p[i].arrival_time);
        printf("\tBurst Time: ");
        scanf("%d",&p[i].burst_time);
        p[i].remaining_time=p[i].burst_time;
        printf("-------------------------\n");
    }
    roundRobin(p,n);
    free(p);
    return 0;
}