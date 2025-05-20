//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 100
#define MAX_LINE 1000

char **split_line(char *line);
int execute_command(char **args);
void handle_signal(int signum);

int main()
{
    char input_buffer[MAX_LINE];
    char **args;
    int status;

    signal(SIGINT, handle_signal);
    while(1)
    {
        printf("> ");
        fgets(input_buffer, MAX_LINE, stdin);

        args = split_line(input_buffer);
        if(args == NULL)
        {
            printf("Error: Too many arguments\n");
            continue;
        }

        if(strcmp(args[0], "exit") == 0)
        {
            break;
        }

        status = execute_command(args);
        if(status == -1)
        {
            printf("Error: Command not found\n");
        }
    }

    return 0;
}

char **split_line(char *line)
{
    int count = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    if(args == NULL)
    {
        return NULL;
    }

    char *token = strtok(line, " ");
    while(token!= NULL)
    {
        args[count] = token;
        count++;
        if(count >= MAX_ARGUMENTS)
        {
            break;
        }
        token = strtok(NULL, " ");
    }

    args[count] = NULL;
    return args;
}

int execute_command(char **args)
{
    pid_t pid;
    int status;

    if(args[0] == NULL)
    {
        return -1;
    }

    if(strcmp(args[0], "cd") == 0)
    {
        if(args[1] == NULL)
        {
            printf("Error: Directory not specified\n");
            return 1;
        }
        if(chdir(args[1])!= 0)
        {
            perror("chdir");
            return 1;
        }
    }
    else if(strcmp(args[0], "pwd") == 0)
    {
        char cwd[1024];
        if(getcwd(cwd, sizeof(cwd))!= NULL)
        {
            printf("%s\n", cwd);
        }
    }
    else
    {
        pid = fork();
        if(pid == -1)
        {
            perror("fork");
            return 1;
        }
        else if(pid == 0)
        {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void handle_signal(int signum)
{
    if(signum == SIGINT)
    {
        printf("\nInterrupted\n");
    }
}