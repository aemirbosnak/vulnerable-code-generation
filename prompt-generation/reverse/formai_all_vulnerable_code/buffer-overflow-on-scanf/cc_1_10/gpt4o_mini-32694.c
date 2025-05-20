//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

Process processes[MAX_PROCESSES];
int process_count = 0;

int quantum_time = 2; // Time quantum for Round Robin

void *execute_process(void *arg) {
    Process *proc = (Process *)arg;
    printf("Process %d starts execution with remaining time %d\n", proc->id, proc->remaining_time);

    while (proc->remaining_time > 0) {
        if (proc->remaining_time > quantum_time) {
            sleep(quantum_time);
            proc->remaining_time -= quantum_time;
            printf("Process %d executed for %d seconds. Remaining time: %d seconds\n", proc->id, quantum_time, proc->remaining_time);
        } else {
            sleep(proc->remaining_time);
            printf("Process %d completed execution. Total time: %d seconds\n", proc->id, proc->burst_time);
            proc->remaining_time = 0;
        }
    }
    return NULL;
}

void schedule_processes() {
    pthread_t threads[MAX_PROCESSES];

    for (int i = 0; i < process_count; i++) {
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time
    }

    while (1) {
        int all_done = 1;

        for (int i = 0; i < process_count; i++) {
            if (processes[i].remaining_time > 0) {
                all_done = 0; // At least one process is still remaining
                // Create a thread for the process
                pthread_create(&threads[i], NULL, execute_process, (void *)&processes[i]);
                // Wait for the process thread to execute
                pthread_join(threads[i], NULL);
            }
        }

        // Break if all processes are completed
        if (all_done) break;
    }
}

int main() {
    printf("Welcome to the Round Robin CPU Scheduling Simulator!\n");

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &process_count);
    
    if (process_count > MAX_PROCESSES || process_count <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < process_count; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Scheduling processes using Round Robin...\n");

    schedule_processes();

    printf("All processes have been completed.\n");

    return 0;
}