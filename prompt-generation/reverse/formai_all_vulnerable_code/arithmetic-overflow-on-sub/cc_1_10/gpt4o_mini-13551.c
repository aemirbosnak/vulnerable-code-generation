//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

volatile sig_atomic_t keep_going = 1;

void handle_sigint(int signo) {
    keep_going = 0;
}

typedef struct {
    pid_t pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
    unsigned long memory;
} Process;

void get_processes(Process processes[], int *count) {
    struct dirent *entry;
    DIR *dp = opendir("/proc");
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char *endptr;
            pid_t pid = strtol(entry->d_name, &endptr, 10);
            if (*endptr != '\0') continue;

            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "/proc/%d/stat", pid);
            FILE *stat_file = fopen(path, "r");
            if (stat_file) {
                Process process;
                process.pid = pid;
                fscanf(stat_file, "%*d %s %*c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu",
                       process.name, &process.memory);
                strcpy(process.state, "Unknown"); // Placeholder for state
                fclose(stat_file);
                
                snprintf(path, sizeof(path), "/proc/%d/status", pid);
                FILE *status_file = fopen(path, "r");
                if (status_file) {
                    char line[BUFFER_SIZE];
                    while (fgets(line, sizeof(line), status_file)) {
                        if (strncmp(line, "State:", 6) == 0) {
                            sscanf(line + 6, "%s", process.state);
                            break;
                        }
                    }
                    fclose(status_file);
                }
                processes[(*count)++] = process;
            }
        }
    }
    closedir(dp);
}

void display_processes(Process processes[], int count) {
    printf("%-10s %-30s %-10s %-10s\n", "PID", "NAME", "STATE", "MEMORY");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10s %-10lu kB\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].memory / 1024);
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    Process processes[MAX_PROCESSES];
    int count;

    while (keep_going) {
        system("clear"); // Clear the screen
        get_processes(processes, &count);
        display_processes(processes, count);
        usleep(1000000); // Sleep for 1 second
    }

    printf("Process viewer exited cleanly.\n");
    return 0;
}