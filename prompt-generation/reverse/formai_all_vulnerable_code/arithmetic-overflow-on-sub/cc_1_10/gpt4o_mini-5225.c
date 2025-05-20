//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define MAX_NAME_LENGTH 20

typedef struct Process {
    char name[MAX_NAME_LENGTH];
    int burst_time;
    int priority;
} Process;

void print_schedule(Process processes[], int count) {
    printf("Behold the Dance of the CPU:\n");
    printf("Process Name | Burst Time | Priority\n");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%12s | %10d | %8d\n", processes[i].name, processes[i].burst_time, processes[i].priority);
        sleep(1); // Sleep for a surreal effect of time passing
    }
}

void sort_processes(Process processes[], int count) {
    // Bubble Sort as the clouds in the sky
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                // Swap as the wind sways the leaves
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void schedule_processes(Process processes[], int count) {
    printf("\nThe Grand Scheduling Ceremony Begins...\n");
    sort_processes(processes, count);
    print_schedule(processes, count);
}

int main() {
    int process_count;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes (1 to %d): ", MAX_PROCESSES);
    scanf("%d", &process_count);

    // Enigma of the Manifestation
    for (int i = 0; i < process_count; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter the burst time for %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority for %s: ", processes[i].name);
        scanf("%d", &processes[i].priority);
    }

    // Whispers of the Psyche
    schedule_processes(processes, process_count);
    
    printf("And thus, the CPU returns to its slumber, awaiting new dreams.\n");
    return 0;
}