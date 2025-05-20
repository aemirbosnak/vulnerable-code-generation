//Falcon-180B DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_PROCESSES 10

struct process {
    pid_t pid;
    char *name;
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated.\n");
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    int num_processes = 0;
    struct process processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        printf("Enter name of process to start: ");
        scanf("%s", processes[num_processes].name);

        processes[num_processes].pid = fork();

        if (processes[num_processes].pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        } else if (processes[num_processes].pid == 0) {
            execlp(processes[num_processes].name, processes[num_processes].name, NULL);
            printf("Child process %s started.\n", processes[num_processes].name);
            exit(0);
        } else {
            num_processes++;
        }
    }

    while (num_processes > 0) {
        int status;
        pid_t pid = wait(&status);

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == pid) {
                processes[i].status = status;
                printf("Process %s terminated with status %d.\n", processes[i].name, status);
                num_processes--;
                break;
            }
        }
    }

    return 0;
}