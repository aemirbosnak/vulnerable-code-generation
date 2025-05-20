//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int status;
} Process;

void print_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d %s %d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    FILE* fp = fopen("/proc/self/task", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/task\n");
        exit(1);
    }
    char line[MAX_PROCESS_NAME_LENGTH];
    while (fgets(line, MAX_PROCESS_NAME_LENGTH, fp)!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Too many processes\n");
            exit(1);
        }
        int len = strlen(line);
        if (line[len - 2] == '\n') {
            line[len - 2] = '\0';
        }
        strcpy(processes[num_processes].name, line);
        processes[num_processes].pid = atoi(line);
        processes[num_processes].status = 0;
        num_processes++;
    }
    fclose(fp);
    int status;
    waitpid(0, &status, 0);
    print_processes(processes, num_processes);
    return 0;
}