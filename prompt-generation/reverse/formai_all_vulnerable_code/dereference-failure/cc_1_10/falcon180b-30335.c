//Falcon-180B DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;

    char *token = strtok(argv[2], " ");
    while (token!= NULL && num_arguments < MAX_ARGUMENTS) {
        arguments[num_arguments++] = token;
        token = strtok(NULL, " ");
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(command, arguments);
        perror("execvp");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Child process terminated abnormally\n");
            return 1;
        }
    }
}