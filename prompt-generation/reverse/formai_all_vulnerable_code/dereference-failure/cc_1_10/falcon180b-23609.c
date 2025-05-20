//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define DELIM " "

int main() {
    char *cmdline = (char *)malloc(MAX_LINE_LEN);
    char *token = NULL;
    int argc = 0;
    char **argv = NULL;

    printf("Enter command: ");
    fgets(cmdline, MAX_LINE_LEN, stdin);

    // Parse command line
    token = strtok(cmdline, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Command terminated abnormally\n");
        }
    }

    free(cmdline);
    return 0;
}