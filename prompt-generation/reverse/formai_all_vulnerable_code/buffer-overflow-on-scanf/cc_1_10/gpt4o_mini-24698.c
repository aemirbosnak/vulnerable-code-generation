//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_NAME_LENGTH 50

typedef struct Process {
    char name[MAX_NAME_LENGTH];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void initialize_processes(Process processes[], int count);
void calculate_waiting_time(Process processes[], int count);
void calculate_turnaround_time(Process processes[], int count);
void sort_processes_by_priority(Process processes[], int count);
void display_processes(Process processes[], int count);

int main() {
    int n;
    Process processes[MAX_PROCESSES];

    printf("Welcome to the C System Boot Optimizer!\n");
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n < 1 || n > MAX_PROCESSES) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    initialize_processes(processes, n);
    sort_processes_by_priority(processes, n);
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);
    display_processes(processes, n);

    return 0;
}

void initialize_processes(Process processes[], int count) {
    printf("Enter details for each process:\n");
    for (int i = 0; i < count; i++) {
        printf("Process %d Name: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Process %d Priority (1-5, 1=highest): ", i + 1);
        scanf("%d", &processes[i].priority);
    }
}

void sort_processes_by_priority(Process processes[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculate_waiting_time(Process processes[], int count) {
    processes[0].waiting_time = 0;
    for (int i = 1; i < count; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

void calculate_turnaround_time(Process processes[], int count) {
    for (int i = 0; i < count; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void display_processes(Process processes[], int count) {
    printf("\nProcess Scheduling Order (Sorted by Priority):\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Process Name", "Burst Time", "Priority", "Wait Time", "Turnaround");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10d %-10d %-10d\n", 
                processes[i].name, 
                processes[i].burst_time, 
                processes[i].priority, 
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }

    printf("--------------------------------------------------\n");
    printf("System optimization performed successfully!\n");
}