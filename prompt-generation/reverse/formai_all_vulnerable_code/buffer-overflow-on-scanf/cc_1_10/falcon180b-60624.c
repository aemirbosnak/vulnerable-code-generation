//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_PROCESSES 10
#define MAX_TIME_QUANTUM 5

// Process structure
struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to compare two processes based on their burst time
int compare_burst_time(const void *a, const void *b) {
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;

    if (p1->burst_time < p2->burst_time) {
        return -1;
    } else if (p1->burst_time > p2->burst_time) {
        return 1;
    } else {
        return 0;
    }
}

// Function to execute a process
void *execute_process(void *arg) {
    struct process *p = (struct process *)arg;

    // Sleep for the burst time of the process
    sleep(p->burst_time);

    // Print the process id and its execution time
    printf("Process %d executed for %d time units\n", p->id, p->burst_time);

    return NULL;
}

// Function to implement round robin scheduling algorithm
void round_robin_scheduling() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    int current_time = 0;
    int completed_processes = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Read the number of processes and their burst times from user input
    printf("Enter the number of processes (<= %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Sort the processes based on their burst time
    qsort(processes, num_processes, sizeof(struct process), compare_burst_time);

    // Execute each process for its burst time
    for (int i = 0; i < num_processes; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, execute_process, &processes[i]);

        // Wait for the process to complete
        pthread_join(thread_id, NULL);

        // Increment the current time by the time quantum
        current_time += MAX_TIME_QUANTUM;

        // Update the completed processes count
        completed_processes++;

        // Calculate the waiting time and turnaround time for the completed process
        processes[i].waiting_time = current_time - processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        // Update the total waiting time and turnaround time
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Print the results of the round robin scheduling algorithm
    printf("Average waiting time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / num_processes);
}

int main() {
    round_robin_scheduling();

    return 0;
}