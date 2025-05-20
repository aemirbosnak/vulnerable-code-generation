//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
// include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024 // maximum command length
#define MAX_NUM_ARGUMENTS 10 // maximum number of arguments

int main()
{
    char command[MAX_COMMAND_LENGTH]; // command string
    char *args[MAX_NUM_ARGUMENTS]; // array to store arguments
    int status; // status returned by waitpid()

    while(1) // infinite loop
    {  
        printf("shell> "); // print shell prompt
        fgets(command, MAX_COMMAND_LENGTH, stdin); // read user input
        command[strlen(command) - 1] = '\0'; // remove newline character
        
        char *token = strtok(command, " "); // tokenize input string
        int i = 0;
        while(token != NULL && i < MAX_NUM_ARGUMENTS - 1)
        {
            args[i] = token; // store argument
            i++;
            token = strtok(NULL, " "); // move to next token
        }
        args[i] = NULL; // terminate argument list with NULL
        
        if(args[0] == NULL) // check if command is empty
            continue;
        
        if(strcmp(args[0], "exit") == 0) // check if user wants to exit
            break;
        
        pid_t pid = fork(); // create child process
        if(pid == -1) // check for error
        {
            perror("fork");
            exit(1);
        }
        else if(pid == 0) // child process
        {
            execvp(args[0], args); // execute command
            perror(args[0]); // check for error
            exit(1);
        }
        else // parent process
        {
            waitpid(pid, &status, 0); // wait for child process to finish
        }
    }
    return 0; // terminate program
}