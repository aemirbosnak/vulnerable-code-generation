//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

char **split_line(char *line) {
    int argc = 0, len = strlen(line);
    char **argv = malloc((MAX_ARGUMENTS + 1) * sizeof(char *));
    if (argv == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }
    argv[argc] = NULL;
    char *token = strtok(line, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        fprintf(stderr, "Error: Command not found.\n");
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s not found.\n", args[0]);
            return 1;
        }
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    char **args = split_line(input);
    int result = execute_command(args);
    if (result!= 0) {
        printf("Exit with status %d\n", result);
    }
}