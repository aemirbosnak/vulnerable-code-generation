//Code Llama-13B DATASET v1.0 Category: System administration ; Style: protected
/*
 * C System Administration Example Program
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 10

typedef struct {
    char* cmd;
    char* args[MAX_ARGS];
} cmd_t;

int run_cmd(cmd_t* cmd) {
    int status;
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        // Child process
        execvp(cmd->cmd, cmd->args);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(&status);
        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) == 0) {
                return 0;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        // Fork failed
        return -1;
    }
}

int main(int argc, char* argv[]) {
    cmd_t cmd;
    cmd.cmd = argv[1];
    for (int i = 2; i < argc; i++) {
        cmd.args[i - 2] = argv[i];
    }
    if (run_cmd(&cmd) == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command execution failed.\n");
    }
    return 0;
}