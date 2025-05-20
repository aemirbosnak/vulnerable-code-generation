#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

int main() {
    char cmd[MAX_CMD_LEN];
    printf("Enter command: ");
    fgets(cmd, sizeof(cmd), stdin);
    cmd[strcspn(cmd, "\n")] = '\0';

    char *args[64];
    args[0] = strtok(cmd, " ");
    int i = 1;
    while (args[i - 1]) {
        args[i] = strtok(NULL, " ");
        i++;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        char *path = getenv("PATH");
        char *full_path = NULL;
        char *token = strtok(path, ":");
        while (token != NULL) {
            full_path = malloc(strlen(token) + strlen(args[0]) + 2);
            sprintf(full_path, "%s/%s", token, args[0]);
            if (access(full_path, X_OK) == 0) {
                break;
            }
            free(full_path);
            token = strtok(NULL, ":");
        }

        if (full_path == NULL) {
            fprintf(stderr, "Command not found\n");
            exit(EXIT_FAILURE);
        }

        execv(full_path, args);
        perror("execv");
        free(full_path);
        exit(EXIT_FAILURE);
    } else {
        if (strchr(cmd, '&') != NULL) {
            waitpid(pid, NULL, WNOHANG);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}
