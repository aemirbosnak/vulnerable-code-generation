//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESSES 100
#define STATUS_RUNNING 1
#define STATUS_WAITING 0

typedef struct {
    int pid;
    int priority;
    int status;
} Process;

Process process_table[MAX_PROCESSES];
int process_count = 0;

void initialize_processes(int count) {
    for (int i = 0; i < count; i++) {
        process_table[i].pid = i + 1; // Process IDs start from 1
        process_table[i].priority = rand() % 10; // Random priority between 0-9
        process_table[i].status = STATUS_WAITING; // Initially waiting
    }
    process_count = count;
}

void display_processes() {
    printf("PID\tPriority\tStatus\n");
    printf("----------------------------------\n");
    for (int i = 0; i < process_count; i++) {
        printf("%d\t%d\t\t%s\n", 
               process_table[i].pid,
               process_table[i].priority,
               (process_table[i].status == STATUS_RUNNING) ? "Running" : "Waiting");
    }
    printf("----------------------------------\n");
}

void optimize_processes() {
    // Sort processes based on priority (higher number = higher priority)
    for (int i = 0; i < process_count - 1; i++) {
        for (int j = 0; j < process_count - i - 1; j++) {
            if (process_table[j].priority < process_table[j + 1].priority) {
                // Swap
                Process temp = process_table[j];
                process_table[j] = process_table[j + 1];
                process_table[j + 1] = temp;
            }
        }
    }
}

void run_processes() {
    for (int i = 0; i < process_count; i++) {
        process_table[i].status = STATUS_RUNNING;
        printf("Running process PID %d with priority %d...\n", process_table[i].pid, process_table[i].priority);
        sleep(1); // Simulate process run time
        process_table[i].status = STATUS_WAITING; // Set back to waiting after running
    }
}

int main() {
    srand(time(0)); // Seed for randomness
    int num_processes;

    printf("Enter the number of processes (1-%d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    if (num_processes < 1 || num_processes > MAX_PROCESSES) {
        printf("Invalid number of processes. Please try again.\n");
        return 1;
    }

    printf("Initializing processes...\n");
    initialize_processes(num_processes);
    
    printf("Processes initialized successfully!\n");

    printf("\nInitial process table:\n");
    display_processes();

    printf("\nOptimizing process order based on priority...\n");
    optimize_processes();

    printf("\nOptimized process table:\n");
    display_processes();

    printf("\nStarting process execution...\n");
    run_processes();

    printf("\nAll processes have been executed.\n");
    return 0;
}