//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100

struct process {
    pid_t pid;
    char name[64];
    int status;
};

int get_processes(struct process *processes, int max_processes) {
    FILE *fp;
    char path[64] = "/proc/";
    int count = 0;

    sprintf(path + strlen(path), "%d", getpid());
    fp = fopen(path, "r");

    if (fp == NULL) {
        return -1;
    }

    while (fscanf(fp, "%d %s %d", &processes[count].pid, processes[count].name, &processes[count].status) == 3) {
        count++;
        if (count >= max_processes) {
            break;
        }
    }

    fclose(fp);
    return count;
}

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes;

    num_processes = get_processes(processes, MAX_PROCESSES);
    if (num_processes < 0) {
        printf("Error getting processes.\n");
        return 1;
    }

    print_processes(processes, num_processes);

    return 0;
}