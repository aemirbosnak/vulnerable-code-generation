//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to calculate Average Waiting Time and Average Turnaround Time
void calculateTimes(int processes[], int n, int burstTime[], int arrivalTime[]) {
    int waitingTime[n], turnaroundTime[n], completionTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Calculation of completion time, waiting time, turnaround time
    completionTime[0] = burstTime[0] + arrivalTime[0];
    turnaroundTime[0] = completionTime[0] - arrivalTime[0];
    waitingTime[0] = turnaroundTime[0] - burstTime[0];

    for (int i = 1; i < n; i++) {
        int minimumArrivalTimeIndex = i; // Minimum arrival time of the remaining processes
        for (int j = i; j < n; j++) {
            if (arrivalTime[j] < arrivalTime[minimumArrivalTimeIndex]) {
                minimumArrivalTimeIndex = j;
            }
        }

        int temp = processes[minimumArrivalTimeIndex];
        processes[minimumArrivalTimeIndex] = processes[i];
        processes[i] = temp;

        temp = burstTime[minimumArrivalTimeIndex];
        burstTime[minimumArrivalTimeIndex] = burstTime[i];
        burstTime[i] = temp;

        temp = arrivalTime[minimumArrivalTimeIndex];
        arrivalTime[minimumArrivalTimeIndex] = arrivalTime[i];
        arrivalTime[i] = temp;

        completionTime[i] = completionTime[i - 1] + burstTime[i];
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];

        // Waiting time should not be negative
        if (waitingTime[i] < 0) {
            waitingTime[i] = 0;
        }
    }

    // Calculation of total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Calculation of average waiting time and average turnaround time
    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("Process\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], arrivalTime[i], completionTime[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main() {
    int n, *processes, *burstTime, *arrivalTime;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    processes = (int*)malloc(n * sizeof(int));
    burstTime = (int*)malloc(n * sizeof(int));
    arrivalTime = (int*)malloc(n * sizeof(int));

    printf("Enter the burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        processes[i] = i + 1;
    }

    printf("Enter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
    }

    calculateTimes(processes, n, burstTime, arrivalTime);

    free(processes);
    free(burstTime);
    free(arrivalTime);

    return 0;
}