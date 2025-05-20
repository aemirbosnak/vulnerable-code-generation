//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 512
#define MAX_ARGS 20

int main() {
    char buffer[BUFFER_SIZE], *args[MAX_ARGS];
    int argc, redirect, redirect_in, redirect_out, status, i;
    pid_t pid;

    while(1) {
        // print shell prompt
        printf("$ ");

        // read command
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';

        // split command into arguments
        argc = 0;
        args[argc++] = strtok(buffer, " ");
        while((args[argc++] = strtok(NULL, " ")) != NULL);

        // handle empty command
        if(argc == 1) continue;

        // check if command requests redirection
        redirect = 0;
        for(i=1; i<argc; i++) {
            if(strcmp(args[i], "<") == 0) redirect_in = i;
            else if(strcmp(args[i], ">") == 0) redirect_out = i;
        }
        if(redirect_in || redirect_out) redirect = 1;

        // fork a child process to execute the command
        pid = fork();
        if(pid == -1) {
            printf("Error: fork failed.\n");
            exit(1);
        } else if(pid == 0) {
            // child process
            if(redirect_in) {
                close(STDIN_FILENO);
                open(args[redirect_in+1], O_RDONLY);
            }
            if(redirect_out) {
                close(STDOUT_FILENO);
                open(args[redirect_out+1], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            }
            execvp(args[0], args);
        } else {
            // parent process
            if(redirect) {
                if(redirect_in) close(redirect_in);
                if(redirect_out) close(redirect_out);
            }
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}