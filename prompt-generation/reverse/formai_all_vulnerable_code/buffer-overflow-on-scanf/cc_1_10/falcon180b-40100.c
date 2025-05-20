//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    char name[50];
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated\n");
    }
}

int main() {
    int num_processes = 0;
    struct process processes[MAX_PROCESSES];
    int status;
    int i = 0;

    signal(SIGCHLD, sigchld_handler);

    while (num_processes < MAX_PROCESSES) {
        printf("Enter process name: ");
        scanf("%s", processes[num_processes].name);

        processes[num_processes].pid = fork();

        if (processes[num_processes].pid == 0) {
            execlp(processes[num_processes].name, processes[num_processes].name, NULL);
            exit(1);
        }
        else if (processes[num_processes].pid < 0) {
            perror("Fork");
            exit(1);
        }
        else {
            printf("Process %s started with PID %d\n", processes[num_processes].name, processes[num_processes].pid);
            num_processes++;
        }
    }

    while (num_processes > 0) {
        for (i = 0; i < num_processes; i++) {
            if (waitpid(processes[i].pid, &status, WNOHANG) == processes[i].pid) {
                printf("Process %s terminated with status %d\n", processes[i].name, status);
                num_processes--;
                memmove(&processes[i], &processes[num_processes], sizeof(struct process));
            }
        }
        sleep(1);
    }

    return 0;
}