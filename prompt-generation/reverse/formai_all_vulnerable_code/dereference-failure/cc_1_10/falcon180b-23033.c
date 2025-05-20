//Falcon-180B DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define PATH_SEPARATOR ':'

char *split_string(char *str, char delimiter) {
    char *token = strtok(str, delimiter);
    return token;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    int argument_count = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        arguments[argument_count++] = token;
        token = strtok(NULL, " ");
    }

    arguments[argument_count] = NULL;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        perror("execvp");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}