//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    pid_t pid;
    char command[100];

    while (1) {
        printf("$ ");
        fgets(command, sizeof(command), stdin);

        /* Remove trailing newline character */
        if (command[strlen(command) - 1] == '\n')
            command[strlen(command) - 1] = '\0';

        /* Exit if "exit" command is entered */
        if (strcmp(command, "exit") == 0)
            break;

        if ((pid = fork()) < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */

            char *argv[10];
            int argc = 0;

            /* Tokenize command string */
            char *token = strtok(command, " ");
            while (token != NULL) {
                argv[argc++] = token;
                token = strtok(NULL, " ");
            }
            argv[argc] = NULL;

            /* Execute command */
            if (execvp(argv[0], argv) < 0) {
                perror("execvp error");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);

        } else {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return EXIT_SUCCESS;
}