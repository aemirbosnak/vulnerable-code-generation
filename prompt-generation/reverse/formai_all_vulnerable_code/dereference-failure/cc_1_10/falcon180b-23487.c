//Falcon-180B DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

int main(int argc, char *argv[]) {
    int status;
    pid_t pid;
    char *command = malloc(MAX_COMMAND_LENGTH);
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    int num_arguments = 0;

    if (argc < 2) {
        printf("Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    strcat(command, " ");
    for (int i = 2; i < argc; i++) {
        arguments[num_arguments++] = argv[i];
        strcat(command, argv[i]);
        strcat(command, " ");
    }

    pid = fork();

    if (pid == 0) {
        for (int i = 0; i < num_arguments; i++) {
            if (strcmp(arguments[i], ">") == 0) {
                char *filename = arguments[i+1];
                int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
                if (fd == -1) {
                    fprintf(stderr, "Error: Could not open file '%s' for writing\n", filename);
                    exit(1);
                }
                dup2(fd, 1);
                close(fd);
                i++;
            } else if (strcmp(arguments[i], ">>") == 0) {
                char *filename = arguments[i+1];
                int fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
                if (fd == -1) {
                    fprintf(stderr, "Error: Could not open file '%s' for appending\n", filename);
                    exit(1);
                }
                dup2(fd, 1);
                close(fd);
                i++;
            }
        }

        execvp(command, arguments);
        fprintf(stderr, "Error: Could not execute command '%s'\n", command);
        exit(1);
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    free(command);
    for (int i = 0; i < num_arguments; i++) {
        free(arguments[i]);
    }
    free(arguments);

    return 0;
}