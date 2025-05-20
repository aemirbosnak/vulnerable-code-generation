//Falcon-180B DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 64
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t launch_shell() {
    char *shell_args[] = {"/bin/bash", NULL};
    return fork();
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *line = NULL;
    size_t buf_size = 0;
    ssize_t read_count;
    pid_t child_pid;

    printf("Welcome to the shell!\n");

    while (1) {
        printf("> ");
        read_count = getline(&line, &buf_size, stdin);

        if (read_count <= 0) {
            if (feof(stdin)) {
                printf("\nExiting...\n");
                break;
            } else if (ferror(stdin)) {
                perror("Error reading input");
                break;
            }
        }

        line[read_count - 1] = '\0';

        char **args = split_line(line);

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                printf("Usage: cd [directory]\n");
            } else {
                if (chdir(args[1])!= 0) {
                    perror("Error changing directory");
                }
            }
        } else {
            child_pid = launch_shell();

            if (child_pid == -1) {
                perror("Error forking process");
            } else if (child_pid > 0) {
                waitpid(child_pid, NULL, 0);
            } else {
                execvp(args[0], args);
                perror("Error executing command");
            }
        }

        free(line);
        line = NULL;
        buf_size = 0;
    }

    return 0;
}