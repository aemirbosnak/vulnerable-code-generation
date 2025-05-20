//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char name[256];
    char state[10];
    int ppid;
} ProcessInfo;

void get_process_info(const char *pid, ProcessInfo *process) {
    char path[MAX_LINE_LENGTH];
    FILE *status_file;

    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        perror("Unable to open process status file");
        return;
    }

    process->pid = atoi(pid);
    fgets(process->name, sizeof(process->name), status_file); 
    sscanf(process->name, "Name:\t%s", process->name);
    
    while (fgets(path, sizeof(path), status_file)) {
        if (strstr(path, "State:")) {
            sscanf(path, "State:\t%s", process->state);
        } else if (strstr(path, "PPid:")) {
            sscanf(path, "PPid:\t%d", &process->ppid);
        }
    }

    fclose(status_file);
}

void list_processes(const char *filter) {
    DIR *proc_dir;
    struct dirent *entry;
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Unable to open /proc directory");
        return;
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            // We found a process directory
            ProcessInfo process;
            get_process_info(entry->d_name, &process);

            if (filter == NULL || strstr(process.name, filter)) {
                processes[count++] = process;
                if (count >= MAX_PROCESSES) {
                    break; // Limit the number of processes for display
                }
            }
        }
    }

    closedir(proc_dir);

    printf("%-10s %-30s %-10s %-10s\n", "PID", "Name", "State", "PPID");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10s %-10d\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].ppid);
    }
}

int main(int argc, char *argv[]) {
    char filter[256] = {0};

    if (argc > 1) {
        strncpy(filter, argv[1], sizeof(filter) - 1);
        filter[sizeof(filter) - 1] = '\0'; // Ensure null-termination
    }

    printf("Process Viewer\n");
    printf("==============\n");

    if (strlen(filter) > 0) {
        printf("Filter: %s\n\n", filter);
    } else {
        printf("No filter applied.\n\n");
    }

    list_processes(strlen(filter) > 0 ? filter : NULL);
    
    return 0;
}