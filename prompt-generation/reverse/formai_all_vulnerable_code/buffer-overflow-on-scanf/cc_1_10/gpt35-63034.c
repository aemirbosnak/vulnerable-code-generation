//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_BURST_TIME 10
#define QUANTUM 2

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
} Process;

int randomize(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    Process processes[MAX_PROCESSES];
    int num_processes = MAX_PROCESSES;
    printf("==== RETRO CPU SCHEDULER ====\n");
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);
    if (num_processes > MAX_PROCESSES) {
        num_processes = MAX_PROCESSES;
    }
    printf("\nRandomly generating %d processes...\n", num_processes);
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        processes[i].arrival_time = randomize(0, MAX_BURST_TIME);
        processes[i].burst_time = randomize(1, MAX_BURST_TIME);
        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("\nProcesses generated!\n");
    printf("===========================\n");
    printf("PID\tARRIVAL\tBURST\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
    }
    printf("===========================\n");
    
    printf("\nStarting scheduling...\n\n");
    int time = 0;
    int completed_processes = 0;
    while (completed_processes < num_processes) {
        int current_process = -1;
        int highest_priority = -1;
        int quantum_used = 0;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (highest_priority < processes[i].remaining_time) {
                    highest_priority = processes[i].remaining_time;
                    current_process = i;
                }
            }
        }
        if (current_process == -1) {
            printf("IDLE\t%d\n", time);
            time++;
            continue;
        }
        if (processes[current_process].remaining_time > QUANTUM) {
            quantum_used = QUANTUM;
        } else {
            quantum_used = processes[current_process].remaining_time;
        }
        printf("P%d\t%d\n", processes[current_process].pid, time);
        processes[current_process].remaining_time -= quantum_used;
        time += quantum_used;
        if (processes[current_process].remaining_time <= 0) {
            completed_processes++;
            processes[current_process].turnaround_time = time - processes[current_process].arrival_time;
            processes[current_process].waiting_time = processes[current_process].turnaround_time - processes[current_process].burst_time;
        }
    }
    printf("Scheduling complete!\n");
    printf("===========================\n");
    printf("PID\tARRIVAL\tBURST\tTURNAROUND\tWAITING\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("===========================\n");

    return 0;
}