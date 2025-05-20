//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

void main() {
    int n, i, j, k, count=0, timeQuant, sum=0, waitingTime=0, turnaroundTime=0;
    int *burstTime, *remainingTime, *waiting, *turnaround, *processes;

    printf("***Welcome to a new CPU Scheduling Algorithm***\n");
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    burstTime = (int*)malloc(sizeof(int)*n);
    remainingTime = (int*)malloc(sizeof(int)*n);
    waiting = (int*)malloc(sizeof(int)*n);
    turnaround = (int*)malloc(sizeof(int)*n);
    processes = (int*)malloc(sizeof(int)*n);

    printf("\nEnter the Burst Time for each process-\n");
    for(i=0; i<n; i++){
        printf("Process[%d]: ", i+1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
        processes[i] = i+1;
    }

    printf("\nEnter the Time Quantum: ");
    scanf("%d", &timeQuant);

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(burstTime[i]>burstTime[j]){
                k = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = k;

                k = processes[i];
                processes[i] = processes[j];
                processes[j] = k;
            }
        }
    }

    printf("\nHere's the Quantum Round Robin Algorithm-\n\n");
    i=0;
    while(count!=n){
        if(remainingTime[i]<=timeQuant && remainingTime[i]>0){
            sum+=remainingTime[i];
            remainingTime[i]=0;
            count++;
            turnaround[count-1] = sum;
            waiting[count-1] = sum-burstTime[i];
        }
        else if(remainingTime[i]>0){
            remainingTime[i]-=timeQuant;
            sum+=timeQuant;
        }
        if(i==n-1)
            i=0;
        else if(processes[i+1]<=sum)
            i++;
        else
            i=0;
    }

    printf("Process\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("P[%d]\t\t%d\t\t\t%d\t\t\t%d\n", i+1, burstTime[i], waiting[i], turnaround[i]);
        waitingTime+=waiting[i];
        turnaroundTime+=turnaround[i];
    }
    printf("\nAverage Waiting Time: %f\nAverage Turnaround Time: %f\n", (float)waitingTime/n, (float)turnaroundTime/n);

    free(burstTime);
    free(remainingTime);
    free(waiting);
    free(turnaround);
    free(processes);
}