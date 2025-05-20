//Falcon-180B DATASET v1.0 Category: System administration ; Style: protected
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
#define MAX_PROCESSES 10
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
} process_t;

void run_command(process_t *process) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("Error forking process: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        execlp(process->command, process->command, NULL);
        printf("Error executing command: %s\n", strerror(errno));
        exit(1);
    } else {
        process->pid = child_pid;
    }
}

void wait_for_process(process_t *process) {
    int status;
    waitpid(process->pid, &status, WUNTRACED);

    if (WIFEXITED(status)) {
        process->status = WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        process->status = WTERMSIG(status);
    } else {
        process->status = -1;
    }
}

void kill_process(process_t *process) {
    kill(process->pid, SIGKILL);
    waitpid(process->pid, NULL, 0);
}

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        printf("Enter command (or type 'exit' to quit): ");
        fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(processes[num_processes].command, "exit") == 0) {
            break;
        }

        run_command(&processes[num_processes]);
        num_processes++;
    }

    while (num_processes > 0) {
        for (int i = 0; i < num_processes; i++) {
            wait_for_process(&processes[i]);

            if (processes[i].status!= -1) {
                printf("Process %d exited with status %d\n", processes[i].pid, processes[i].status);
            }

            num_processes--;
            i--;
        }
    }

    return 0;
}