//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
    char *args[MAX_LINE / 2 + 1]; /* command line arguments, as strings */
    int should_run = 1; /* flag to determine when to exit program */
    int background = 0; /* optional flag for running in background */
    while (should_run)
    {
        printf("osh>");
        fflush(stdout);

        char input[MAX_LINE];
        fgets(input, MAX_LINE, stdin);

        int length = strlen(input);
        if (input[length - 1] == '\n') /* get rid of newline */
            input[length - 1] = '\0';

        int arg_count = 0; /* number of command line arguments */
        args[arg_count] = strtok(input, " "); /* first argument */
        while (args[arg_count] != NULL)
        {
            arg_count++;
            args[arg_count] = strtok(NULL, " "); /* get next argument */
        }
        if (arg_count == 0) /* empty input */
            continue;
        if (strcmp(args[arg_count - 1], "&") == 0) /* run in background */
        {
            background = 1;
            args[arg_count - 1] = NULL;
        }
        else
            background = 0;

        pid_t pid = fork();

        if (pid < 0) /* error occurred */
        {
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if (pid == 0) /* child process */
        {
            if (execvp(args[0], args) < 0) /* execute command */
            {
                fprintf(stderr, "Command not found\n");
                return 1;
            }
        }
        else /* parent process */
        {
            if (background == 0) /* wait for child to finish */
            {
                int status;
                waitpid(pid, &status, 0);
            }
        }

        fflush(stdout);
    }
    return 0;
}