//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_PID_LENGTH 6

typedef struct process {
    pid_t pid;
    char name[MAX_PID_LENGTH];
    int status;
} Process;

void print_processes(Process* processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].status!= 0) {
            printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int status;
    char command[80];
    pid_t pid;

    while (1) {
        printf("Enter command (ps to view processes, kill PID to terminate process, exit to quit): ");
        scanf("%s", command);

        if (strcmp(command, "ps") == 0) {
            print_processes(processes);
        } else if (strcmp(command, "kill") == 0) {
            scanf("%d", &pid);
            kill(pid, SIGTERM);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                printf("Fork failed\n");
            } else if (child_pid == 0) {
                if (num_processes >= MAX_PROCESSES) {
                    printf("Too many processes\n");
                    exit(1);
                }

                strncpy(processes[num_processes].name, command, MAX_PID_LENGTH);
                processes[num_processes].pid = getpid();
                processes[num_processes].status = 0;
                num_processes++;

                execlp("/bin/sh", "sh", "-c", command, NULL);
                perror("execlp");
                exit(1);
            } else {
                waitpid(child_pid, &status, 0);

                if (WIFEXITED(status)) {
                    processes[--num_processes].status = WEXITSTATUS(status);
                } else if (WIFSIGNALED(status)) {
                    processes[--num_processes].status = WTERMSIG(status);
                }
            }
        }
    }

    return 0;
}