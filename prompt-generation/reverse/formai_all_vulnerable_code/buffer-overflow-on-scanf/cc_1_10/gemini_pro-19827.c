//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_PROCESSES 100
#define MAX_TIME 1000

// Process structure
typedef struct {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
} Process;

// Scheduling algorithms
typedef enum {
    FCFS,
    SJF,
    SRT,
    RR,
    PRIO
} Algorithm;

// Function prototypes
void print_menu();
Algorithm get_algorithm();
void get_processes(Process processes[], int *num_processes);
void print_processes(Process processes[], int num_processes);
void execute_algorithm(Algorithm algorithm, Process processes[], int num_processes);

// Main function
int main() {
    // Print the menu
    print_menu();

    // Get the algorithm
    Algorithm algorithm = get_algorithm();

    // Get the processes
    Process processes[MAX_PROCESSES];
    int num_processes;
    get_processes(processes, &num_processes);

    // Print the processes
    print_processes(processes, num_processes);

    // Execute the algorithm
    execute_algorithm(algorithm, processes, num_processes);

    return 0;
}

// Print the menu
void print_menu() {
    printf("\nCPU Scheduling Algorithms\n");
    printf("------------------------\n");
    printf("1. First-Come First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Shortest Remaining Time (SRT)\n");
    printf("4. Round Robin (RR)\n");
    printf("5. Priority (PRIO)\n");
}

// Get the algorithm
Algorithm get_algorithm() {
    int choice;
    printf("\nEnter the number of the algorithm you want to use: ");
    scanf("%d", &choice);
    return choice;
}

// Get the processes
void get_processes(Process processes[], int *num_processes) {
    printf("\nEnter the number of processes: ");
    scanf("%d", num_processes);

    for (int i = 0; i < *num_processes; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }
}

// Print the processes
void print_processes(Process processes[], int num_processes) {
    printf("\nProcesses\n");
    printf("------------------------\n");
    printf("Arrival Time\tBurst Time\tPriority\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }
}

// Execute the algorithm
void execute_algorithm(Algorithm algorithm, Process processes[], int num_processes) {
    switch (algorithm) {
        case FCFS:
            printf("\nFirst-Come First-Served\n");
            break;
        case SJF:
            printf("\nShortest Job First\n");
            break;
        case SRT:
            printf("\nShortest Remaining Time\n");
            break;
        case RR:
            printf("\nRound Robin\n");
            break;
        case PRIO:
            printf("\nPriority\n");
            break;
        default:
            printf("\nInvalid algorithm\n");
    }
}