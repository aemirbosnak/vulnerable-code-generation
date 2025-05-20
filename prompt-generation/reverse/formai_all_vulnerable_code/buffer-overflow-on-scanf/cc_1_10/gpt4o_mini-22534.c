//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 5

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int priority;
    int arrival_time;
} Process;

void display(Process processes[], int n);
void roundRobin(Process processes[], int n);
void inputProcesses(Process processes[], int n);
void sortProcessesByArrival(Process processes[], int n);
int areAllProcessesDone(Process processes[], int n);

int main() {
    printf("----------------------------------------------------\n");
    printf("         Welcome to the Cyberpunk CPU Scheduler!   \n");
    printf("----------------------------------------------------\n");

    int n;
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if(n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];
    inputProcesses(processes, n);
    sortProcessesByArrival(processes, n);
    
    printf("\nProcesses:\n");
    display(processes, n);

    printf("\nExecuting Round Robin Scheduling...\n");
    roundRobin(processes, n);

    printf("----------------------------------------------------\n");

    return 0;
}

void inputProcesses(Process processes[], int n) {
    srand(time(0));
    for(int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].burst_time = rand() % 20 + 1; // Random burst time between 1 and 20
        processes[i].arrival_time = rand() % 5; // Random arrival time between 0 and 5
        processes[i].remaining_time = processes[i].burst_time;  // Initialize remaining time
        processes[i].priority = rand() % 5; // Random Priority for Extra Cyberpunk Style
    }
}

void display(Process processes[], int n) {
    printf("ID\tBurst Time\tArrival Time\tRemaining Time\tPriority\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].burst_time, processes[i].arrival_time,
               processes[i].remaining_time, processes[i].priority);
    }
}

void roundRobin(Process processes[], int n) {
    int time = 0;
    int wait_time = 0, total_waiting_time = 0;
    while (!areAllProcessesDone(processes, n)) {
        for(int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                printf("Time %d: Process %d is executing...\n", time, processes[i].id);

                // Execution logic
                if (processes[i].remaining_time > TIME_QUANTUM) {
                    // Process will not finish in this time quantum
                    processes[i].remaining_time -= TIME_QUANTUM;
                    time += TIME_QUANTUM;
                } else {
                    // Process finishes
                    time += processes[i].remaining_time;
                    wait_time = time - processes[i].burst_time - processes[i].arrival_time;
                    total_waiting_time += wait_time;

                    printf("Time %d: Process %d finished execution.\n", time, processes[i].id);
                    processes[i].remaining_time = 0;
                }
            }
        }
    }
    printf("\nAverage Wait Time: %.2f\n", (float)total_waiting_time / n);
}

void sortProcessesByArrival(Process processes[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int areAllProcessesDone(Process processes[], int n) {
    for(int i = 0; i < n; i++) {
        if (processes[i].remaining_time > 0) {
            return 0; // Not all processes are done
        }
    }
    return 1; // All processes are done
}