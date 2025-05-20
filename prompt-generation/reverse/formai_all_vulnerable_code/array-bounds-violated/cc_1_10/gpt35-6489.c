//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

int main()
{
    char line[MAX_LINE_LENGTH + 1];
    char *args[MAX_ARGS + 1];

    while (1)
    {
        // Print prompt
        printf("$ ");

        // Read input line
        if (!fgets(line, MAX_LINE_LENGTH + 1, stdin))
        {
            // End of file / error
            break;
        }

        // Remove trailing newline
        line[strlen(line) - 1] = '\0';

        // Parse input line into arguments
        char *token = strtok(line, " ");
        int arg_count = 0;

        while (token != NULL)
        {
            args[arg_count] = token;
            arg_count++;

            if (arg_count > MAX_ARGS)
            {
                printf("Too many arguments\n");
                goto next_command;
            }

            token = strtok(NULL, " ");
        }

        args[arg_count] = NULL;

        // Run command in child process
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // Child process

            execvp(args[0], args);

            // Execution failed
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process

            // Wait for child to finish
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status))
            {
                int ret = WEXITSTATUS(status);

                if (ret != 0)
                {
                    printf("Command failed with exit code %d\n", ret);
                }
            }
            else if (WIFSIGNALED(status))
            {
                printf("Command terminated by signal %d\n", WTERMSIG(status));
            }

        }

    next_command:;
    }

    return 0;
}