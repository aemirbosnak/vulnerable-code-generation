//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define STATUS_FILE "status"
#define MAX_BUFFER 256

// Structure to hold process information
typedef struct {
    int pid;
    char name[MAX_BUFFER];
    char state[MAX_BUFFER];
} ProcessInfo;

// Function to get process name and state from its status file
void get_process_info(int pid, ProcessInfo* info) {
    char path[MAX_BUFFER];
    snprintf(path, sizeof(path), "%s/%d/%s", PROC_PATH, pid, STATUS_FILE);

    FILE* file = fopen(path, "r");
    if (file) {
        char line[MAX_BUFFER];
        while (fgets(line, sizeof(line), file)) {
            if (sscanf(line, "Name:\t%s", info->name) == 1) {
                // Name retrieved
            }
            if (sscanf(line, "State:\t%s", info->state) == 1) {
                // State retrieved
                break;
            }
        }
        fclose(file);
    }
}

// Function to print the processes
void print_processes() {
    DIR* dir = opendir(PROC_PATH);
    struct dirent* entry;

    if (dir == NULL) {
        perror("Unable to open the /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("%-8s %-25s %s\n", "PID", "Process Name", "State");
    printf("%-8s %-25s %s\n", "----", "-------------", "------");

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            ProcessInfo info;
            info.pid = pid;

            get_process_info(pid, &info);
            if (info.state[0] != '\0') {
                printf("%-8d %-25s %s\n", info.pid, info.name, info.state);
            }
        }
    }

    closedir(dir);
}

int main() {
    printf("Process Viewer\n");
    printf("=======================\n");

    print_processes();

    return 0;
}