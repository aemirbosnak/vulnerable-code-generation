//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_COMMAND_LENGTH 100      // maximum command length
#define MAX_NUM_ARGUMENTS 10        // maximum number of arguments in a command

int main()
{
    char command[MAX_COMMAND_LENGTH];  // stores the command entered by the user
    char *argument[MAX_NUM_ARGUMENTS]; // stores the arguments passed in the command
    int status, i;

    while(1)    // infinite loop until the user enters the 'exit' command
    {
        printf("-> ");  // shell prompt

        fgets(command, MAX_COMMAND_LENGTH, stdin);   // read command from the user
        command[strlen(command)-1] = '\0';  // replace the new line character at the end with null character

        if(strcmp(command, "exit")==0)  // exit command to close the shell
        {
            exit(0);    // exit the shell with status 0
        }

        pid_t pid = fork(); // create a new process using fork()

        if(pid == 0)    // child process
        {
            // tokenize the command and store each argument as a separate string in the argument array
            argument[0] = strtok(command, " ");
            for(i=1; i<MAX_NUM_ARGUMENTS; i++)
            {
                argument[i] = strtok(NULL, " ");
                if(argument[i] == NULL) // break if no more arguments are there
                {
                    break;
                }
            }

            // execute the command using execvp() system call
            execvp(argument[0], argument);

            // print an error message if the execution fails
            printf("Command not found!\n");
            exit(1);    // exit child process with status 1
        }
        else if(pid < 0)    // fork() failed
        {
            printf("Fork Failed!\n");
            exit(1);    // exit parent process with status 1
        }
        else    // parent process
        {
            waitpid(pid, &status, 0);   // wait for child process to finish
        }
    }

    return 0;
}