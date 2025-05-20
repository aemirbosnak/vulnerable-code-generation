//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_NUM_ARGUMENTS 10

// Define some colors for fun
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_RESET   "\x1b[0m"

// Define a function to nicely print the shell prompt
void printPrompt()
{
    printf(ANSI_GREEN "my-unixish-shell: " ANSI_RESET);
}

// Define a function to handle "cd" command
void changeDirectory(const char *directory)
{
    if(directory == NULL)
    {
        printf(ANSI_YELLOW "Usage: cd <directory>\n" ANSI_RESET);
    }
    else
    {
        if(chdir(directory) == -1)
        {
            printf(ANSI_RED "Error: Failed to change directory\n" ANSI_RESET);
        }
    }
}

int main()
{
    // Create an infinite loop for the shell
    while(1)
    {
        printPrompt();
        
        // Get the user input
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        
        // Remove the newline character at the end of user input
        input[strlen(input) - 1] = '\0';
        
        // Parse the user input into multiple arguments
        char *arguments[MAX_NUM_ARGUMENTS];
        int count = 0;
        char *token = strtok(input, " ");
        while(token != NULL && count < MAX_NUM_ARGUMENTS)
        {
            arguments[count++] = token;
            token = strtok(NULL, " ");
        }
        
        // If user just pressed enter
        if(count == 0)
        {
            continue;
        }
        
        // Handle "exit" command
        if(strcmp(arguments[0], "exit") == 0)
        {
            printf(ANSI_YELLOW "Bye!\n" ANSI_RESET);
            exit(0);
        }
        
        // Handle "cd" command
        if(strcmp(arguments[0], "cd") == 0)
        {
            changeDirectory(arguments[1]);
            continue;
        }
        
        // Create a child process and run the command in it
        pid_t pid = fork();
        if(pid == 0)
        {
            // Child process
            
            // Execute the command
            int result = execvp(arguments[0], arguments);
            
            // If the command was not found in PATH
            if(result == -1)
            {
                printf(ANSI_RED "Error: Command not found\n" ANSI_RESET);
            }
            
            // Child process should exit here
            exit(0);
        }
        else if(pid > 0)
        {
            // Parent process
            
            // Wait for child process to exit
            wait(NULL);
        }
        else
        {
            // Couldn't create child process
            printf(ANSI_RED "Error: Couldn't create child process\n" ANSI_RESET);
        }
    }

    // End of infinite loop
    return 0;
}