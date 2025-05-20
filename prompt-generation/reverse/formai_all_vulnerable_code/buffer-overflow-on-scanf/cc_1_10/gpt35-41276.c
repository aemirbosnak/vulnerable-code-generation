//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// Constants for the program
#define MAX_PROCESSES 10000
#define MAX_RESOURCES 20

// Mutexes to protect shared resources
pthread_mutex_t mutex_procs = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_res = PTHREAD_MUTEX_INITIALIZER;

// Global variables
int available[MAX_RESOURCES];
int allocated[MAX_PROCESSES][MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int num_processes = 0;
int num_resources = 0;

// Function declarations
bool request_resources(int pid, int request[]);
void release_resources(int pid, int release[]);
bool is_safe();
bool is_safe_helper(int work[], bool finish[]);
void print_status();

int main(int argc, char *argv[]) {
    // Read in command line arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Open and read file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: Failed to open file %s\n", argv[1]);
        exit(1);
    }

    // Read number of resources
    fscanf(fp, "%d", &num_resources);

    // Read in available array
    for (int i = 0; i < num_resources; i++) {
        fscanf(fp, "%d", &available[i]);
    }

    // Read in allocation matrix
    while (!feof(fp) && num_processes < MAX_PROCESSES) {
        for (int i = 0; i < num_resources; i++) {
            fscanf(fp, "%d", &allocated[num_processes][i]);
        }
        for (int i = 0; i < num_resources; i++) {
            fscanf(fp, "%d", &maximum[num_processes][i]);
            need[num_processes][i] = maximum[num_processes][i] - allocated[num_processes][i];
        }
        num_processes++;
    }

    // Close file
    fclose(fp);

    // Prompt user for input
    while (true) {
        int choice, pid;
        int request[MAX_RESOURCES];
        int release[MAX_RESOURCES];

        printf("Enter 1 to request resources for a process\n");
        printf("Enter 2 to release resources for a process\n");
        printf("Enter 3 to print the current system status\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the process ID: ");
                scanf("%d", &pid);
                printf("Enter the requested resources: ");
                for (int i = 0; i < num_resources; i++) {
                    scanf("%d", &request[i]);
                }
                if (request_resources(pid, request)) {
                    printf("Request granted\n");
                } else {
                    printf("Request denied\n");
                }
                break;
            case 2:
                printf("Enter the process ID: ");
                scanf("%d", &pid);
                printf("Enter the released resources: ");
                for (int i = 0; i < num_resources; i++) {
                    scanf("%d", &release[i]);
                }
                release_resources(pid, release);
                printf("Resources released\n");
                break;
            case 3:
                print_status();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

bool request_resources(int pid, int request[]) {
    // Check if request exceeds need
    pthread_mutex_lock(&mutex_procs);
    pthread_mutex_lock(&mutex_res);
    for (int i = 0; i < num_resources; i++) {
        if (request[i] > need[pid][i]) {
            pthread_mutex_unlock(&mutex_res);
            pthread_mutex_unlock(&mutex_procs);
            return false;
        }
        if (request[i] > available[i]) {
            pthread_mutex_unlock(&mutex_res);
            pthread_mutex_unlock(&mutex_procs);
            return false;
        }
    }

    // Temporarily allocate resources
    for (int i = 0; i < num_resources; i++) {
        available[i] -= request[i];
        allocated[pid][i] += request[i];
        need[pid][i] -= request[i];
    }

    // Check if system is safe
    if (!is_safe()) {
        // Restore previous state
        for (int i = 0; i < num_resources; i++) {
            available[i] += request[i];
            allocated[pid][i] -= request[i];
            need[pid][i] += request[i];
        }
        pthread_mutex_unlock(&mutex_res);
        pthread_mutex_unlock(&mutex_procs);
        return false;
    }

    pthread_mutex_unlock(&mutex_res);
    pthread_mutex_unlock(&mutex_procs);
    return true;
}

void release_resources(int pid, int release[]) {
    pthread_mutex_lock(&mutex_procs);
    pthread_mutex_lock(&mutex_res);
    for (int i = 0; i < num_resources; i++) {
        available[i] += release[i];
        allocated[pid][i] -= release[i];
        need[pid][i] += release[i];
    }
    pthread_mutex_unlock(&mutex_res);
    pthread_mutex_unlock(&mutex_procs);
}

bool is_safe() {
    // Initialize arrays
    bool finish[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    for (int i = 0; i < num_processes; i++) {
        finish[i] = false;
    }
    for (int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }

    // Check if system is safe
    while (true) {
        int i;
        for (i = 0; i < num_processes; i++) {
            if (!finish[i] && is_safe_helper(work, finish)) {
                break;
            }
        }
        if (i == num_processes) {
            break;
        }
    }

    // Check if all processes finished
    for (int i = 0; i < num_processes; i++) {
        if (!finish[i]) {
            return false;
        }
    }

    return true;
}

bool is_safe_helper(int work[], bool finish[]) {
    for (int i = 0; i < num_resources; i++) {
        if (work[i] < need[i]) {
            return false;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        if (!finish[i]) {
            bool can_finish = true;
            for (int j = 0; j < num_resources; j++) {
                if (need[i][j] > work[j]) {
                    can_finish = false;
                    break;
                }
            }
            if (can_finish) {
                finish[i] = true;
                for (int j = 0; j < num_resources; j++) {
                    work[j] += allocated[i][j];
                }
                return true;
            }
        }
    }

    return false;
}

void print_status() {
    printf("\n");
    printf("Allocation  ");
    for (int i = 0; i < num_resources; i++) {
        printf("R%d ", i);
    }
    printf("\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d          ", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d  ", allocated[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Maximum      ");
    for (int i = 0; i < num_resources; i++) {
        printf("R%d ", i);
    }
    printf("\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d          ", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d  ", maximum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Need         ");
    for (int i = 0; i < num_resources; i++) {
        printf("R%d ", i);
    }
    printf("\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d          ", i);
        for (int j = 0; j < num_resources; j++) {
            printf("%d  ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Available    ");
    for (int i = 0; i < num_resources; i++) {
        printf("%d  ", available[i]);
    }
    printf("\n");
}