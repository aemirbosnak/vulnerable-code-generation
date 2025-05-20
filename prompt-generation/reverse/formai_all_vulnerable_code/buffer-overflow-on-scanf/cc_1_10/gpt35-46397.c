//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#define MAX_PROCESSES 10

void printProcess(int processId,char state){
    printf("Process %d is in %c state\n",processId,state);
}

struct Process{
    int id;
    int arrivalTime;
    int burstTime;
    int completeTime;
    int turnAroundTime;
    int waitingTime;
    char state;
}processArray[MAX_PROCESSES];

int main(){
    int n,i,j,currentTime=0;
    float avgWaitingTime=0,avgTurnAroundTime=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter arrival time and burst time of each process:\n");
    for(i=0;i<n;i++){
        processArray[i].id=i+1;
        processArray[i].completeTime=-1;
        processArray[i].state='w';
        scanf("%d%d",&processArray[i].arrivalTime,&processArray[i].burstTime);
    }

    //First Come First Serve Scheduling
    for(i=0;i<n;i++){
        if(currentTime<processArray[i].arrivalTime)
            currentTime=processArray[i].arrivalTime;
        processArray[i].state='r';
        printProcess(processArray[i].id,processArray[i].state);
        processArray[i].completeTime=currentTime+processArray[i].burstTime;
        currentTime=processArray[i].completeTime;
        processArray[i].turnAroundTime=processArray[i].completeTime-processArray[i].arrivalTime;
        processArray[i].waitingTime=processArray[i].turnAroundTime-processArray[i].burstTime;
        avgWaitingTime+=processArray[i].waitingTime;
        avgTurnAroundTime+=processArray[i].turnAroundTime;
        processArray[i].state='f';
        printProcess(processArray[i].id,processArray[i].state);
        printf("\n");
    }

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processArray[i].id,processArray[i].arrivalTime,processArray[i].burstTime,processArray[i].waitingTime,processArray[i].turnAroundTime);
    }

    printf("Average Waiting Time: %f\n",avgWaitingTime/n);
    printf("Average Turnaround Time: %f\n",avgTurnAroundTime/n);

    return 0;
}