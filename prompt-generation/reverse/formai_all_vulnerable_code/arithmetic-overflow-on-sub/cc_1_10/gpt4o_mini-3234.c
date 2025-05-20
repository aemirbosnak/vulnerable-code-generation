//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;      // Process ID
    int burst;    // Burst time
    int wait_time; // Waiting time
    int turn_time; // Turnaround time
} Process;

// Function prototypes
void fcfs(Process proc[], int n);
void sjn(Process proc[], int n);
void roundRobin(Process proc[], int n, int quantum);
void calculate_average_times(Process proc[], int n);

// Main function
int main() {
    int n, choice, quantum;
    Process proc[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        proc[i].pid = i + 1; // Assigning process IDs
        printf("Enter burst time for process %d: ", proc[i].pid);
        scanf("%d", &proc[i].burst);
    }
    
    printf("Choose Scheduling Algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job Next (SJN)\n");
    printf("3. Round Robin (RR)\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            fcfs(proc, n);
            break;
        case 2:
            sjn(proc, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            roundRobin(proc, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void fcfs(Process proc[], int n) {
    int total_wait_time = 0, total_turn_time = 0;
    
    proc[0].wait_time = 0;
    
    for(int i = 1; i < n; i++) {
        proc[i].wait_time = proc[i - 1].wait_time + proc[i - 1].burst;
        total_wait_time += proc[i].wait_time;
    }
    
    for(int i = 0; i < n; i++) {
        proc[i].turn_time = proc[i].wait_time + proc[i].burst;
        total_turn_time += proc[i].turn_time;
    }
        
    printf("\nFCFS Scheduling:\n");
    calculate_average_times(proc, n);
}

void sjn(Process proc[], int n) {
    // Sort processes by burst time (SJN)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(proc[i].burst > proc[j].burst) {
                Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    int total_wait_time = 0, total_turn_time = 0;
    
    proc[0].wait_time = 0;
    
    for(int i = 1; i < n; i++) {
        proc[i].wait_time = proc[i - 1].wait_time + proc[i - 1].burst;
        total_wait_time += proc[i].wait_time;
    }
    
    for(int i = 0; i < n; i++) {
        proc[i].turn_time = proc[i].wait_time + proc[i].burst;
        total_turn_time += proc[i].turn_time;
    }

    printf("\nSJN Scheduling:\n");
    calculate_average_times(proc, n);
}

void roundRobin(Process proc[], int n, int quantum) {
    int total_wait_time = 0, total_turn_time = 0;
    int remaining_burst[MAX_PROCESSES];
    
    for(int i = 0; i < n; i++) {
        remaining_burst[i] = proc[i].burst; 
        proc[i].wait_time = 0; 
    }

    int time = 0;
    while(1) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if(remaining_burst[i] > 0) {
                done = 0; 

                if(remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    proc[i].wait_time = time - proc[i].burst; 
                    remaining_burst[i] = 0; 
                }
            }
        }
        if(done) break;
    }

    for(int i = 0; i < n; i++) {
        proc[i].turn_time = proc[i].wait_time + proc[i].burst;
        total_turn_time += proc[i].turn_time;
    }

    printf("\nRound Robin Scheduling:\n");
    calculate_average_times(proc, n);
}

void calculate_average_times(Process proc[], int n) {
    float avg_wait_time = 0, avg_turn_time = 0;

    for(int i = 0; i < n; i++) {
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", proc[i].pid, proc[i].wait_time, proc[i].turn_time);
        avg_wait_time += proc[i].wait_time;
        avg_turn_time += proc[i].turn_time;
    }

    avg_wait_time /= n;
    avg_turn_time /= n;

    printf("Average Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turn_time);
}