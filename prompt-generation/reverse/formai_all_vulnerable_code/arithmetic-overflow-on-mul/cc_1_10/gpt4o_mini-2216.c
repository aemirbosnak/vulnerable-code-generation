//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    long residentSetSize; // RSS in kilobytes
} ProcessInfo;

// Function to read the memory usage of a specific process
long getProcessMemoryUsage(int pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/statm", pid);

    FILE *file = fopen(path, "r");
    if (!file) {
        return -1;
    }

    long memoryUsage = 0;
    fscanf(file, "%*s %ld", &memoryUsage);
    fclose(file);

    return memoryUsage * getpagesize() / 1024; // Convert pages to kilobytes
}

// Function to read process name from /proc/[pid]/comm
void getProcessName(int pid, char *name) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/comm", pid);
    FILE *file = fopen(path, "r");
    if (file) {
        fgets(name, BUFFER_SIZE, file);
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0'; // Remove newline character
        }
        fclose(file);
    }
}

// Function to monitor memory usage
void monitorMemoryUsage() {
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    while (1) {
        for (int pid = 1; pid < MAX_PROCESSES; pid++) {
            long memoryUsage = getProcessMemoryUsage(pid);
            if (memoryUsage != -1) {
                processes[count].pid = pid;
                getProcessName(pid, processes[count].name);
                processes[count].residentSetSize = memoryUsage;
                count++;
            }
        }
        
        // Display the results
        printf("\nPID\tName\t\t\tMemory Usage (KB)\n");
        printf("---------------------------------------------------\n");
        
        for (int i = 0; i < count; i++) {
            printf("%d\t%-20s\t%ld\n", processes[i].pid, processes[i].name, processes[i].residentSetSize);
        }

        fflush(stdout);
        sleep(5); // Delay for a short interval before refreshing
        printf("\033[H\033[J"); // Clear terminal screen
        count = 0; // Reset count for the next round
    }
}

int main() {
    printf("Starting Memory Usage Monitor...\n");
    monitorMemoryUsage();
    return 0;
}