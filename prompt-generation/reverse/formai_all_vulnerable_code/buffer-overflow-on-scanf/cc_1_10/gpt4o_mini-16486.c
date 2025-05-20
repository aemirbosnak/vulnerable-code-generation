//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateWaitingTime(Process p[], int n, int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++)
        remainingTime[i] = p[i].burstTime;

    int done = 0, t = 0;
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] > quantum) {
                    t += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    t += remainingTime[i];
                    p[i].waitingTime = t - p[i].burstTime;
                    remainingTime[i] = 0;
                    done++;
                }
            }
        }
    }
}

void calculateTurnaroundTime(Process p[], int n) {
    for (int i = 0; i < n; i++)
        p[i].turnaroundTime = p[i].burstTime + p[i].waitingTime;
}

void fcfs(Process p[], int n) {
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++)
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;

    calculateTurnaroundTime(p, n);
}

void sjf(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burstTime > p[j].burstTime) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    fcfs(p, n);
}

void roundRobin(Process p[], int n, int quantum) {
    calculateWaitingTime(p, n, quantum);
    calculateTurnaroundTime(p, n);
}

void displayResults(Process p[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i].processID, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }
}

int main() {
    int n, choice, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *p = (Process *)malloc(n * sizeof(Process));
    
    for (int i = 0; i < n; i++) {
        p[i].processID = i + 1;
        printf("Enter burst time for Process P%d: ", p[i].processID);
        scanf("%d", &p[i].burstTime);
    }

    printf("\nSelect Scheduling Algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            roundRobin(p, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            free(p);
            return 1;
    }

    displayResults(p, n);
    free(p);
    return 0;
}