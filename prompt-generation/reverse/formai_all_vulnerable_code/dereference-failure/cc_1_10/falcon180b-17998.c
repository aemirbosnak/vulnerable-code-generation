//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESS 100

typedef struct {
    int pid;
    char name[64];
    int status;
} process;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        exit(1);
    }

    int pid = atoi(argv[1]);

    if (kill(pid, 0) == -1) {
        printf("Process %d not found\n", pid);
        exit(1);
    }

    process *procs = malloc(MAX_PROCESS * sizeof(process));
    int num_procs = 0;

    FILE *fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/status\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(procs[num_procs].name, line + 6);
        } else if (strncmp(line, "Pid:", 4) == 0) {
            procs[num_procs].pid = atoi(line + 5);
        } else if (strncmp(line, "State:", 6) == 0) {
            procs[num_procs].status = atoi(line + 7);
        }
        num_procs++;
    }

    fclose(fp);

    int i;
    for (i = 0; i < num_procs; i++) {
        if (procs[i].pid == pid) {
            printf("Process %d: %s\n", procs[i].pid, procs[i].name);
            printf("State: %d\n", procs[i].status);
            break;
        }
    }

    free(procs);

    return 0;
}