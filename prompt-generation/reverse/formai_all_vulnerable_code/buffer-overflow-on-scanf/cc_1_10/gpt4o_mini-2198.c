//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct {
    char name[30];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process proc[], int n) {
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i-1].waiting_time + proc[i-1].burst_time;
    }
}

void calculate_turnaround_time(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void print_processes(Process proc[], int n) {
    printf("\nProcess\tPriority\tBurst_time\tWaiting_time\tTurnaround_time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].name, proc[i].priority,
               proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("In fair Verona, where we lay our scene,\n");
    printf("Enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n < 1 || n > MAX_PROCESSES) {
        printf("Alas! The number of processes must be from 1 to %d.\n", MAX_PROCESSES);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter the priority of %s: ", processes[i].name);
        scanf("%d", &processes[i].priority);
        printf("Enter the burst time of %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);
    }

    // Invoke process ordering with a flourish
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
    print_processes(processes, n);

    printf("\nThus, we dance the dance of optimization,\n");
    printf("Let each process bloom and shine, without delay,\n");
    printf("In the realm of Linux, beneath the starry rays.\n");

    for (int i = 0; i < n; i++) {
        printf("Process %s hath finished, leaving grace in its wake.\n", processes[i].name);
    }

    return 0;
}