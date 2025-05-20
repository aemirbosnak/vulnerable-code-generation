//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char cmd[100]; // buffer to store user input
    pid_t pid; // process ID
    int status; // status of child process

    while(1)
    {
        printf("shell$ ");
        fgets(cmd, 100, stdin); // read user input

        if (cmd[strlen(cmd) - 1] == '\n') // remove newline character
            cmd[strlen(cmd) - 1] = '\0';

        if (!strcmp(cmd, "exit")) // exit shell
            exit(0);

        pid = fork(); // create child process

        if (pid < 0)
        {
            printf("Error: forking child process failed\n");
            exit(1);
        }

        if (pid == 0) // child process
        {
            char *tokens[20]; // array to store command arguments
            int n = 0; // number of arguments

            // parse user input and tokenize command arguments
            char *token = strtok(cmd, " ");

            while (token != NULL)
            {
                tokens[n++] = token;
                token = strtok(NULL, " ");
            }

            tokens[n] = NULL; // mark end of array

            execvp(tokens[0], tokens); // execute command
            exit(0);
        }
        else // parent process
        {
            waitpid(pid, &status, 0); // wait for child process to finish
        }
    }

    return 0;
}