//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void printProcess(Process p) {
    printf("🎉 Process %d | Burst Time: %d | Waiting Time: %d | Turnaround Time: %d\n", 
           p.id, p.burstTime, p.waitingTime, p.turnaroundTime);
}

void calculateWaitingTimeFCFS(Process processes[], int n) {
    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void calculateTurnaroundTimeFCFS(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void fcfsScheduling(Process processes[], int n) {
    printf("✨ First-Come-First-Serve Scheduling! 🎊\n");
    calculateWaitingTimeFCFS(processes, n);
    calculateTurnaroundTimeFCFS(processes, n);

    printf("\nHere are the results:\n");
    for (int i = 0; i < n; i++) {
        printProcess(processes[i]);
    }
}

void sjfScheduling(Process processes[], int n) {
    printf("✨ Shortest Job First Scheduling! 🎊\n");
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    calculateWaitingTimeFCFS(processes, n);
    calculateTurnaroundTimeFCFS(processes, n);
    
    printf("\nHere are the results:\n");
    for (int i = 0; i < n; i++) {
        printProcess(processes[i]);
    }
}

void roundRobinScheduling(Process processes[], int n, int quantum) {
    printf("✨ Round Robin Scheduling! 🎊\n");
    int remainingBurst[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remainingBurst[i] = processes[i].burstTime;
    }

    int time = 0;
    while (1) {
        int done = 1; // Flag to check if all processes are done
        for (int i = 0; i < n; i++) {
            if (remainingBurst[i] > 0) {
                done = 0; // There are more processes
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

    calculateTurnaroundTimeFCFS(processes, n);
    
    printf("\nHere are the results:\n");
    for (int i = 0; i < n; i++) {
        printProcess(processes[i]);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("🎈 Welcome to the CPU Scheduling Simulator! 🎈\n");
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
    }

    printf("\n*** Choose a scheduling algorithm ***\n");
    printf("1. First-Come-First-Serve\n");
    printf("2. Shortest Job First\n");
    printf("3. Round Robin\n");
    int choice;
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        fcfsScheduling(processes, n);
    } else if (choice == 2) {
        sjfScheduling(processes, n);
    } else if (choice == 3) {
        printf("Enter time quantum for Round Robin: ");
        scanf("%d", &quantum);
        roundRobinScheduling(processes, n, quantum);
    } else {
        printf("🚫 Invalid choice! Please restart the program. 🚫\n");
    }

    printf("🎉 Thank you for using the CPU Scheduling Simulator! Goodbye! 🎊\n");
    return 0;
}