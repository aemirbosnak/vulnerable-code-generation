//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 10

void execute_command(char* cmd);

int main(int argc, char* argv[]) {
    char input[MAX_CMD_LEN];
    char* cmd;
    while (1) {
        printf("> ");
        fgets(input, MAX_CMD_LEN, stdin);
        if (input[strlen(input)-1] == '\n')
            input[strlen(input)-1] = '\0';
        if (strcmp(input, "exit") == 0) {
            break;
        }
        pid_t pid;
        if ((pid = fork()) == -1) {
            perror("fork error");
            continue;
        }
        if (pid == 0) {
            execute_command(input);
            exit(EXIT_SUCCESS);
        }
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid error");
        }
    }
    return 0;
}

void execute_command(char* cmd) {
    int arg_num = 0;
    char* args[MAX_ARGS];
    char* token = strtok(cmd, " ");
    while (token != NULL && arg_num < MAX_ARGS-1) {
        args[arg_num++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_num] = NULL;
    int fd;
    if ((fd = open("/dev/null", O_WRONLY)) == -1) {
        perror("open error");
        return;
    }
    if (dup2(fd, STDERR_FILENO) == -1) {
        perror("dup2 error");
        return;
    }
    close(fd);
    if (execvp(args[0], args) == -1) {
        fprintf(stderr, "execvp error (errno=%d)\n", errno);
        return;
    }
}