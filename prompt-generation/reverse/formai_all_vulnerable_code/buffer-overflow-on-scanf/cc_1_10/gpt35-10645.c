//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    int n, burstTime[20], waitingTime[20], turnaroundTime[20], avgWaitTime=0, avgTurnTime=0, i, j, temp, position; 
    
    //Accepting number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    //Accepting the burst time for each process
    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++){
        printf("Process %d: ", i+1);
        scanf("%d", &burstTime[i]);
    }

    //Sorting burst time for SJF
    for(i=0;i<n-1;i++){
        position=i;
        for(j=i+1;j<n;j++){
            if(burstTime[j]<burstTime[position]){
                position=j;
            }
        }
        temp=burstTime[i];
        burstTime[i]=burstTime[position];
        burstTime[position]=temp;
    }

    //Calculating Waiting and Turnaround time for each process
    waitingTime[0]=0;
    for(i=1;i<n;i++){
        waitingTime[i]=0;
        for(j=0;j<i;j++){
            waitingTime[i]+=burstTime[j];
        }
    }
    for(i=0;i<n;i++){
        turnaroundTime[i]=burstTime[i]+waitingTime[i];
    }

    //Printing the results
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("Process %d:\t\t%d\t\t%d\t\t%d\n", i+1, burstTime[i], waitingTime[i], turnaroundTime[i]);
        avgWaitTime+=waitingTime[i];
        avgTurnTime+=turnaroundTime[i];
    }
    printf("Average Waiting Time: %.2f\n", (float)avgWaitTime/n);
    printf("Average Turnaround Time: %.2f\n", (float)avgTurnTime/n);

    return 0;
}