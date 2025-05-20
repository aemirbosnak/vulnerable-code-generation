//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " "

char **split_command(char *command)
{
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork_and_exec(char **argv)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    }

    return pid;
}

int main()
{
    char input[MAX_COMMAND_LENGTH];
    char **args = NULL;
    pid_t pid;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_command(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        } else if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                printf("%s\n", cwd);
            } else {
                perror("getcwd");
            }
        } else {
            pid = fork_and_exec(args);
            if (pid < 0) {
                exit(1);
            }
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}