//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define BUF_SIZE 256

int main(int argc, char *argv[]) {
    int exit_status = 0;
    while (1) {
        char *cmd, *args[MAX_ARGS], *tok;
        char buf[BUF_SIZE];
        int arg_count = 0, bg_exec = 0, append_flag = 0, i, fd_out;
		
        printf("$ ");

        if (!fgets(buf, BUF_SIZE, stdin)) break;

        // Parse cmd and args
        cmd = strtok(buf, " \n");

        args[0] = cmd;
        arg_count++;

        while ((tok = strtok(NULL, " \n"))) {
            if (strcmp(tok, "&") == 0) {
                bg_exec = 1;
            } else if (strcmp(tok, ">") == 0) {
                append_flag = 0;
                fd_out = open(strtok(NULL, " \n"), O_WRONLY | O_CREAT | O_TRUNC, 0644);
            } else if (strcmp(tok, ">>") == 0) {
                append_flag = 1;
                fd_out = open(strtok(NULL, " \n"), O_WRONLY | O_CREAT | O_APPEND, 0644);
            } else {
                args[arg_count] = tok;
                arg_count++;
            }
        }

        args[arg_count] = NULL;

        // Handle built-in commands
        if (strcmp(cmd, "exit") == 0) {
            break;
        } else if (strcmp(cmd, "cd") == 0) {
            chdir(args[1]);
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            printf("Fork error!\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            if (bg_exec) {
                setpgid(0, 0);
            }
            if (fd_out) {
                dup2(fd_out, STDOUT_FILENO);
            }
            execvp(cmd, args);
            printf("Command not found: %s\n", cmd);
            exit(1);
        } else {
            // Parent process
            if (!bg_exec) {
                waitpid(pid, &exit_status, 0);
            }
            if (fd_out) {
                close(fd_out);
            }
        }
    }

    return exit_status;
}