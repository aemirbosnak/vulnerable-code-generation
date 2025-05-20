//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
};

int num_processes = 0;
struct process processes[MAX_PROCESSES];

void add_process(int pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Too many processes\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command to start or 'q' to quit: ");
        scanf("%s", command);

        if (strcmp(command, "q") == 0) {
            break;
        }

        int pid = fork();

        if (pid == 0) {
            ptrace(PTRACE_TRACEME, 0, 0, 0);
            execlp(command, command, NULL);
            exit(1);
        } else if (pid < 0) {
            printf("Error forking process\n");
        } else {
            add_process(pid, command);
            wait(NULL);
        }
    }

    return 0;
}