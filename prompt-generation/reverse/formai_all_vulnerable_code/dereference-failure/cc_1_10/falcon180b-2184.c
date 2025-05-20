//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/prctl.h>
#include <sys/resource.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 32

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int status;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(pid_t pid, const char *name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t *p = &processes[num_processes++];
    p->pid = pid;
    strncpy(p->name, name, MAX_PROCESS_NAME_LENGTH);
    p->status = 0;
}

void remove_process(int index) {
    if (index < 0 || index >= num_processes) {
        printf("Error: Invalid process index.\n");
        return;
    }

    num_processes--;
    for (int i = index; i < num_processes; i++) {
        processes[i] = processes[i + 1];
    }
}

void print_processes() {
    printf("Processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].name);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error: Failed to fork.\n");
        return 1;
    } else if (pid == 0) {
        prctl(PR_SET_NAME, command);
        execlp(command, command, NULL);
        printf("Error: Failed to execute command.\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);

        add_process(pid, command);
        print_processes();

        return 0;
    }
}