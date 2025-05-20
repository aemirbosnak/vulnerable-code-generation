//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 20

// Struct for storing information about a process
typedef struct {
    char name[10];
    int arrivalTime;
    int burstTime;
    int remainingTime;
} Process;

// Struct for storing information about a particular time slot in the Gantt chart
typedef struct {
    char processName[10];
    int startTime;
    int endTime;
} TimeSlot;

// Global variables
Process processes[MAX_PROCESSES];
int numProcesses = 0;
int currentTime = 0;
int quantum = 0;
bool processRunning = false;
int runningProcess = -1;
TimeSlot ganttChart[MAX_PROCESSES * 2];
int numTimeSlots = 0;

// Function to add a process to the queue
void addProcess() {
    Process p;
    printf("Enter process name: ");
    scanf("%s", p.name);
    printf("Enter arrival time: ");
    scanf("%d", &p.arrivalTime);
    printf("Enter burst time: ");
    scanf("%d", &p.burstTime);
    p.remainingTime = p.burstTime;
    processes[numProcesses++] = p;
}

// Function to print the Gantt chart
void printGanttChart() {
    printf("\nGantt Chart:\n\n");
    for (int i = 0; i < numTimeSlots; i++) {
        printf("%s\t", ganttChart[i].processName);
    }
    printf("\n");
    for (int i = 0; i < numTimeSlots; i++) {
        printf("%d\t", ganttChart[i].startTime);
    }
    printf("%d\n", ganttChart[numTimeSlots - 1].endTime);
}

// Function to check if all processes have finished executing
bool allProcessesFinished() {
    for (int i = 0; i < numProcesses; i++) {
        if (processes[i].remainingTime > 0) {
            return false;
        }
    }
    return true;
}

// Function to find the next process to run using Round Robin scheduling
// Returns the index of the process to run
int getNextProcessRR() {
    for (int i = 0; i < numProcesses; i++) {
        if (processes[i].remainingTime > 0 && processes[i].arrivalTime <= currentTime) {
            return i;
        }
    }
    return -1;
}

// Function to simulate Round Robin scheduling
void runRR() {
    printf("\n");
    printf("Round Robin Scheduling:\n");
    printf("-----------------------\n\n");
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while (!allProcessesFinished()) {
        int nextProcess = getNextProcessRR();
        if (nextProcess == -1) {
            currentTime++;
            ganttChart[numTimeSlots].startTime = ganttChart[numTimeSlots - 1].endTime;
            ganttChart[numTimeSlots].endTime = currentTime;
            strcpy(ganttChart[numTimeSlots].processName, "--");
            numTimeSlots++;
            continue;
        }
        if (!processRunning) {
            runningProcess = nextProcess;
            processRunning = true;
        }
        if (processes[runningProcess].remainingTime <= quantum) {
            ganttChart[numTimeSlots].startTime = ganttChart[numTimeSlots - 1].endTime;
            currentTime += processes[runningProcess].remainingTime;
            ganttChart[numTimeSlots].endTime = currentTime;
            strcpy(ganttChart[numTimeSlots].processName, processes[runningProcess].name);
            numTimeSlots++;
            processes[runningProcess].remainingTime = 0;
            processRunning = false;
            continue;
        } else {
            ganttChart[numTimeSlots].startTime = ganttChart[numTimeSlots - 1].endTime;
            currentTime += quantum;
            ganttChart[numTimeSlots].endTime = currentTime;
            strcpy(ganttChart[numTimeSlots].processName, processes[runningProcess].name);
            numTimeSlots++;
            processes[runningProcess].remainingTime -= quantum;
            processRunning = false;
        }
    }
    printGanttChart();
}

// Main function
int main() {
    char choice = ' ';
    while (choice != 'n') {
        printf("Current Time: %d\n", currentTime);
        printf("---------------\n\n");
        printf("Enter a choice:\n");
        printf("a) Add a process to the queue\n");
        printf("b) Run Round Robin scheduling\n");
        printf("n) Exit\n");
        printf("\nChoice: ");
        scanf(" %c", &choice);
        printf("\n");
        switch (choice) {
            case 'a':
                if (numProcesses == MAX_PROCESSES) {
                    printf("Maximum number of processes reached.\n");
                } else {
                    addProcess();
                }
                break;
            case 'b':
                runRR();
                break;
            case 'n':
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }

    return 0;
}