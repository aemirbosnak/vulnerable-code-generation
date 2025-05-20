//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;     // Process ID
    int bt;     // Burst Time
    int at;     // Arrival Time
} Process;

void findWaitingTime(Process proc[], int n, int wt[], int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = proc[i].bt;

    int t = 0; // Current time
    while (1) {
        int done = 1; // Check if all processes are done
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // If at least one process is still remaining
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    wt[i] = t - proc[i].bt - proc[i].at; // Waiting time calculation
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1) break; // All processes finished
    }
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i]; // Turnaround time = Burst time + Waiting time
}

void findavgTime(Process proc[], int n, int quantum) {
    int wt[n], tat[n];
    findWaitingTime(proc, n, wt, quantum);
    findTurnAroundTime(proc, n, wt, tat);

    float total_wt = 0, total_tat = 0;
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].bt, proc[i].at, wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

void fcfs(Process proc[], int n) {
    int wt[n], tat[n];
    wt[0] = 0; // Waiting time for the first process is always 0

    for (int i = 1; i < n; i++) {
        wt[i] = proc[i - 1].bt + wt[i - 1]; // Calculate waiting time
    }
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i]; // Calculate turnaround time
    }

    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].bt, proc[i].at, wt[i], tat[i]);
    }
}

int compare(const void *a, const void *b) {
    return ((Process *)a)->bt - ((Process *)b)->bt; // For SJF
}

void sjf(Process proc[], int n) {
    qsort(proc, n, sizeof(Process), compare);
    fcfs(proc, n); // Use FCFS after sorting by burst time
}

int main() {
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
        scanf("%d %d", &proc[i].bt, &proc[i].at);
    }

    printf("Choose Scheduling Algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nApplying FCFS Scheduling...\n");
            fcfs(proc, n);
            break;
        case 2:
            printf("\nApplying SJF Scheduling...\n");
            sjf(proc, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            printf("\nApplying Round Robin Scheduling...\n");
            findavgTime(proc, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}