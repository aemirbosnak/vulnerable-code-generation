//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 100

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

void print_processes(process_t processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d - %s (%d)\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter a command to run or type 'q' to quit: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "q") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            if (execlp(input, input, NULL) == -1) {
                fprintf(stderr, "Error executing command: %s\n", strerror(errno));
                exit(1);
            }
        } else if (pid < 0) {
            fprintf(stderr, "Error forking process: %s\n", strerror(errno));
        } else {
            processes[num_processes].pid = pid;
            processes[num_processes].status = 0;
            strcpy(processes[num_processes].command, input);
            num_processes++;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &processes[i].status, WNOHANG);
    }

    print_processes(processes, num_processes);

    return 0;
}