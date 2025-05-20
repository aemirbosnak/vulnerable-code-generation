//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100

struct process {
    char name[50];
    int pid;
    int status;
};

void read_processes(struct process *processes) {
    char path[30] = "/proc";
    int i = 0;

    while (i < MAX_PROCESSES) {
        sprintf(path + strlen(path), "/%d", i);

        if (access(path, F_OK) == 0) {
            FILE *fp;
            char cmd[100];

            sprintf(cmd, "cat %s/cmdline", path);

            fp = popen(cmd, "r");

            fscanf(fp, "%s", processes[i].name);

            pclose(fp);

            processes[i].pid = i;
            processes[i].status = 1;

            i++;
        } else {
            break;
        }
    }
}

void display_processes(struct process *processes) {
    int i;

    for (i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].status == 1) {
            printf("%-20s %-10d\n", processes[i].name, processes[i].pid);
        }
    }
}

int main() {
    struct process processes[MAX_PROCESSES];

    read_processes(processes);

    printf("Process ID\tProcess Name\n");

    display_processes(processes);

    return 0;
}