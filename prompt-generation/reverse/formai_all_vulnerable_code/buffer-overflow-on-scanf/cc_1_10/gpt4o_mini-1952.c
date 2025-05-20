//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;           // Process ID
    int burst_time;  // Burst time required by process
    int waiting_time; // Time a process waits before its turn
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;
int quantum_time = 0;

sem_t sem; // Semaphore for synchronization

void *scheduler(void *arg) {
    int total_waiting_time[MAX_PROCESSES] = {0};
    int remaining_burst_time[MAX_PROCESSES];

    for(int i = 0; i < num_processes; i++){
        remaining_burst_time[i] = processes[i].burst_time;
    }

    int all_done = 0;
    while (!all_done) {
        all_done = 1;
        for(int i = 0; i < num_processes; i++) {
            if (remaining_burst_time[i] > 0) {
                all_done = 0; // At least one process is remaining
                if (remaining_burst_time[i] > quantum_time) {
                    printf("Process %d is running for %d time units\n", processes[i].id, quantum_time);
                    sleep(quantum_time);
                    remaining_burst_time[i] -= quantum_time;
                } else {
                    printf("Process %d is running for %d time units (Finishing)\n", processes[i].id, remaining_burst_time[i]);
                    sleep(remaining_burst_time[i]);
                    total_waiting_time[i] += quantum_time; // Add time spent in previous cycles
                    remaining_burst_time[i] = 0; // Process completed
                }
            }
        }
    }

    // Calculate waiting time
    for (int j = 0; j < num_processes; j++) {
        processes[j].waiting_time = total_waiting_time[j];
    }

    sem_post(&sem); // Signal completion
    return NULL;
}

int main() {
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    if (num_processes > MAX_PROCESSES || num_processes < 1) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter quantum time: ");
    scanf("%d", &quantum_time);

    // Initialize semaphore
    sem_init(&sem, 0, 0);

    // Create scheduler thread
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, scheduler, NULL);

    printf("Scheduling processes...\n");

    // Wait for scheduler to finish
    sem_wait(&sem);

    // Display waiting times
    printf("\nProcess Waiting Times:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: Waiting Time = %d\n", processes[i].id, processes[i].waiting_time);
    }

    // Cleanup
    pthread_join(scheduler_thread, NULL);
    sem_destroy(&sem);

    return 0;
}