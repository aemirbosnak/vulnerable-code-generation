//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100

struct process {
    pid_t pid;
    char command[64];
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("A child process has exited.\n");
    }
}

int main() {
    int i, num_processes = 0;
    struct process processes[MAX_PROCESSES];

    signal(SIGCHLD, sigchld_handler);

    printf("Enter the number of processes to monitor: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter the command for process %d: ", i + 1);
        scanf("%s", processes[i].command);
        processes[i].pid = fork();

        if (processes[i].pid == -1) {
            printf("Failed to fork process.\n");
            return 1;
        } else if (processes[i].pid == 0) {
            execlp(processes[i].command, processes[i].command, NULL);
            printf("Failed to execute process.\n");
            return 1;
        }
    }

    while (1) {
        for (i = 0; i < num_processes; i++) {
            if (kill(processes[i].pid, 0) == -1) {
                printf("Process %d has exited.\n", i + 1);
                processes[i].pid = 0;
            }
        }

        sleep(1);
    }

    return 0;
}