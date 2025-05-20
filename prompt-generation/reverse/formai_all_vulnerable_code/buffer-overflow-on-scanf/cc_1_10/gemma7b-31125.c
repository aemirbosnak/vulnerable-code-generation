//Gemma-7B DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

int main()
{
    char cmd[MAX_CMD_LEN];
    char **commands = NULL;
    int num_commands = 0;

    printf("Welcome to the C System Administration Shell!\n");
    printf("Type 'help' for a list of commands.\n");

    while (1)
    {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        if (strcmp(cmd, "help") == 0)
        {
            printf("Available commands:\n");
            for (int i = 0; i < num_commands; i++)
            {
                printf("%s\n", commands[i]);
            }
        }
        else if (strcmp(cmd, "add") == 0)
        {
            commands = realloc(commands, (num_commands + 1) * sizeof(char *));
            commands[num_commands++] = malloc(MAX_CMD_LEN);
            printf("Enter the command you want to add: ");
            fgets(commands[num_commands - 1], MAX_CMD_LEN, stdin);
        }
        else if (strcmp(cmd, "rm") == 0)
        {
            printf("Enter the index of the command you want to remove: ");
            int index;
            scanf("%d", &index);

            if (index >= 0 && index < num_commands)
            {
                free(commands[index]);
                commands = realloc(commands, (num_commands - 1) * sizeof(char *));
                num_commands--;
            }
            else
            {
                printf("Invalid index.\n");
            }
        }
        else if (strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}