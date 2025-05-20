//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LEN 16
#define MAX_COMMAND_LEN 64

typedef struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    char command[MAX_COMMAND_LEN];
} process_t;

void read_processes(process_t processes[]) {
    char procfile[64] = "/proc/";
    int i = 0;

    strcat(procfile, "1/");
    int fd = open(procfile, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Error opening /proc/1\n");
        exit(1);
    }

    char line[64];
    while (fgets(line, sizeof(line), fd)!= NULL) {
        if (i >= MAX_PROCESSES) {
            fprintf(stderr, "Maximum number of processes reached\n");
            break;
        }

        if (sscanf(line, "name=%s", processes[i].name) == 1) {
            sprintf(procfile, "/proc/%s/cmdline", processes[i].name);

            int cmd_fd = open(procfile, O_RDONLY);
            if (cmd_fd == -1) {
                fprintf(stderr, "Error opening %s\n", procfile);
                exit(1);
            }

            if (read(cmd_fd, processes[i].command, sizeof(processes[i].command)) == -1) {
                fprintf(stderr, "Error reading %s\n", procfile);
                exit(1);
            }

            close(cmd_fd);
            i++;
        }
    }

    close(fd);
}

void print_processes(process_t processes[]) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].pid!= 0) {
            printf("%d %s %s\n", processes[i].pid, processes[i].name, processes[i].command);
        }
    }
}

int main() {
    process_t processes[MAX_PROCESSES];

    read_processes(processes);
    print_processes(processes);

    return 0;
}