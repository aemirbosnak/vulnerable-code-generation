//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
};

int num_processes = 0;
struct process processes[MAX_PROCESSES];

void add_process(int pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        fprintf(stderr, "Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
    processes[num_processes].status = 0;

    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            break;
        }
    }
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            printf("%d: %s\n", processes[i].pid, processes[i].command);
        }
    }
}

int main(int argc, char** argv) {
    int i;
    char input[MAX_COMMAND_LENGTH];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        return 1;
    }

    strncpy(input, argv[1], MAX_COMMAND_LENGTH);

    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execlp(input, input, NULL) == -1) {
            fprintf(stderr, "Error: Exec failed.\n");
            return 1;
        }
    } else {
        add_process(pid, input);

        while (num_processes > 0) {
            print_processes();
            sleep(1);
        }
    }

    return 0;
}