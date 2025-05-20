//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>

#define MAX_CMD_LEN 1024
#define MAX_CMD_ARGS 50

void sig_handler(int signo)
{
    int status;
    pid_t pid;

    while((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        printf("child process %d exited with status %d\n", pid, WEXITSTATUS(status));
    }
}

void execute(char **args)
{
    pid_t pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }

    if(pid == 0)
    {
        if(execvp(args[0], args) == -1)
        {
            printf("Error executing command\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main()
{
    signal(SIGCHLD, sig_handler); // Register signal handler for child process termination

    char cmd[MAX_CMD_LEN];
    char *cmd_args[MAX_CMD_ARGS];
    char *token;
    int i;

    while(1)
    {
        printf("$> ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        cmd[strlen(cmd) - 1] = 0;

        if(strcmp(cmd, "exit") == 0)
        {
            break;
        }

        i = 0;
        token = strtok(cmd, " ");

        while(token != NULL)
        {
            cmd_args[i++] = token;
            token = strtok(NULL, " ");
        }

        cmd_args[i] = NULL;

        execute(cmd_args);
    }

    return 0;
}