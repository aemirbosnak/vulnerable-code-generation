//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: ephemeral
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
    int pid;
    char name[20];
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated\n");
    }
}

int main() {
    int i, num_processes = 0;
    struct process *processes;

    processes = (struct process *)malloc(MAX_PROCESSES * sizeof(struct process));

    signal(SIGCHLD, sigchld_handler);

    while (1) {
        printf("Enter command: ");
        scanf("%s", processes[num_processes].name);

        if (num_processes >= MAX_PROCESSES) {
            printf("Maximum number of processes reached\n");
            break;
        }

        processes[num_processes].pid = fork();

        if (processes[num_processes].pid == -1) {
            printf("Fork failed\n");
        } else if (processes[num_processes].pid == 0) {
            execlp(processes[num_processes].name, processes[num_processes].name, NULL);
            exit(EXIT_FAILURE);
        } else {
            num_processes++;
        }
    }

    for (i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &processes[i].status, WNOHANG);
    }

    free(processes);
    return 0;
}