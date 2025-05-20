//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_ARGS 25
#define MAX_CMD_LENGTH 100

int main()
{
    printf("Welcome to the Unix-like Shell Program!\n");

    char* cmd_args[MAX_CMD_ARGS];
    char cmd_buffer[MAX_CMD_LENGTH];
    int status;

    while(1)
    {
        printf("$ ");

        if(fgets(cmd_buffer, MAX_CMD_LENGTH, stdin) == NULL)
        {
            printf("Exiting the shell program\n");
            break;
        }

        if(cmd_buffer[strlen(cmd_buffer)-1] == '\n')
        {
            cmd_buffer[strlen(cmd_buffer)-1] = '\0';
        }

        int num_cmd_args = 0;
        cmd_args[num_cmd_args] = strtok(cmd_buffer, " ");

        while(cmd_args[num_cmd_args] != NULL && num_cmd_args < MAX_CMD_ARGS-1)
        {
            num_cmd_args++;
            cmd_args[num_cmd_args] = strtok(NULL, " ");
        }

        cmd_args[num_cmd_args] = NULL;

        if(strcmp(cmd_args[0], "exit") == 0)
        {
            printf("Exiting the shell program\n");
            break;
        }

        pid_t pid = fork();

        if(pid < 0)
        {
            printf("Failed to create a child process\n");
            exit(-1);
        }

        if(pid == 0)
        {
            execvp(cmd_args[0], cmd_args);
            printf("Failed to execute the command\n");
            exit(-1);
        }

        waitpid(pid, &status, 0);

        if(WIFEXITED(status))
        {
            printf("Command exited with status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}