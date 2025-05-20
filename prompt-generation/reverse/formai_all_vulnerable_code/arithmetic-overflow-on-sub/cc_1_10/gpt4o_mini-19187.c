//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void printShocked(const char *msg) {
    printf("\n!! SHOCKING ALERT !! %s\n", msg);
}

void fcfsScheduling(Process processes[], int n) {
    printShocked("Running First-Come-First-Served Scheduling!");

    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    printf("\nFCFS Scheduling Results:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void sjnScheduling(Process processes[], int n) {
    printShocked("Oh no! Time to find the Shortest Job Next!");

    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    printf("\nSJN Scheduling Results:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void roundRobinScheduling(Process processes[], int n) {
    printShocked("Round and Round We Go with Round Robin Scheduling!");

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = 0;  // There is a remaining process

                if (processes[i].remaining_time > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].turnaround_time = time;
                    processes[i].remaining_time = 0;
                }
            }
        }
        if (done) break;
    }

    printf("\nRound Robin Scheduling Results:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printShocked("Welcome to the CPU Scheduling Arena!");
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printShocked("Too many processes! I can't handle them!");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0; // Default
        processes[i].turnaround_time = 0; // Default
    }

    fcfsScheduling(processes, n);
    sjnScheduling(processes, n);
    roundRobinScheduling(processes, n);

    printShocked("All Scheduling Completed! What a ride!");

    return 0;
}