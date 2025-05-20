//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef struct {
    int id;
    int burstTime;
    int remainingTime;
    int waitTime;
    int turnAroundTime;
} Process;

// Function prototypes
void fcfsScheduling(Process processes[], int n);
void sjfScheduling(Process processes[], int n);
void roundRobinScheduling(Process processes[], int n);
void calculateTimes(Process processes[], int n);
void printProcesses(Process processes[], int n);

int main() {
    Process processes[MAX_PROCESSES];
    int n, i, choice;

    printf("Welcome to the Exciting CPU Scheduling Simulator! 🎉\n");
    printf("How many processes do you have? (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("That's too many processes! Let's stick to %d.\n", MAX_PROCESSES);
        n = MAX_PROCESSES;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitTime = 0;
        processes[i].turnAroundTime = 0;
    }

    printf("Choose a scheduling algorithm:\n");
    printf("1. First-Come-First-Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n🚀 Running First-Come-First-Serve Scheduling!\n");
            fcfsScheduling(processes, n);
            break;
        case 2:
            printf("\n🚀 Running Shortest Job First Scheduling!\n");
            sjfScheduling(processes, n);
            break;
        case 3:
            printf("\n🚀 Running Round Robin Scheduling!\n");
            roundRobinScheduling(processes, n);
            break;
        default:
            printf("Invalid choice! Please run the program again with a correct option.\n");
            exit(1);
    }

    printf("\n🎊 Process scheduling completed! 🎊\n");
    printProcesses(processes, n);

    return 0;
}

void fcfsScheduling(Process processes[], int n) {
    int totalWaitTime = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waitTime = processes[i - 1].waitTime + processes[i - 1].burstTime;
        totalWaitTime += processes[i].waitTime;
    }
    calculateTimes(processes, n);
}

void sjfScheduling(Process processes[], int n) {
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    fcfsScheduling(processes, n);
}

void roundRobinScheduling(Process processes[], int n) {
    int totalWaitTime = 0;
    int time = 0;
    int remainingProcesses = n;

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    processes[i].remainingTime -= TIME_QUANTUM;
                } else {
                    time += processes[i].remainingTime;
                    processes[i].waitTime = time - processes[i].burstTime;
                    processes[i].remainingTime = 0;
                    remainingProcesses--;
                }
            }
        }
    }
    calculateTimes(processes, n);
}

void calculateTimes(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitTime;
    }
}

void printProcesses(Process processes[], int n) {
    printf("\n Process ID | Burst Time | Waiting Time | Turnaround Time\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("     %d     |     %d      |      %d      |        %d\n",
               processes[i].id, processes[i].burstTime,
               processes[i].waitTime, processes[i].turnAroundTime);
    }
    printf("--------------------------------------------------------\n");
}