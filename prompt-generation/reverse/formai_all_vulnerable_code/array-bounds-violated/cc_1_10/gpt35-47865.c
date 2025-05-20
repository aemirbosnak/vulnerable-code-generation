//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char command[100];  // variable to store the user's command

    while (1) {  // loop indefinitely 
        printf("> ");  // print the prompt
        fflush(stdout);

        // get the user's command
        fgets(command, sizeof(command), stdin);

        // remove the newline character from the end of the command
        command[strlen(command)-1] = '\0';

        // fork a child process to execute the command
        pid_t pid = fork();

        if (pid < 0) {  // fork failed
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {  // child process
            // split the command into arguments
            char *args[20];
            char *token = strtok(command, " ");
            int index = 0;

            while (token != NULL) {
                args[index++] = token;
                token = strtok(NULL, " ");
            }

            args[index] = NULL;

            // execute the command
            execvp(args[0], args);
            perror("execvp failed");
            exit(1);
        } else {  // parent process
            // wait for the child to finish
            wait(NULL);
        }
    }

    return 0;
}