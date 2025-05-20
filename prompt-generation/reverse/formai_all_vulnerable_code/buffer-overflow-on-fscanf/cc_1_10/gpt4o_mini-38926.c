//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_PATH "/proc"
#define BUFFER_SIZE 256
#define TASK_PATH_SIZE 512

typedef struct ProcessInfo {
    int pid;
    char comm[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} ProcessInfo;

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void read_process_info(int pid, ProcessInfo *proc_info) {
    char path[TASK_PATH_SIZE];
    snprintf(path, sizeof(path), "%s/%d/stat", PROC_PATH, pid);
    
    FILE *file = fopen(path, "r");
    if (file) {
        fscanf(file, "%d %s %s", &proc_info->pid, proc_info->comm, proc_info->state);
        fclose(file);
    }
}

void list_processes() {
    DIR *dir = opendir(PROC_PATH);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open /proc");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-20s %-10s\n", "PID", "COMMAND", "STATE");
    
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            ProcessInfo proc_info;
            int pid = atoi(entry->d_name);
            read_process_info(pid, &proc_info);
            // Adjust command for output and remove parentheses
            proc_info.comm[strcspn(proc_info.comm, "()")] = 0;
            
            printf("%-10d %-20s %-10s\n", proc_info.pid, proc_info.comm, proc_info.state);
        }
    }

    closedir(dir);
}

int main() {
    printf("=== Process Viewer ===\n");
    printf("Retrieving process information...\n\n");
    list_processes();
    printf("\nDone.\n");

    return 0;
}