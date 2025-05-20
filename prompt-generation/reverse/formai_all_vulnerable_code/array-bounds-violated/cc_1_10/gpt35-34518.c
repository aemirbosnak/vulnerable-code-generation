//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024

/**
 * Function to parse user input into a list of arguments
 */
void parse_input(char *input, char **args)
{
    int i = 0;
    while (*input)
    {
        while (*input == ' ' || *input == '\t' || *input == '\n')
            *input++ = '\0';

        *args++ = input;

        while (*input != '\0' && *input != ' ' && *input != '\t' && *input != '\n')
            input++;
    }
    *args = NULL; // mark the end of argument list
}

/**
 * Function to execute commands
 */
void execute(char **args)
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0)
    {
        printf("Error: forking process failed.\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // child process
        if (execvp(*args, args) < 0)
        {
            printf("Error: command execution failed.\n");
            exit(1);
        }
    }
    else
    {
        // parent process
        while (wait(&status) != pid)
            ;
    }
}

int main()
{
    char input[MAX_BUFFER];
    char *args[MAX_BUFFER/2 + 1];

    while (1)
    {
        // prompt user for input
        printf(">> ");
        fflush(stdout);

        // read user input
        fgets(input, MAX_BUFFER, stdin);

        // remove trailing newline character
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        // parse input
        parse_input(input, args);

        // handle empty input
        if (args[0] == NULL)
            continue;

        // handle exit command
        if (strcmp(args[0], "exit") == 0)
            break;

        execute(args);
    }

    printf("Exiting the shell...\n");
    return 0;
}