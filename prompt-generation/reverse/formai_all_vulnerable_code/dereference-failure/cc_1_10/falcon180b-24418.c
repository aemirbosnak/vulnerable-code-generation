//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 100

struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
};

void print_processes(struct process processes[], int num_processes) {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        char input[MAX_COMMAND_LENGTH];
        printf("Enter command to run (or type 'q' to quit): ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "q") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            int status;
            if (execvp(input, NULL) == -1) {
                printf("Error: %s\n", strerror(errno));
                exit(1);
            }
        } else if (pid < 0) {
            // Fork error
            printf("Error: %s\n", strerror(errno));
        } else {
            // Parent process
            processes[num_processes].pid = pid;
            strncpy(processes[num_processes].command, input, MAX_COMMAND_LENGTH - 1);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';
            num_processes++;
        }
    }

    int status;
    while (waitpid(0, &status, WNOHANG) > 0) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == status) {
                processes[i].status = WEXITSTATUS(status);
                break;
            }
        }
    }

    print_processes(processes, num_processes);

    return 0;
}