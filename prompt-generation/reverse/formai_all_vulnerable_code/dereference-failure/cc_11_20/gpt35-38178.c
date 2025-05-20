//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#define MAX_CMD_SIZE 1024
#define MAX_ARG_SIZE 64
#define MAX_ARGS 16

int main()
{
    char cmd[MAX_CMD_SIZE]; // variable to hold user's input command
    char *args[MAX_ARGS]; // array to hold command arguments
    char *token; // variable to hold individual argument
    
    while (1)
    {
        printf(">> "); // prompt for user input
        fgets(cmd, MAX_CMD_SIZE, stdin); // read user input
        
        // remove trailing newline character
        if ((strlen(cmd) > 0) && (cmd[strlen(cmd) - 1] == '\n'))
            cmd[strlen(cmd) - 1] = '\0';
        
        // tokenize the user input command
        int i = 0;
        token = strtok(cmd, " ");
        while (token != NULL && i < MAX_ARGS - 1)
        {
            args[i] = token; // store argument in the argument array
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL; // make sure the argument array is null-terminated
        
        if (i == 0) // user has not entered any command
            continue;
         
        // check if user wants to exit the shell
        if (strcmp(args[0], "exit") == 0)
            break;
        
        // fork a new process to execute the command
        pid_t pid = fork();
        if (pid == -1) // error forking new process
        {
            fprintf(stderr, "Error forking new process: %s\n", strerror(errno));
            continue;
        }
        else if (pid == 0) // child process
        {
            if (execvp(args[0], args) == -1) // execute the command
            {
                fprintf(stderr, "Error executing command: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        }
        else // parent process
        {
            int status;
            if (waitpid(pid, &status, 0) == -1) // wait for child process to finish
            {
                fprintf(stderr, "Error waiting for child process: %s\n", strerror(errno));
            }
        }
    }
    return EXIT_SUCCESS;
}