//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 100

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        char input[MAX_COMMAND_LENGTH];
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error forking\n");
        } else if (pid == 0) {
            strcpy(processes[num_processes].command, input);
            processes[num_processes].pid = getpid();
            processes[num_processes].status = 0;
            num_processes++;
            execlp("/bin/sh", "sh", "-c", input, NULL);
        } else {
            int status;
            waitpid(pid, &status, 0);
            processes[--num_processes].status = status;
        }
    }

    print_processes(processes, num_processes);

    return 0;
}