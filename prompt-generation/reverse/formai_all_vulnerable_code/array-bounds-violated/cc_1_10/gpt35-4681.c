//FormAI DATASET v1.0 Category: System boot optimizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 5

void printHelp();

int main()
{
    char commands[MAX_COMMANDS][10] = {"reboot", "shutdown", "optimize", "clean", "defragment", "restore", "backup", "update", "scan", "check"};
    char args[MAX_ARGS][20];
    char input[100];
    int numArgs, commandIndex, i;

    printf("Welcome to the Boot Optimizer!\n");
    printf("Type 'help' for a list of available commands.\n");

    while(1)
    {
        printf("> ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character

        // parse input into command and arguments
        numArgs = sscanf(input, "%s %s %s %s %s", commands[0], args[0], args[1], args[2], args[3]);
        if(numArgs < 1) continue;

        // match command with index
        for(i = 0; i < MAX_COMMANDS; i++)
        {
            if(strcmp(commands[0], commands[i]) == 0)
            {
                commandIndex = i;
                break;
            }
        }

        // execute command based on index
        switch(commandIndex)
        {
            case 0: // Reboot
                printf("System is rebooting...\n");
                break;

            case 1: // Shutdown
                printf("System is shutting down...\n");
                break;

            case 2: // Optimize
                printf("Optimizing file system...\n");
                break;

            case 3: // Clean
                printf("Cleaning up system files...\n");
                break;

            case 4: // Defragment
                printf("Defragmenting disk...\n");
                break;

            case 5: // Restore
                printf("Restoring system to previous state...\n");
                break;

            case 6: // Backup
                printf("Backing up system files...\n");
                break;

            case 7: // Update
                printf("Updating system...\n");
                break;

            case 8: // Scan
                printf("Scanning system for viruses...\n");
                break;

            case 9: // Check
                printf("Checking system for errors...\n");
                break;

            default:
                printf("Invalid command. Type 'help' for a list of available commands.\n");
                break;
        }

        // clear arguments for next iteration
        for(i = 0; i < MAX_ARGS; i++)
        {
            strcpy(args[i], "");
        }

    }

    return 0;
}

void printHelp()
{
    printf("Available commands:\n");
    printf("reboot\n");
    printf("shutdown\n");
    printf("optimize\n"); 
    printf("clean\n");
    printf("defragment\n");
    printf("restore\n");
    printf("backup\n");
    printf("update\n");
    printf("scan\n");
    printf("check\n");
}