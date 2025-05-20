//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int main() {
    // define variables for process information
    int numProcesses, burstTimes[20], arrivalTimes[20], waitingTimes[20], turnaroundTimes[20];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    // get user input for process information
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);
    printf("\nEnter burst times for each process: \n");
    for(int i = 0; i < numProcesses; i++) {
        printf("Burst time for process %d: ", i+1);
        scanf("%d", &burstTimes[i]);
    }
    printf("\nEnter arrival times for each process: \n");
    for(int i = 0; i < numProcesses; i++) {
        printf("Arrival time for process %d: ", i+1);
        scanf("%d", &arrivalTimes[i]);
    }

    // perform the FCFS scheduling algorithm
    int currentProcess = 0;
    for(int i = 0; i < numProcesses; i++) {
        if(arrivalTimes[i] > currentProcess) { // if next process arrives after current process completes
            currentProcess = arrivalTimes[i];
        }
        waitingTimes[i] = currentProcess - arrivalTimes[i];
        currentProcess += burstTimes[i];
        turnaroundTimes[i] = currentProcess - arrivalTimes[i];
    }

    // calculate average waiting and turnaround times
    for(int i = 0; i < numProcesses; i++) {
        avgWaitingTime += waitingTimes[i];
        avgTurnaroundTime += turnaroundTimes[i];
    }
    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;

    // print out results
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burstTimes[i], arrivalTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }
    printf("\nAverage waiting time: %.2f", avgWaitingTime);
    printf("\nAverage turnaround time: %.2f", avgTurnaroundTime);

    return 0;
}