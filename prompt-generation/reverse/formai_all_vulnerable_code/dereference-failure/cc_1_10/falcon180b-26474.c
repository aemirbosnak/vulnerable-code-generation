//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 4096
#define DELIM " \t\r\n\a"
#define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

char **split_command(char *command);
int execute_command(char **args);
void loop(void);

int main(int argc, char **argv) {
    loop();
    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_command(input);
    execute_command(args);
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        if (argc >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
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
    }

    char *path = getenv("PATH");
    char *new_path = malloc(sizeof(char) * (strlen(PATH) + strlen(path) + 2));
    strcpy(new_path, PATH);
    strcat(new_path, ":");
    strcat(new_path, path);

    setenv("PATH", new_path, 1);
    free(new_path);

    if ((pid = fork()) == -1) {
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

    return 0;
}