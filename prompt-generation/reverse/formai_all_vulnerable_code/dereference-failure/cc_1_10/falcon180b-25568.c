//Falcon-180B DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_BACKGROUND_PROCESSES 10

typedef struct {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
} process_t;

static int num_processes = 0;
static process_t processes[MAX_BACKGROUND_PROCESSES];

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == -1) {
                processes[i].pid = waitpid(0, &processes[i].status, WNOHANG);
                if (processes[i].pid == -1) {
                    fprintf(stderr, "Error: process %d terminated abnormally.\n", processes[i].pid);
                    exit(1);
                }
                break;
            }
        }
    }
}

int launch_process(char* command) {
    if (num_processes >= MAX_BACKGROUND_PROCESSES) {
        fprintf(stderr, "Error: too many background processes.\n");
        return -1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed.\n");
        return -1;
    } else if (pid == 0) {
        if (execvp(command, NULL) == -1) {
            fprintf(stderr, "Error: execvp failed.\n");
            exit(1);
        }
    } else {
        processes[num_processes].pid = pid;
        processes[num_processes].status = 0;
        strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
        num_processes++;

        signal(SIGCHLD, sigchld_handler);
    }

    return pid;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        return 1;
    }

    char* command = argv[1];
    int pid = launch_process(command);

    if (pid == -1) {
        return 1;
    } else {
        waitpid(pid, NULL, 0);
        return 0;
    }
}