//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated.\n");
    }
}

int main() {
    int i, j, num_processes = 0;
    pid_t pid;
    struct process processes[MAX_PROCESSES];

    signal(SIGCHLD, sigchld_handler);

    printf("Enter number of processes to monitor: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter process %d command: ", i + 1);
        scanf("%s", processes[i].command);
        processes[i].pid = fork();

        if (processes[i].pid == 0) {
            execlp(processes[i].command, processes[i].command, NULL);
            exit(1);
        } else if (processes[i].pid < 0) {
            printf("Fork failed.\n");
            exit(1);
        }
    }

    while (1) {
        for (i = 0; i < num_processes; i++) {
            pid = waitpid(processes[i].pid, &processes[i].status, WNOHANG);

            if (pid == processes[i].pid) {
                if (WIFEXITED(processes[i].status)) {
                    printf("Process %d exited with status %d.\n", i + 1, WEXITSTATUS(processes[i].status));
                } else if (WIFSIGNALED(processes[i].status)) {
                    printf("Process %d terminated by signal %d.\n", i + 1, WTERMSIG(processes[i].status));
                } else if (WIFSTOPPED(processes[i].status)) {
                    printf("Process %d stopped by signal %d.\n", i + 1, WSTOPSIG(processes[i].status));
                } else {
                    printf("Process %d status unknown.\n", i + 1);
                }

                processes[i].pid = 0;
            }
        }

        sleep(1);
    }

    return 0;
}