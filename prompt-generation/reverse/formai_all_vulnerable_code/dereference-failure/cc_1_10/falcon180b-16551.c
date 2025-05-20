//Falcon-180B DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

void execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Invalid command.\n");
        return;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv = NULL;

    printf("> ");
    fgets(input, sizeof(input), stdin);

    argv = split_command(input);
    execute_command(argv);

    free(argv);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    loop();

    return EXIT_SUCCESS;
}