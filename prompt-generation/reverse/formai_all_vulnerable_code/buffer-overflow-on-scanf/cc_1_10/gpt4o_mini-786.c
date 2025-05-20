//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remainingBurst[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remainingBurst[i] = processes[i].burstTime;
        processes[i].waitingTime = 0;
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remainingBurst[i] > 0) {
                done = 0; 
                if (remainingBurst[i] > quantum) {
                    time += quantum;
                    remainingBurst[i] -= quantum;
                } else {
                    time += remainingBurst[i];
                    processes[i].waitingTime = time - processes[i].burstTime;
                    remainingBurst[i] = 0;
                }
            }
        }
        if (done) break;
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void printGanttChart(Process processes[], int n) {
    printf("\n\nGantt Chart:\n");
    int time = 0;
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].id);
        time += processes[i].burstTime;
    }
    printf("|\nTime: 0");
    time = 0;
    for (int i = 0; i < n; i++) {
        time += processes[i].burstTime;
        printf("    %d", time);
    }
    printf("\n");
}

void printProcessDetails(Process processes[], int n) {
    printf("\nProcess Details:\n");
    printf("ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

int main() {
    printf("Welcome to the Cheerful CPU Scheduling Simulator!\n");
    
    int n, quantum;

    printf("How many processes do we have today? (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n < 1 || n > MAX_PROCESSES) {
        printf("Please enter a valid number of processes between 1 and %d!\n", MAX_PROCESSES);
        return 1;
    }

    Process processes[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
    }

    printf("Great! Now, please enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printGanttChart(processes, n);
    printProcessDetails(processes, n);

    printf("Thank you for using the Cheerful CPU Scheduling Simulator! Keep smiling!\n");

    return 0;
}