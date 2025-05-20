//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **argv = NULL;
    char *token;

    while ((token = strtok(command, DELIM))) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
    }

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL)
        return 1;

    if (strcmp(argv[0], "exit") == 0) {
        return 0;
    } else if (strcmp(argv[0], "cd") == 0) {
        if (chdir(argv[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("execvp");
                return 1;
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    argv = split_command(input);
    execute_command(argv);

    free(argv);
}

int main(void) {
    loop();

    return 0;
}