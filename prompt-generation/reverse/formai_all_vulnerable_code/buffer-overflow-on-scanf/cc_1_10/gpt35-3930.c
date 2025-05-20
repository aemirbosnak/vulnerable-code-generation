//FormAI DATASET v1.0 Category: System administration ; Style: innovative
// This is a program that simulates a task manager
// It allows the user to view, kill, and prioritize running processes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    char name[20];
    int priority;
    int running;
};

struct Process runningProcesses[MAX_PROCESSES];
int numProcesses = 0;

void addProcess() {
    if (numProcesses >= MAX_PROCESSES) {
        printf("Unable to add process. Too many processes running.\n");
        return;
    }

    struct Process newProcess;
    printf("Enter the process name: ");
    scanf("%s", newProcess.name);
    printf("Enter the process priority: ");
    scanf("%d", &newProcess.priority);

    newProcess.pid = numProcesses;
    newProcess.running = 1;

    runningProcesses[numProcesses] = newProcess;
    numProcesses++;
}

void viewProcesses() {
    printf("PID\tName\tPriority\tRunning\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%s\t%d\t\t%s\n", runningProcesses[i].pid, runningProcesses[i].name, runningProcesses[i].priority, runningProcesses[i].running ? "Yes" : "No");
    }
}

void killProcess() {
    int pid;
    printf("Enter the PID of the process you want to kill: ");
    scanf("%d", &pid);

    for (int i = 0; i < numProcesses; i++) {
        if (runningProcesses[i].pid == pid) {
            runningProcesses[i].running = 0;
            return;
        }
    }

    printf("Process with PID %d not found.\n", pid);
}

void prioritizeProcess() {
    int pid, newPriority;
    printf("Enter the PID of the process you want to prioritize: ");
    scanf("%d", &pid);
    printf("Enter the new priority: ");
    scanf("%d", &newPriority);

    for (int i = 0; i < numProcesses; i++) {
        if (runningProcesses[i].pid == pid) {
            runningProcesses[i].priority = newPriority;
            return;
        }
    }

    printf("Process with PID %d not found.\n", pid);
}

int main() {
    int choice = 0;
    while (choice != 5) {
        printf("\nTask Manager\n");
        printf("1. Add Process\n");
        printf("2. View Processes\n");
        printf("3. Kill Process\n");
        printf("4. Prioritize Process\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProcess();
                break;
            case 2:
                viewProcesses();
                break;
            case 3:
                killProcess();
                break;
            case 4:
                prioritizeProcess();
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice.\n");
                break;
        }
    }

    printf("Exiting Task Manager.\n");

    return 0;
}