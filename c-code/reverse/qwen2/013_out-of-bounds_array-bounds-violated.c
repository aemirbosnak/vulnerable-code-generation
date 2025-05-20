#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 128

void parse_command(char *command, char **args) {
    int arg_count = 0;
    args[arg_count++] = strtok(command, " ");
    while (args[arg_count - 1] != NULL && arg_count < MAX_ARGS) {
        args[arg_count++] = strtok(NULL, " ");
    }
}

int find_path(const char *cmd, char *path) {
    const char *env_path = getenv("PATH");
    if (!env_path) return -1;

    char *copy_path = strdup(env_path);
    char *dir = strtok(copy_path, ":");
    while (dir != NULL) {
        snprintf(path, MAX_COMMAND_LENGTH, "%s/%s", dir, cmd);
        if (access(path, X_OK) == 0) {
            free(copy_path);
            return 0;
        }
        dir = strtok(NULL, ":");
    }

    free(copy_path);
    return -1;
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    pid_t pid;

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0) continue;

        parse_command(command, args);

        if (strcmp(args[0], "exit") == 0) break;

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            char path[MAX_COMMAND_LENGTH];
            if (find_path(args[0], path) == -1) {
                fprintf(stderr, "Command not found: %s\n", args[0]);
                exit(EXIT_FAILURE);
            }
            execv(path, args);
            perror("execv");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
