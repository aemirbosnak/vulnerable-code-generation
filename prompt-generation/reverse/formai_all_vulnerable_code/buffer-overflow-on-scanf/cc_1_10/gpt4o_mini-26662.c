//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    int burst_time;
} Process;

void input_processes(Process processes[], int *count) {
    printf("Enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", count);
    
    for (int i = 0; i < *count; i++) {
        printf("Enter name for process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter priority for process %d (higher number means higher priority): ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
}

void display_processes(Process processes[], int count) {
    printf("\nProcesses:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Priority", "Burst Time");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10d\n", processes[i].name, processes[i].priority, processes[i].burst_time);
    }
}

int compare_processes(const void *a, const void *b) {
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processB->priority - processA->priority; // Higher priority first
}

void optimize_boot_order(Process processes[], int count) {
    qsort(processes, count, sizeof(Process), compare_processes);
    printf("\nOptimized Boot Order:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Priority: %d, Burst Time: %d)\n", i + 1, processes[i].name, processes[i].priority, processes[i].burst_time);
    }
}

void simulate_boot_sequence(Process processes[], int count) {
    printf("\nSimulating Boot Sequence...\n");
    for (int i = 0; i < count; i++) {
        printf("Booting %s... (Burst Time: %d seconds)\n", processes[i].name, processes[i].burst_time);
        sleep(processes[i].burst_time); // Simulate the time taken for the process to boot
    }
    printf("All processes have been booted successfully!\n");
}

int main() {
    Process processes[MAX_PROCESSES];
    int process_count = 0;

    input_processes(processes, &process_count);
    display_processes(processes, process_count);
    
    optimize_boot_order(processes, process_count);
    simulate_boot_sequence(processes, process_count);

    return 0;
}