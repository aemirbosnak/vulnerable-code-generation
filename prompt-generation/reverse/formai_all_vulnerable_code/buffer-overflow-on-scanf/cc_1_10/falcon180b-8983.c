//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_PROCESS_NUM 100
#define BUF_SIZE 1024

typedef struct {
    pid_t pid;
    char name[64];
    int status;
} Process;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // do nothing
    }
}

int main() {
    int i, j, num_processes = 0;
    Process processes[MAX_PROCESS_NUM];
    char command[BUF_SIZE];
    pid_t pid;
    int status;

    signal(SIGCHLD, sigchld_handler);

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter the command for process %d: ", i + 1);
        scanf("%s", command);

        pid = fork();
        if (pid == -1) {
            printf("Failed to fork.\n");
            exit(1);
        } else if (pid == 0) {
            execlp(command, command, NULL);
            exit(1);
        } else {
            processes[i].pid = pid;
            strcpy(processes[i].name, command);
            processes[i].status = 0;
        }
    }

    while (num_processes > 0) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].status == 0) {
                pid = waitpid(processes[i].pid, &status, WNOHANG);
                if (pid == processes[i].pid) {
                    processes[i].status = status;
                }
            }
        }
        usleep(100000);
    }

    for (i = 0; i < num_processes; i++) {
        printf("Process %d: %s\n", i + 1, processes[i].name);
        printf("Status: %d\n", processes[i].status);
        printf("\n");
    }

    return 0;
}