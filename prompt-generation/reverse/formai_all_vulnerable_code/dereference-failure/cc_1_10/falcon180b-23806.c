//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 512
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(void);

int main(void)
{
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    pid_t child_pid;

    print_prompt();

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL)
    {
        args = split_command(input_buffer);

        if (args[0] == NULL)
        {
            continue;
        }

        child_pid = fork();

        if (child_pid == -1)
        {
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        }
        else if (child_pid == 0)
        {
            execute_command(args);
            exit(0);
        }
        else
        {
            waitpid(child_pid, NULL, WUNTRACED);
        }
    }

    return 0;
}

char **split_command(char *command)
{
    char **args = malloc(sizeof(char *));
    args[0] = strtok(command, DELIM);
    int arg_count = 1;

    while (args[arg_count - 1]!= NULL)
    {
        args = realloc(args, sizeof(char *) * (arg_count + 1));
        args[arg_count] = strtok(NULL, DELIM);
        arg_count++;
    }

    args[arg_count] = NULL;

    return args;
}

pid_t fork(void)
{
    return fork();
}

int execute_command(char **args)
{
    pid_t pid;
    int status;

    if (args[0] == NULL)
    {
        return 1;
    }

    pid = fork();

    if (pid == -1)
    {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            fprintf(stderr, "Execvp failed.\n");
            exit(1);
        }
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
    }

    return 0;
}

void print_prompt(void)
{
    printf("> ");
}