//FormAI DATASET v1.0 Category: System boot optimizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 1000
#define MAX_RESOURCES 10

int available_resources[MAX_RESOURCES];
int allocated_resources[MAX_PROCESSES][MAX_RESOURCES];
int needed_resources[MAX_PROCESSES][MAX_RESOURCES];
int n_processes;
int n_resources;
int safe_sequence[MAX_PROCESSES];

// Function to check if a process can be allocated resources
int can_allocate(int process_id, int *request) {
    for (int i = 0; i < n_resources; i++) {
        if (request[i] > needed_resources[process_id][i])
            return 0;
        if (request[i] > available_resources[i])
            return 0;
    }
    return 1;
}

// Function to allocate resources to a process
void allocate(int process_id, int *request) {
    for (int i = 0; i < n_resources; i++) {
        available_resources[i] -= request[i];
        allocated_resources[process_id][i] += request[i];
        needed_resources[process_id][i] -= request[i];
    }
}

// Function to release resources held by a process
void release(int process_id) {
    for (int i = 0; i < n_resources; i++) {
        available_resources[i] += allocated_resources[process_id][i];
        allocated_resources[process_id][i] = 0;
        needed_resources[process_id][i] = 0;
    }
}

// Function to find a safe sequence of processes that can be executed
int find_safe_sequence() {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES];
    int count = 0;
    for (int i = 0; i < n_resources; i++)
        work[i] = available_resources[i];
    for (int i = 0; i < n_processes; i++)
        finish[i] = 0;
    while (count < n_processes) {
        int found = 0;
        for (int i = 0; i < n_processes; i++) {
            if (finish[i] == 0) {
                int can_run = 1;
                for (int j = 0; j < n_resources; j++) {
                    if (needed_resources[i][j] > work[j]) {
                        can_run = 0;
                        break;
                    }
                }
                if (can_run) {
                    for (int j = 0; j < n_resources; j++)
                        work[j] += allocated_resources[i][j];
                    safe_sequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0;
    }
    return 1;
}

// Function to print the status of all resources
void print_status() {
    printf("\nAvailable resources: ");
    for (int i = 0; i < n_resources; i++)
        printf("%d ", available_resources[i]);
    printf("\n");
    printf("Processes:\n");
    for (int i = 0; i < n_processes; i++) {
        printf("Process %d\n", i);
        printf("Allocated resources: ");
        for (int j = 0; j < n_resources; j++)
            printf("%d ", allocated_resources[i][j]);
        printf("\n");
        printf("Needed resources: ");
        for (int j = 0; j < n_resources; j++)
            printf("%d ", needed_resources[i][j]);
        printf("\n");
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the available resources
    printf("Enter the number of resources: ");
    scanf("%d", &n_resources);
    printf("Enter the number of units for each resource:\n");
    for (int i = 0; i < n_resources; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &available_resources[i]);
    }

    // Initialize the processes and their resource needs
    printf("Enter the number of processes: ");
    scanf("%d", &n_processes);
    for (int i = 0; i < n_processes; i++) {
        for (int j = 0; j < n_resources; j++) {
            needed_resources[i][j] = rand() % (available_resources[j] / 2) + 1;
        }
    }

    // Main loop
    while (1) {
        int command;
        printf("\n1. Allocate resources to a process\n");
        printf("2. Release resources held by a process\n");
        printf("3. Print status\n");
        printf("4. Quit\n");
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command) {
            case 1:
                // Allocate resources to a process
                printf("Enter the ID of the process: ");
                int process_id;
                scanf("%d", &process_id);
                if (process_id < 0 || process_id >= n_processes) {
                    printf("Invalid process ID\n");
                    break;
                }
                printf("Enter the amount of each resource to allocate:\n");
                int request[MAX_RESOURCES];
                for (int i = 0; i < n_resources; i++)
                    scanf("%d", &request[i]);
                if (!can_allocate(process_id, request)) {
                    printf("Cannot allocate resources\n");
                    break;
                }
                allocate(process_id, request);
                if (find_safe_sequence()) {
                    printf("Allocation successful, safe sequence found: ");
                    for (int i = 0; i < n_processes; i++)
                        printf("%d ", safe_sequence[i]);
                    printf("\n");
                }
                else {
                    printf("Allocation successful, unsafe sequence found\n");
                }
                break;
            case 2:
                // Release resources held by a process
                printf("Enter the ID of the process: ");
                int process_id2;
                scanf("%d", &process_id2);
                if (process_id2 < 0 || process_id2 >= n_processes) {
                    printf("Invalid process ID\n");
                    break;
                }
                release(process_id2);
                printf("Resources released\n");
                break;
            case 3:
                // Print status
                print_status();
                break;
            case 4:
                // Quit
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid command\n");
        }
    }
    return 0;
}