//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 256

// Struct to hold process information
typedef struct {
    int pid;
    char comm[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} ProcessInfo;

// Function prototypes
void listProcesses();
int isNumber(const char *str);
void getProcessInfo(int pid, ProcessInfo *processInfo);

int main() {
    printf("Simple Linux Process Viewer\n");
    printf("===========================\n");
    
    // Call the function to list all processes
    listProcesses();
    
    return 0;
}

// Function to list all processes in the /proc directory
void listProcesses() {
    DIR *procDir;
    struct dirent *entry;

    // Open the /proc directory
    if ((procDir = opendir("/proc")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-30s %-10s\n", "PID", "Command", "State");
    
    // Iterate through the directory entries
    while ((entry = readdir(procDir)) != NULL) {
        // Check if the name is a number (which indicates a process ID)
        if (isNumber(entry->d_name)) {
            int pid = atoi(entry->d_name);
            ProcessInfo pInfo;
            getProcessInfo(pid, &pInfo);
            // Display process information
            if (pInfo.pid != -1) {
                printf("%-10d %-30s %-10s\n", pInfo.pid, pInfo.comm, pInfo.state);
            }
        }
    }
    closedir(procDir);
}

// Function to check if a string represents a number
int isNumber(const char *str) {
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

// Function to get process information from /proc/[pid]/stat
void getProcessInfo(int pid, ProcessInfo *processInfo) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return;  // If the process does not exist, return
    }

    // Read process information
    fscanf(file, "%d %s %s", &processInfo->pid, processInfo->comm, processInfo->state);
    
    // Clean up the command name (removing parentheses)
    if (processInfo->comm[0] == '(') {
        char *end = strchr(processInfo->comm+1, ')');
        if (end != NULL) {
            *end = '\0';
            memmove(processInfo->comm, processInfo->comm + 1, strlen(processInfo->comm));
        }
    }

    fclose(file);
}