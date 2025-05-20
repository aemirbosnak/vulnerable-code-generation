//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(line, " ");
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    return argv;
}

int main(int argc, char **argv) {
    char input[MAX_LINE_SIZE];
    char **args;
    pid_t pid;
    int status;

    printf("Cyberpunk Shell 1.0\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_SIZE, stdin);

        args = split_line(input);
        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}