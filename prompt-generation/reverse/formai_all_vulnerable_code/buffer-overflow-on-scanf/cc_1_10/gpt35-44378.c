//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>

//Defining the process structure
typedef struct process{
    int processId;
    int arrivalTime;
    int burstTime;
    int priority;
}Process;

//Function to sort processes according to their arrival time
void sortByArrivalTime(Process processes[], int n){
    Process temp;
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(processes[j].arrivalTime<processes[i].arrivalTime){
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

//Function to implement the Priority scheduling algorithm
void priorityScheduling(Process processes[], int n){
    int i, j, totalWaitingTime = 0, totalCompletionTime = 0;
    float avgWaitingTime, avgCompletionTime;
    int burstTime[n], waitingTime[n], completionTime[n], turnaroundTime[n];
    sortByArrivalTime(processes, n);
    for(i=0; i<n; i++){
        burstTime[i] = processes[i].burstTime;
        waitingTime[i] = 0;
        completionTime[i] = 0;
        turnaroundTime[i] = 0;
    }
    for(i=0; i<n; i++){
        int highestPriority = -9999, highestPriorityIndex = 0;
        for(j=0; j<n; j++){
            if(processes[j].arrivalTime<=i){
                if(processes[j].priority>highestPriority && burstTime[j]>0){
                    highestPriority = processes[j].priority;
                    highestPriorityIndex = j;
                }
            }
        }
        burstTime[highestPriorityIndex] -= 1;
        if(burstTime[highestPriorityIndex] == 0){
            completionTime[highestPriorityIndex] = i+1;
            turnaroundTime[highestPriorityIndex] = completionTime[highestPriorityIndex] - processes[highestPriorityIndex].arrivalTime;
            waitingTime[highestPriorityIndex] = turnaroundTime[highestPriorityIndex] - processes[highestPriorityIndex].burstTime;
        }
    }
    printf("Process\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(i=0; i<n; i++){
        totalWaitingTime += waitingTime[i];
        totalCompletionTime += completionTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].arrivalTime, processes[i].burstTime, waitingTime[i], turnaroundTime[i], completionTime[i]);
    }
    avgWaitingTime = (float)totalWaitingTime/(float)n;
    avgCompletionTime = (float)totalCompletionTime/(float)n;
    printf("Average Waiting Time: %f\n", avgWaitingTime);
    printf("Average Completion Time: %f\n", avgCompletionTime);
}

//Driver Code
void main(){
    int i, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process processes[n];
    for(i=0; i<n; i++){
        printf("Enter the arrival time, burst time and priority of process %d: ", i+1);
        scanf("%d%d%d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);
        processes[i].processId = i+1;
    }
    priorityScheduling(processes, n);
}