//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process proc[], int n) {
    int total_waiting_time = 0;
    proc[0].waiting_time = 0; // The first process waits forever... just kidding.

    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
        total_waiting_time += proc[i].waiting_time;
    }
    
    printf("\nTotal Waiting Time: %d\n", total_waiting_time);
}

void calculate_turnaround_time(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void print_processes(Process proc[], int n) {
    printf("─────────────────────────────────────\n");
    printf("Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("─────────────────────────────────────\n");
    for (int i = 0; i < n; i++) {
        printf("    %d      |      %d      |     %d     |      %d       |       %d\n", 
                proc[i].process_id, proc[i].arrival_time, proc[i].burst_time, 
                proc[i].waiting_time, proc[i].turnaround_time);
    }
    printf("─────────────────────────────────────\n");
}

void FIFO(Process proc[], int n) {
    printf("\nFIFO Scheduling: Because First In, First Out is how we do it at the CPU diner!\n");
    calculate_waiting_time(proc, n);
    calculate_turnaround_time(proc, n);
    print_processes(proc, n);
}

void SJF(Process proc[], int n) {
    printf("\nShortest Job First Scheduling: For those who like to finish fast!\n");
    
    // Sorting the processes by burst time (the shorter, the better)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burst_time > proc[j + 1].burst_time) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
    calculate_waiting_time(proc, n);
    calculate_turnaround_time(proc, n);
    print_processes(proc, n);
}

void RoundRobin(Process proc[], int n, int quantum) {
    printf("\nRound Robin Scheduling: Like a merry-go-round, but less fun!\n");
    
    int remaining_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = proc[i].burst_time;
    }

    int time = 0;
    while (1) {
        int done = 1; // Assume all processes are done initially
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = 0; // At least one process is not done

                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    proc[i].waiting_time = time - proc[i].burst_time - proc[i].arrival_time;
                    remaining_burst[i] = 0; // Process completed
                }
            }
        }
        
        if (done) break; // If all processes are done, exit the loop
    }

    calculate_turnaround_time(proc, n);
    print_processes(proc, n);
}

int main() {
    Process proc[MAX_PROCESSES];
    int n, choice, quantum;

    printf("Welcome to the Silly CPU Scheduler!\n");
    printf("Enter the number of processes (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        proc[i].process_id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &proc[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
    }

    printf("\nChoose a scheduling algorithm:\n1. FIFO\n2. SJF\n3. Round Robin\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FIFO(proc, n);
            break;
        case 2:
            SJF(proc, n);
            break;
        case 3:
            printf("Enter Time Quantum for Round Robin: ");
            scanf("%d", &quantum);
            RoundRobin(proc, n, quantum);
            break;
        default:
            printf("Oops! That's not a valid choice. Try flipping a coin instead!\n");
            break;
    }

    printf("Thank you for using the Silly CPU Scheduler! Remember to prioritize your CPU and not get too 'stressed'!\n");
    return 0;
}