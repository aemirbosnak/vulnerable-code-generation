//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;                 // Process ID
    char name[BUFFER_SIZE];  // Process name
    long rss;               // Resident Set Size
} ProcessInfo;

int processCount = 0;
ProcessInfo processes[MAX_PROCESSES];

// Function prototypes
void fetchMemoryUsage();
void printMemoryInfo();
void sortProcessesByMemory();
void clearScreen();

int main() {
    while (1) {
        clearScreen();
        fetchMemoryUsage();
        sortProcessesByMemory();
        printMemoryInfo();
        sleep(5); // Update every 5 seconds
    }
    return 0;
}

void clearScreen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}

void fetchMemoryUsage() {
    FILE *fp;
    char line[BUFFER_SIZE];
    char statusPath[BUFFER_SIZE];

    // Clear previous data
    processCount = 0;

    // Open the process status file
    fp = popen("ps -eo pid,comm,rss", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    // Read each line of the output
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (processCount >= MAX_PROCESSES) {
            break;  // Prevent overflow
        }

        // Parse the output
        if (sscanf(line, "%d %s %ld", &processes[processCount].pid,
                   processes[processCount].name, &processes[processCount].rss) == 3) {
            processCount++;
        }
    }

    // Close the file pointer
    pclose(fp);
}

void sortProcessesByMemory() {
    // Simple bubble sort for sorting processes by RSS
    for (int i = 0; i < processCount - 1; i++) {
        for (int j = 0; j < processCount - i - 1; j++) {
            if (processes[j].rss < processes[j + 1].rss) {
                // Swap processes
                ProcessInfo temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void printMemoryInfo() {
    printf("PID\tName\t\tRSS (KB)\n");
    printf("------------------------------------\n");
    
    for (int i = 0; i < processCount; i++) {
        printf("%d\t%-15s\t%ld\n", processes[i].pid, processes[i].name, processes[i].rss);
    }

    if (processCount == 0) {
        printf("No processes found.\n");
    }
}