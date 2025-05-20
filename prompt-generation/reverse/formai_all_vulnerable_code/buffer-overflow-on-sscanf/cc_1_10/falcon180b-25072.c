//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 1024

struct process {
    int pid;
    char name[MAX_LINE_LENGTH];
    int status;
};

int main() {
    int num_processes = 0;
    struct process processes[MAX_PROCESSES];

    FILE *proc_file = fopen("/proc/self/status", "r");
    if (proc_file == NULL) {
        printf("Error opening /proc/self/status\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, proc_file)!= NULL) {
        if (sscanf(line, "Name:\t%s", processes[num_processes].name) == 1) {
            num_processes++;
        }
    }

    fclose(proc_file);

    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = getpid();
        processes[i].status = 1;
    }

    while (1) {
        for (int i = 0; i < num_processes; i++) {
            int status;
            waitpid(processes[i].pid, &status, WNOHANG);

            if (WIFEXITED(status)) {
                processes[i].status = 0;
            }
        }

        usleep(500000);
    }

    return 0;
}