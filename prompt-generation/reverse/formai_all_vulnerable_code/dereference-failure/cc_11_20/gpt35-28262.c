//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_ARGS 10

int main(void)
{
    char *args[MAX_ARGS];
    char history[MAX_LINE];
    int hist_pos = 0;
    int should_run = 1;

    while (should_run)
    {
        printf("USER@FUTURE-SHELL:$ ");
        fflush(stdout);

        // Read input
        char input[MAX_LINE];
        fgets(input, MAX_LINE, stdin);

        // Remove newline
        input[strcspn(input, "\n")] = 0;

        // Handle history
        if (strcmp(input, "history") == 0)
        {
            printf("Shell command history:\n");
            int i;
            for (i = 0; i < hist_pos; i++)
            {
                printf("%d: %s\n", i, history[i]);
            }
        }
        else if (input[0] == '!')
        {
            int index = atoi(input + 1);
            if (index < hist_pos)
            {
                strcpy(input, history[index]);
            }
            else
            {
                printf("Invalid history index\n");
                continue;
            }
        }

        // Handle exit
        if (strcmp(input, "exit") == 0)
        {
            should_run = 0;
            continue;
        }

        // Parse input into arguments
        int arg_pos = 0;
        char *token = strtok(input, " ");
        while (token != NULL && arg_pos < MAX_ARGS)
        {
            args[arg_pos++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_pos] = NULL;

        // Handle empty input
        if (arg_pos == 0)
        {
            continue;
        }

        // Add to history
        strcpy(history[hist_pos++], input);

        // execute command
        pid_t pid = fork();
        if (pid == 0)
        {
            execvp(args[0], args);
            printf("Command not found\n");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            printf("Fork failed\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}