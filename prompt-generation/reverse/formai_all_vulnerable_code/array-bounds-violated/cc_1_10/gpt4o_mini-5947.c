//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 256
#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char name[256];
    char state[16];
    double cpuUsage;
} ProcessInfo;

void getProcessInfo(ProcessInfo* processes, int* count) {
    DIR* procDir;
    struct dirent* entry;
    char path[MAX_PATH];

    *count = 0;

    // Open the "/proc" directory to read process information
    if ((procDir = opendir("/proc")) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(procDir)) != NULL) {
        // Check if the entry is a directory and a number (PID)
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            FILE* statFile = fopen(path, "r");
            if (statFile) {
                ProcessInfo procInfo;
                fscanf(statFile, "%d %s %s", &procInfo.pid, procInfo.name, procInfo.state);
                procInfo.name[strlen(procInfo.name) - 1] = '\0'; // Remove trailing parentheses

                // Here you can add CPU usage calculation if needed.
                procInfo.cpuUsage = (double)rand() / RAND_MAX * 100; // Placeholder for CPU usage

                processes[*count] = procInfo;
                (*count)++;
                fclose(statFile);
            }
        }
    }
    closedir(procDir);
}

void displayProcessInfo(ProcessInfo* processes, int count) {
    printf("%-10s %-25s %-10s %-10s\n", "PID", "Name", "State", "CPU Usage");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10s %-10.2f%%\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].cpuUsage);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int processCount = 0;

    while (1) {
        // Fetch process information
        getProcessInfo(processes, &processCount);
        
        // Clear the console
        printf("\033[H\033[J"); // ANSI escape codes for clearing the screen

        // Display process information
        displayProcessInfo(processes, processCount);
        
        // Sleep for a while before the next refresh
        sleep(3);
    }

    return 0;
}