//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void findWaitingTimeFCFS(Process processes[], int n) {
    processes[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void findTurnaroundTimeFCFS(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void findWaitingTimeSJN(Process processes[], int n) {
    int completed[MAX_PROCESSES] = {0};
    int completedCount = 0, time = 0;

    while (completedCount < n) {
        int shortestIndex = -1;
        int shortestBurstTime = 9999; // Initialize to a large value

        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].burstTime < shortestBurstTime && processes[i].id <= time) {
                shortestBurstTime = processes[i].burstTime;
                shortestIndex = i;
            }
        }

        if (shortestIndex != -1) {
            processes[shortestIndex].waitingTime = time;
            time += processes[shortestIndex].burstTime;
            completed[shortestIndex] = 1;
            completedCount++;
        } else {
            time++;
        }
    }
}

void findTurnaroundTimeSJN(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void findWaitingTimeRR(Process processes[], int n, int quantum) {
    int remainingBurstTime[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remainingBurstTime[i] = processes[i].burstTime;

    int time = 0;
    bool done;
    while (true) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                done = false;
                if (remainingBurstTime[i] > quantum) {
                    time += quantum;
                    remainingBurstTime[i] -= quantum;
                } else {
                    time = time + remainingBurstTime[i];
                    processes[i].waitingTime = time - processes[i].burstTime;
                    remainingBurstTime[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
}

void findTurnaroundTimeRR(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void display(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%3d\t\t%3d\t\t%3d\t\t%3d\n", processes[i].id, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID starting from 1
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    while (true) {
        printf("\n--- CPU Scheduling Algorithms ---\n");
        printf("1. First-Come, First-Served (FCFS)\n");
        printf("2. Shortest Job Next (SJN)\n");
        printf("3. Round Robin (RR)\n");
        printf("4. Exit\n");
        printf("Select a scheduling algorithm: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findWaitingTimeFCFS(processes, n);
                findTurnaroundTimeFCFS(processes, n);
                display(processes, n);
                break;

            case 2:
                // Sort processes based on burst time for SJN
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (processes[i].burstTime > processes[j].burstTime) {
                            Process temp = processes[i];
                            processes[i] = processes[j];
                            processes[j] = temp;
                        }
                    }
                }
                findWaitingTimeSJN(processes, n);
                findTurnaroundTimeSJN(processes, n);
                display(processes, n);
                break;

            case 3:
                printf("Enter time quantum for Round Robin: ");
                scanf("%d", &quantum);
                findWaitingTimeRR(processes, n, quantum);
                findTurnaroundTimeRR(processes, n);
                display(processes, n);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}