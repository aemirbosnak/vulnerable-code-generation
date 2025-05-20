//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    char command[MAX_LINE]; /* user input command */
    int should_run = 1; /* flag to determine when to exit program */
    int background = 0; /* flag for running a command in the background */
    int status; /* status of child process */
    pid_t pid; /* process id */

    while (should_run)
    {
        printf("Shell-Basic$ "); /* Output prompt */
        fflush(stdout); /* Flush the output buffer */

        /* Read input command from user */
        fgets(command, MAX_LINE, stdin);

        /* Replace the new line character with null terminator */
        command[strcspn(command, "\n")] = '\0';

        /* Tokenize the command string into arguments array */
        char *token = strtok(command, " ");
        int index = 0;
        while (token != NULL) {
            args[index] = token;
            index++;
            token = strtok(NULL, " ");
        }
        args[index] = NULL; /* add null terminator at the end */

        /* Check if the command should be run in background */
        if (strcmp(args[index-1], "&") == 0) {
            background = 1;
            args[index-1] = NULL; /* remove the '&' argument */
        }

        /* Fork a child process */
        pid = fork();

        if (pid < 0) { /* error occurred */
            fprintf(stderr, "Fork failed\n");
            exit(1);
        }
        else if (pid == 0) { /* child process */
            if (execvp(args[0], args) < 0) { /* execute the command */
                fprintf(stderr, "%s: Command not found\n", args[0]);
                exit(1);
            }
        }
        else { /* parent process */
            if (background == 0) { /* wait for child process to finish if not running in background */
                waitpid(pid, &status, 0);
            }
        }
        memset(args, 0, sizeof(args)); /* clear the arguments array */
        background = 0; /* reset the background flag */
    }

    return 0;
}