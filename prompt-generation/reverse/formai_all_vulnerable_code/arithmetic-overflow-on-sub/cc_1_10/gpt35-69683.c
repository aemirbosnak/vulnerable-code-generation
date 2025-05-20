//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct process{
    int id;
    int arrival;
    int burst;
    int priority;
    int temp;
    int waiting;
    int turnaround;
}p[MAX];

int n;
int time_quantum;

void input(){
    int i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nProcess [P%d]:\n",i+1);
        p[i].id=i+1;
        printf("Arrival Time: ");
        scanf("%d",&p[i].arrival);
        printf("Burst Time: ");
        scanf("%d",&p[i].burst);
        printf("Priority: ");
        scanf("%d",&p[i].priority);
    }
}

void sortArrival(){
    int i,j;
    struct process temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].arrival>p[j].arrival){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

void executeRoundRobin(){
    int i,j,k;
    int time=0;
    int r_index=-1;
    int total_burst=0;
    int queue[MAX];
    int qsize=0;

    for(i=0;i<n;i++){
        total_burst+=p[i].burst;
        p[i].temp=p[i].burst;
    }

    while(time<total_burst){
        for(i=0;i<n;i++){
            if(p[i].arrival==time){
                queue[qsize++]=i;
            }
        }

        if(r_index==-1){
            r_index=queue[0];
            for(j=0;j<qsize-1;j++){
                queue[j]=queue[j+1];
            }
            qsize--;
        }

        if(p[r_index].temp>time_quantum){
            p[r_index].temp-=time_quantum;
            time+=time_quantum;
            for(i=0;i<n;i++){
                if(p[i].arrival<=time && p[r_index].id!=p[i].id && p[i].temp>0){
                    queue[qsize++]=i;
                }
            }
            queue[qsize++]=r_index;
        }
        else{
            time+=p[r_index].temp;
            p[r_index].temp=0;
            p[r_index].waiting=time-p[r_index].burst-p[r_index].arrival;
            p[r_index].turnaround=time-p[r_index].arrival;

            for(i=0;i<n;i++){
                if(p[i].arrival<=time && p[r_index].id!=p[i].id && p[i].temp>0){
                    queue[qsize++]=i;
                }
            }
        }
        r_index=queue[0];
        for(k=0;k<qsize-1;k++){
            queue[k]=queue[k+1];
        }
        qsize--;
    }
}

void display(){
    int i;
    float avg_waiting, avg_turnaround;
    printf("\n\nProcess    Arrival Time    Burst Time    Priority    Waiting Time    Turnaround Time\n");
    for(i=0;i<n;i++){
        printf("  P[%d]          %d             %d             %d              %d                 %d\n",p[i].id,p[i].arrival,p[i].burst,p[i].priority,p[i].waiting,p[i].turnaround);
    }

    avg_waiting=0.0;
    avg_turnaround=0.0;

    for(i=0;i<n;i++){
        avg_waiting+=p[i].waiting;
        avg_turnaround+=p[i].turnaround;
    }

    avg_waiting/=n;
    avg_turnaround/=n;

    printf("\nAverage Waiting Time: %.2f",avg_waiting);
    printf("\nAverage Turnaround Time: %.2f",avg_turnaround);
}

int main(){
    printf("------------------------------CPU SCHEDULING ALGORITHMS------------------------------\n\n");
    printf("ROUND ROBIN CPU SCHEDULING ALGORITHM\n");

    printf("\nEnter the Time Quantum: ");
    scanf("%d",&time_quantum);

    input();
    sortArrival();
    executeRoundRobin();
    display();

    return 0;
}