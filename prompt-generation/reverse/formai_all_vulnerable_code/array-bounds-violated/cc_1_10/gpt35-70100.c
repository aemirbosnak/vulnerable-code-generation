//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LENGTH 100
#define MAX_NUM_ARGS 10

void execute_command(char* arg_list[])
{
    pid_t pid = fork();
    
    if(pid < 0)
    {
        perror("Failed to fork");
    }
    else if(pid == 0)
    {
        // Child process
        if(execvp(arg_list[0], arg_list) < 0)
        {
            perror("Failed to execute command");
        }
        exit(0);
    }
    else
    {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

int main()
{
    char command[MAX_CMD_LENGTH];
    char* arg_list[MAX_NUM_ARGS + 1];
    int num_args;
    
    while(1)
    {
        printf(">> ");
        fgets(command, MAX_CMD_LENGTH, stdin);
        command[strlen(command) - 1] = '\0';
        
        if(strcmp(command, "exit") == 0)
            break;
        
        num_args = 0;
        arg_list[num_args] = strtok(command, " ");
        while(arg_list[num_args] != NULL && num_args < MAX_NUM_ARGS)
        {
            num_args++;
            arg_list[num_args] = strtok(NULL, " ");
        }
        arg_list[num_args] = NULL;
        
        if(num_args > 0)
        {
            execute_command(arg_list);
        }
    }
    
    return 0;
}