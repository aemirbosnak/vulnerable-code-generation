//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

struct process {
    int pid;
    char name[1024];
    int status;
};

void print_processes(struct process *processes, int count) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    FILE *fp;
    char line[BUFFER_SIZE];
    int count = 0;
    struct process *processes = malloc(sizeof(struct process) * 1024);

    if ((fp = fopen("/proc/self/status", "r"))!= NULL) {
        while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
            if (strstr(line, "Name:")!= NULL) {
                sscanf(line, "Name:\t%s", processes[count].name);
            } else if (strstr(line, "State:")!= NULL) {
                sscanf(line, "State:\t%d", &processes[count].status);
            }
        }
        fclose(fp);
        count++;
    }

    int *pids = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        pids[i] = processes[i].pid;
    }

    waitpid(0, NULL, 0);

    free(processes);
    free(pids);

    return 0;
}