//Falcon-180B DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

typedef struct {
    char *command;
    pid_t pid;
    int status;
    int exit_signal;
} process_t;

void execute_command(process_t *process);
void handle_child_process(int signum, siginfo_t *info, void *context);

int main() {
    process_t child_process;

    printf("Enter command to execute: ");
    fgets(child_process.command, MAX_COMMAND_LENGTH, stdin);
    child_process.command[strcspn(child_process.command, "\n")] = '\0';

    printf("Executing command: %s\n", child_process.command);

    child_process.pid = fork();

    if (child_process.pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (child_process.pid == 0) {
        execute_command(&child_process);
        exit(0);
    } else {
        signal(SIGCHLD, handle_child_process);
        while (waitpid(child_process.pid, &child_process.status, WUNTRACED)!= child_process.pid) {
            sleep(1);
        }
        printf("Child process exited with status %d\n", child_process.status);
    }

    return 0;
}

void execute_command(process_t *process) {
    char *args[3];
    args[0] = "sh";
    args[1] = "-c";
    args[2] = process->command;

    execvp(args[0], args);

    perror("Error executing command");
    exit(1);
}

void handle_child_process(int signum, siginfo_t *info, void *context) {
    process_t *process = (process_t *) context;

    if (info->si_code == CLD_EXITED) {
        process->exit_signal = info->si_status;
    } else if (info->si_code == CLD_KILLED || info->si_code == CLD_DUMPED) {
        process->exit_signal = SIGKILL;
    } else {
        process->exit_signal = SIGTERM;
    }

    printf("Child process %d exited with signal %d\n", process->pid, process->exit_signal);
}