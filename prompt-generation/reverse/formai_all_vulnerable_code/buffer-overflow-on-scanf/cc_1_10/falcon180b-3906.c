//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define PATH ":/usr/local/bin:/usr/bin:/bin"

char **split_command(char *command);
int execute_command(char **args);
void print_prompt(char *username);

int main() {
    char username[20];
    printf("Enter your username: ");
    scanf("%s", username);

    while (1) {
        print_prompt(username);
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        char **args = split_command(command);
        int status = execute_command(args);

        if (status == 1) {
            printf("Child process terminated with status 1\n");
        }

        free(args);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
            return 1;
        }
        if (chdir(args[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                return 1;
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void print_prompt(char *username) {
    printf("%s@localhost:~$ ", username);
}