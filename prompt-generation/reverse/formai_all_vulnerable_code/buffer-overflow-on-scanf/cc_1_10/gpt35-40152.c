//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1000

int arrivalTime[MAX_PROCESSES], burstTime[MAX_PROCESSES], waitingTime[MAX_PROCESSES];

void FCFS(int numberOfProcesses) {
    float averageWaitingTime = 0;
    int currentTime = 0;
    for(int i=0; i<numberOfProcesses; i++) {
        if(currentTime<arrivalTime[i]) {
            currentTime = arrivalTime[i];
        }
        waitingTime[i] = currentTime-arrivalTime[i];
        averageWaitingTime += waitingTime[i];
        currentTime += burstTime[i];
    }
    printf("Average Waiting Time (FCFS): %.2f\n", averageWaitingTime/numberOfProcesses);
}

void SJF(int numberOfProcesses) {
    float averageWaitingTime = 0;
    int copyBurstTime[MAX_PROCESSES], completedProcesses = 0, currentTime = 0;
    memcpy(copyBurstTime, burstTime, sizeof(copyBurstTime));
    while(completedProcesses!=numberOfProcesses) {
        int shortestIndex = -1, shortestBurstTime = MAX_PROCESSES;
        for(int i=0; i<numberOfProcesses; i++) {
            if(arrivalTime[i]<=currentTime && copyBurstTime[i]<shortestBurstTime && copyBurstTime[i]>0) {
                shortestIndex = i;
                shortestBurstTime = copyBurstTime[i];
            }
        }
        if(shortestIndex==-1) {
            currentTime++;
            continue;
        }
        waitingTime[shortestIndex] = currentTime-arrivalTime[shortestIndex];
        averageWaitingTime += waitingTime[shortestIndex];
        currentTime += copyBurstTime[shortestIndex];
        copyBurstTime[shortestIndex] = 0;
        completedProcesses++;
    }
    printf("Average Waiting Time (SJF): %.2f\n", averageWaitingTime/numberOfProcesses);
}

void SRTF(int numberOfProcesses) {
    float averageWaitingTime = 0;
    int copyBurstTime[MAX_PROCESSES], completedProcesses = 0, currentTime = 0, shortestIndex = -1;
    memcpy(copyBurstTime, burstTime, sizeof(copyBurstTime));
    while(completedProcesses!=numberOfProcesses) {
        for(int i=0; i<numberOfProcesses; i++) {
            if(arrivalTime[i]<=currentTime && copyBurstTime[i]>0 && (shortestIndex==-1 || copyBurstTime[i]<copyBurstTime[shortestIndex])) {
                shortestIndex = i;
            }
        }
        if(shortestIndex==-1) {
            currentTime++;
            continue;
        }
        copyBurstTime[shortestIndex]--;
        if(copyBurstTime[shortestIndex]==0) {
            completedProcesses++;
            waitingTime[shortestIndex] = currentTime-arrivalTime[shortestIndex]-burstTime[shortestIndex]+1;
            averageWaitingTime += waitingTime[shortestIndex];
            shortestIndex = -1;
        }
        currentTime++;
    }
    printf("Average Waiting Time (SRTF): %.2f\n", averageWaitingTime/numberOfProcesses);
}

void executeCPUAlgorithm(int numberOfProcesses, char algorithm[]) {
    if(strcmp(algorithm, "FCFS")==0) {
        FCFS(numberOfProcesses);
    }
    else if(strcmp(algorithm, "SJF")==0) {
        SJF(numberOfProcesses);
    }
    else if(strcmp(algorithm, "SRTF")==0) {
        SRTF(numberOfProcesses);
    }
    else {
        printf("Invalid Algorithm\n");
    }
}

int main() {
    int numberOfProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);
    printf("Enter Arrival Time and Burst Time (in ms) of Processes:\n");
    for(int i=0; i<numberOfProcesses; i++) {
        printf("Process %d (AT BT): ", i+1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }
    char algorithm[10];
    printf("Enter CPU Scheduling Algorithm (FCFS/SJF/SRTF): ");
    scanf("%s", algorithm);
    executeCPUAlgorithm(numberOfProcesses, algorithm);
    return 0;
}