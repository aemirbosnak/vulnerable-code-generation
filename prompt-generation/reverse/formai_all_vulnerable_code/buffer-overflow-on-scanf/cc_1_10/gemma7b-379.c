//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

int main()
{
    char cmd[MAX_CMD_LEN];
    char **argv;
    int argc;

    // Allocate memory for argv
    argv = malloc(MAX_CMD_LEN * sizeof(char *));

    // Loop until the user enters quit
    while (strcmp(cmd, "quit") != 0)
    {
        // Prompt the user for a command
        printf("$ ");
        scanf("%s", cmd);

        // Parse the command line
        argc = parse_cmd(cmd, argv);

        // Execute the command
        execute_cmd(argc, argv);
    }

    // Free the memory allocated for argv
    free(argv);

    return 0;
}

int parse_cmd(char *cmd, char **argv)
{
    // Tokenize the command line
    char *token = strtok(cmd, " ");

    // Count the number of tokens
    int argc = 0;

    // Create an array of arguments
    argv = malloc((argc + 1) * sizeof(char *));

    // Populate the array of arguments
    while (token)
    {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    // Add a null terminator
    argv[argc] = NULL;

    return argc;
}

int execute_cmd(int argc, char **argv)
{
    // Check if the command is valid
    if (valid_cmd(argv[0]))
    {
        // Execute the command
        system(argv[0]);
    }
    else
    {
        // Error message
        printf("Error: invalid command.\n");
    }

    return 0;
}

int valid_cmd(char *cmd)
{
    // List of valid commands
    char *valid_cmds[] = {"ls", "pwd", "mkdir", "rm", "quit"};

    // Iterate over the list of valid commands
    for (int i = 0; i < sizeof(valid_cmds) / sizeof(char *); i++)
    {
        // Check if the command is in the list
        if (strcmp(cmd, valid_cmds[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}