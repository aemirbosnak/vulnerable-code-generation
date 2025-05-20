//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdio.h>
#define SIZE 100
#define QUANTUM 2

int burstTime[SIZE];//global array to store the list of burst times of processes
int waitingTime[SIZE];//global array to store the waiting times of processes
int turnAroundTime[SIZE];//global array to store the turn around times of processes
int arrivalTime[SIZE];//global array to store the arrival times of processes
int n;//number of processes

void roundRobin(){
    int remainingTime[n];//local array to store the remaining burst time of each process
    int time=0;//current time
    int flag=0;//flag to check if any process is still left
    int i;

    for(i=0;i<n;i++){
        remainingTime[i]=burstTime[i];
    }

    while(1){
        flag=0;

        for(i=0;i<n;i++){
            if(remainingTime[i]>0){
                flag=1;//if any process is left, set flag to 1
                if(remainingTime[i]>QUANTUM){
                    time+=QUANTUM;
                    remainingTime[i]-=QUANTUM;//if remaining time>QUANTUM, then subtract QUANTUM
                }
                else{
                    time+=remainingTime[i];
                    waitingTime[i]=time-burstTime[i]-arrivalTime[i];//calculate waiting time
                    remainingTime[i]=0;
                }
            }
        }

        if(flag==0){//if no process is left, break the while loop
            break;
        }
    }
}

void calculateTurnAroundTime(){
    int i;

    for(i=0;i<n;i++){
        turnAroundTime[i]=burstTime[i]+waitingTime[i];//turn around time=burst time+waiting time
    }
}

void calculateWaitingTime(){
    int i;

    waitingTime[0]=0;//waiting time of first process is always 0

    for(i=1;i<n;i++){
        waitingTime[i]=waitingTime[i-1]+burstTime[i-1];//waiting time of a process=sum of burst time of previous processes
    }
}

void print(){
    int i;

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");

    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,burstTime[i],arrivalTime[i],waitingTime[i],turnAroundTime[i]);
    }
}

int main(){
    int i;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter burst time of each process: ");
    for(i=0;i<n;i++){
        scanf("%d",&burstTime[i]);
    }

    printf("Enter arrival time of each process: ");
    for(i=0;i<n;i++){
        scanf("%d",&arrivalTime[i]);
    }

    roundRobin();
    calculateWaitingTime();
    calculateTurnAroundTime();
    print();

    return 0;
}