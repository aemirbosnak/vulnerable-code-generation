//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    char name[64];
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated\n");
    }
}

int main() {
    int i, max_processes = 0;
    struct process *processes = NULL;

    // Initialize signal handler
    signal(SIGCHLD, sigchld_handler);

    // Get the number of running processes
    FILE *fp;
    char filename[100];
    sprintf(filename, "/proc/%d/task", getpid());
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open task directory\n");
        exit(1);
    }
    while (fscanf(fp, "%d", &i)!= EOF) {
        max_processes++;
    }
    fclose(fp);

    // Allocate memory for process structures
    processes = malloc(max_processes * sizeof(struct process));
    if (processes == NULL) {
        printf("Error: Unable to allocate memory for process structures\n");
        exit(1);
    }

    // Populate process structures
    sprintf(filename, "/proc/%d/task", getpid());
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open task directory\n");
        exit(1);
    }
    i = 0;
    while (fscanf(fp, "%d", &processes[i].pid)!= EOF) {
        sprintf(processes[i].name, "unknown");
        processes[i].status = 0;
        i++;
    }
    fclose(fp);

    // Monitor processes
    while (1) {
        printf("\n");
        for (i = 0; i < max_processes; i++) {
            if (processes[i].pid > 0) {
                sprintf(filename, "/proc/%d/comm", processes[i].pid);
                fp = fopen(filename, "r");
                if (fp!= NULL) {
                    fscanf(fp, "%s", processes[i].name);
                    fclose(fp);
                }
                printf("%-10d %-16s ", processes[i].pid, processes[i].name);
                if (processes[i].status == 0) {
                    printf("Running\n");
                } else {
                    printf("Terminated\n");
                }
            } else {
                printf("%-10s ", "");
            }
        }
        sleep(1);
    }

    return 0;
}