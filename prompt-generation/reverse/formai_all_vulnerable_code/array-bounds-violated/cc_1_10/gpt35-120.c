//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    char command[1000], *args[100], *token;
    int status, i;

    printf("%%%%%% Unix-like Shell! %%%%%%\n");
    printf("Enter 'exit' to quit.\n");

    while(1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        // remove the trailing newline
        command[strlen(command) - 1] = '\0';

        // exit if the command is "exit"
        if(strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // tokenize the command
        token = strtok(command, " ");
        i = 0;
        while(token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // fork a child process
        pid_t pid = fork();

        if(pid < 0) {
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        } else if(pid == 0) {
            // child process
            if(execvp(args[0], args) < 0) {
                fprintf(stderr, "Command not found.\n");
                exit(1);
            }
        } else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}