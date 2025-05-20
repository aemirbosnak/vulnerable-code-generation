//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Defining necessary structures and variables.
typedef struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int wait_time;
} Process;

int num_processes;
Process *processes = NULL;
int quantum;

// Function declarations.
void fcfs();
void round_robin();
void print_results();

int main() {
    srand(time(NULL));

    printf("MEDIEVAL CPU SCHEDULING\n\n");
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Initializing process array.
    processes = malloc(sizeof(Process) * num_processes);

    // Generating random arrival and burst times for each process.
    for (int i = 0; i < num_processes; i++) {
        processes[i].process_id = i + 1;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 10 + 1;
    }

    printf("\nProcesses generated:\n");
    printf("ID\tArrival Time\tBurst Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time);
    }

    printf("\nSelect CPU scheduling algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Round-Robin (RR)\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        fcfs();
    } else if (choice == 2) {
        printf("\nEnter time quantum: ");
        scanf("%d", &quantum);
        round_robin();
    } else {
        printf("\nInvalid choice.\n");
        return 1;
    }

    print_results();

    free(processes);

    return 0;
}

void fcfs() {
    // Sorting processes by arrival time.
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].wait_time = current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
    }
}

void round_robin() {
    // Initializing variables.
    int current_time = 0;
    bool *completed = malloc(sizeof(bool) * num_processes);
    int *remaining_burst = malloc(sizeof(int) * num_processes);
    for (int i = 0; i < num_processes; i++) {
        completed[i] = false;
        remaining_burst[i] = processes[i].burst_time;
    }

    while (true) {
        bool all_completed = true;
        for (int i = 0; i < num_processes; i++) {
            if (!completed[i]) {
                all_completed = false;
                break;
            }
        }
        if (all_completed) {
            break;
        }

        for (int i = 0; i < num_processes; i++) {
            if (completed[i]) {
                continue;
            }

            if (remaining_burst[i] <= quantum) {
                current_time += remaining_burst[i];
                processes[i].wait_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                remaining_burst[i] = 0;
                completed[i] = true;
            } else {
                current_time += quantum;
                remaining_burst[i] -= quantum;
            }
        }
    }

    free(completed);
    free(remaining_burst);
}

void print_results() {
    int total_wait_time = 0;
    printf("\nResults:\n");
    printf("ID\tWait Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\n", processes[i].process_id, processes[i].wait_time);
        total_wait_time += processes[i].wait_time;
    }
    printf("\nAverage Wait Time: %.2f\n", (float) total_wait_time / num_processes);
}