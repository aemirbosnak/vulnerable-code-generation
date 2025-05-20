//Falcon-180B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 10

typedef struct {
    pid_t pid;
    int status;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == -1) {
                processes[i].pid = waitpid(-1, &processes[i].status, WNOHANG);
                if (processes[i].pid == -1) {
                    printf("Process %d exited with status %d\n", processes[i].pid, processes[i].status);
                    num_processes--;
                }
                break;
            }
        }
    }
}

int launch_process(char* command) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        return -1;
    } else if (pid == 0) {
        if (execvp(command, NULL) == -1) {
            printf("Execvp failed\n");
            exit(1);
        }
    } else {
        processes[num_processes].pid = pid;
        processes[num_processes].status = 0;
        num_processes++;
        return pid;
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    while (1) {
        printf("Enter command: ");
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        int background = 0;
        if (command[strlen(command) - 1] == '&') {
            background = 1;
            command[strlen(command) - 1] = '\0';
        }

        int pid = launch_process(command);

        if (background) {
            printf("Process %d launched in background\n", pid);
        } else {
            int status;
            waitpid(pid, &status, 0);
            printf("Process %d exited with status %d\n", pid, status);
        }
    }

    return 0;
}