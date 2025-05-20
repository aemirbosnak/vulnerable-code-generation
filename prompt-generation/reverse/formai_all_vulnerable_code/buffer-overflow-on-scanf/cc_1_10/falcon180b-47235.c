//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    char name[16];
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated\n");
    }
}

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    signal(SIGCHLD, sigchld_handler);

    while (1) {
        printf("Enter command: ");
        char command[100];
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            print_processes(processes, num_processes);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            pid_t child_pid = fork();

            if (child_pid == 0) {
                execlp(command, command, NULL);
                exit(1);
            } else if (child_pid < 0) {
                perror("fork");
            } else {
                int status;
                waitpid(child_pid, &status, 0);
                processes[num_processes].pid = child_pid;
                processes[num_processes].status = status;
                strncpy(processes[num_processes].name, command, 15);
                num_processes++;
            }
        }
    }

    return 0;
}