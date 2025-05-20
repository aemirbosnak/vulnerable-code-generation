//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_NUM_ARGUMENTS 10

int main()
{
    char *commands[MAX_COMMAND_LENGTH / 2 + 1];
    char command[MAX_COMMAND_LENGTH];
    while (1)
    {
        printf("myshell > ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline char
        command[strlen(command) - 1] = '\0';

        // Tokenize the command
        int i = 0;
        char *token = strtok(command, " ");
        while (token != NULL)
        {
            commands[i++] = token;
            token = strtok(NULL, " ");
        }
        commands[i] = NULL;

        if (commands[0] == NULL)
            continue;

        if (strcmp(commands[0], "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        pid_t pid = fork();
        if (pid == -1)
        {
            printf("Error: failed to fork child process\n");
            continue;
        }
        else if (pid == 0)
        {
            // Child process
            execvp(commands[0], commands);
            printf("Error: failed to execute command \"%s\"\n", commands[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}