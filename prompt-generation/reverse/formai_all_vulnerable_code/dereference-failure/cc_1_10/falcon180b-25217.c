//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
    int exit_code;
} process_t;

void print_processes(process_t processes[], int num_processes) {
    printf("PID\tCommand\tStatus\tExit Code\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\n", processes[i].pid, processes[i].command, processes[i].status, processes[i].exit_code);
    }
}

void monitor_processes(process_t processes[], int num_processes) {
    while (1) {
        int max_processes = waitpid(-1, NULL, WNOHANG);
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid > 0) {
                int pid = waitpid(processes[i].pid, &processes[i].status, WNOHANG);
                if (pid == processes[i].pid) {
                    processes[i].exit_code = WEXITSTATUS(processes[i].status);
                    processes[i].pid = 0;
                }
            }
        }
        if (max_processes <= 0) {
            usleep(100000);
        } else {
            print_processes(processes, num_processes);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH] = {0};
    strncat(command, argv[1], strlen(argv[1]));

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execlp(command, command, NULL);
        perror("execlp");
        return 1;
    }

    process_t process = {0};
    process.pid = pid;
    strncat(process.command, command, strlen(command));

    process_t processes[MAX_PROCESSES] = {0};
    int num_processes = 1;
    processes[0] = process;

    monitor_processes(processes, num_processes);

    return 0;
}