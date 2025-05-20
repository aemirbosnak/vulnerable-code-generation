//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    pid_t pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} ProcessInfo;

void get_process_info(ProcessInfo* processes, int* process_count) {
    DIR* proc_dir;
    struct dirent* entry;
    char path[BUFFER_SIZE];
    FILE* status_file;
    char buffer[BUFFER_SIZE];
    
    proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    *process_count = 0;

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            processes[*process_count].pid = atoi(entry->d_name);
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            status_file = fopen(path, "r");
            if (status_file) {
                while (fgets(buffer, sizeof(buffer), status_file)) {
                    if (sscanf(buffer, "Name:\t%s", processes[*process_count].name) == 1) {
                        // Found the name
                    } else if (sscanf(buffer, "State:\t%s", processes[*process_count].state) == 1) {
                        // Found the state
                    }
                }
                fclose(status_file);
                (*process_count)++;
            }
        }
    }
    closedir(proc_dir);
}

void display_processes(ProcessInfo* processes, int process_count) {
    printf("%-10s %-25s %s\n", "PID", "Name", "State");
    printf("%-10s %-25s %s\n", "---", "----", "-----");
    for (int i = 0; i < process_count; i++) {
        printf("%-10d %-25s %s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

void filter_processes_by_state(ProcessInfo* processes, int process_count, const char* state) {
    printf("\nProcesses with state '%s':\n", state);
    printf("%-10s %-25s %s\n", "PID", "Name", "State");
    printf("%-10s %-25s %s\n", "---", "----", "-----");
    
    for (int i = 0; i < process_count; i++) {
        if (strcmp(processes[i].state, state) == 0) {
            printf("%-10d %-25s %s\n", processes[i].pid, processes[i].name, processes[i].state);
        }
    }
}

int main(int argc, char* argv[]) {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count = 0;
    char filter_state[BUFFER_SIZE] = "";

    get_process_info(processes, &process_count);
    display_processes(processes, process_count);

    if (argc > 1) {
        strncpy(filter_state, argv[1], sizeof(filter_state) - 1);
        filter_processes_by_state(processes, process_count, filter_state);
    }

    return EXIT_SUCCESS;
}