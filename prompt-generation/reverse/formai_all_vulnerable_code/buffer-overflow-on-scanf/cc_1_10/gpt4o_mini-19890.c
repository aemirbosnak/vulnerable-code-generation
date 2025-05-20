//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    long resident_memory;
} ProcessInfo;

void getMemoryUsage(ProcessInfo* processes, int* count) {
    char command[BUFFER_SIZE];
    FILE* fp;
    char buffer[BUFFER_SIZE];
    int idx = 0;

    // Using 'ps' command to get memory usage of processes
    // Command: ps -eo pid,comm,rss
    sprintf(command, "ps -eo pid,comm,rss --sort=-rss");
    
    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    // Skip the header line
    fgets(buffer, sizeof(buffer), fp);

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %ld", &processes[idx].pid, processes[idx].name, &processes[idx].resident_memory);
        idx++;
        if (idx >= MAX_PROCESSES) break; // Avoid overflow
    }
    *count = idx;

    // Close the command stream
    pclose(fp);
}

void displayMenu() {
    printf("\n");
    printf("Welcome to the C RAM Usage Monitor!\n");
    printf("1. View Process Memory Usage\n");
    printf("2. Refresh Data\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

void displayProcesses(ProcessInfo* processes, int count) {
    printf("\n%-10s %-30s %s\n", "PID", "Process Name", "Resident Memory (KB)");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %ld\n", processes[i].pid, processes[i].name, processes[i].resident_memory);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getMemoryUsage(processes, &process_count);
                displayProcesses(processes, process_count);
                break;
            case 2:
                printf("Refreshing data...\n");
                sleep(2);
                continue; // refresh while keeping the menu up
            case 3:
                printf("Exiting the RAM Usage Monitor. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress Enter to return to the menu...");
        getchar(); // Clear newline character in buffer
        getchar(); // Wait for the user to press Enter
    }

    return 0;
}