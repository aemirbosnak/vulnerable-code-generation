//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(char *username);

int main(int argc, char *argv[]) {
    char username[20];
    strcpy(username, argv[0]);

    while (1) {
        print_prompt(username);
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char *command = strtok(input, DELIM);
        char **args = split_command(command);
        pid_t pid = fork();

        if (pid == -1) {
            printf("Error forking process\n");
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            execute_command(args);
            exit(0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(sizeof(char *) * (argc + 1));
    args[argc] = NULL;

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    return args;
}

pid_t fork(void) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
    } else {
        if (args[0] == NULL) {
            return 1;
        }

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else {
            execvp(args[0], args);
            perror("Error executing command");
            exit(1);
        }
    }

    return 0;
}

void print_prompt(char *username) {
    printf("%s@localhost: ", username);
}