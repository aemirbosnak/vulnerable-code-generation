//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} Process;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

void printHeader() {
    printf("\033[1;34m%-8s %-25s %-10s\033[0m\n", "PID", "Process Name", "State");
    printf("\033[1;32m%s\033[0m\n", "---------------------------------------------------------");
}

void getProcessInfo(Process processes[]) {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE], buffer[BUFFER_SIZE];
    FILE *statusFile;

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            processes[index].pid = atoi(entry->d_name);
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            
            statusFile = fopen(path, "r");
            if (statusFile != NULL) {
                while (fgets(buffer, sizeof(buffer), statusFile)) {
                    if (sscanf(buffer, "Name:\t%s", processes[index].name) == 1) {
                        // Successfully read process name
                    }
                    if (sscanf(buffer, "State:\t%s", processes[index].state) == 1) {
                        // Successfully read process state
                    }
                }
                fclose(statusFile);
                index++;
            }
        }
    }
    processes[index].pid = -1; // Indicate end of process list
    closedir(dir);
}

void displayProcesses(Process processes[]) {
    printHeader();
    for (int i = 0; processes[i].pid != -1; i++) {
        if (strcmp(processes[i].state, "S") == 0) {
            printf("\033[1;33m%-8d %-25s %-10s\033[0m\n", processes[i].pid, processes[i].name, processes[i].state);
        } else if (strcmp(processes[i].state, "R") == 0) {
            printf("\033[1;32m%-8d %-25s %-10s\033[0m\n", processes[i].pid, processes[i].name, processes[i].state);
        } else {
            printf("\033[1;31m%-8d %-25s %-10s\033[0m\n", processes[i].pid, processes[i].name, processes[i].state);
        }
    }
}

int main() {
    clearScreen();

    Process processes[MAX_PROCESSES];
    getProcessInfo(processes);

    while (1) {
        clearScreen();
        displayProcesses(processes);
        printf("\nPress Ctrl+C to exit...\n");
        sleep(2); // Refresh the view every 2 seconds
    }

    return 0;
}