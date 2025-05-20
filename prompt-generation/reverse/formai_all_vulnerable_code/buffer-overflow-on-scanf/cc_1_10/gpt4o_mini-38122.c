//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int arrival_time;
};

void findWaitingTime(struct Process processes[], int n, int wt[], int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    int t = 0; // Current time
    bool done = false;

    while (true) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && processes[i].arrival_time <= t) {
                done = false; // Found a process that needs execution

                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    wt[i] = t - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if (done) {
            break; // All processes are done
        }
    }
}

void findTurnAroundTime(struct Process processes[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = processes[i].burst_time + wt[i];
    }
}

void findavgTime(struct Process processes[], int n, int quantum) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];

    findWaitingTime(processes, n, wt, quantum);
    findTurnAroundTime(processes, n, wt, tat);

    printf("Process\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", 
                processes[i].id, 
                processes[i].burst_time, 
                wt[i], 
                tat[i]);
    }
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].remaining_time = processes[i].burst_time; // Initial remaining time is the burst time
    }

    printf("Enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    findavgTime(processes, n, quantum);

    return 0;
}