#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

void execute_command(char *cmd) {
    char *args[MAX_CMD_LEN / 2 + 1];
    int i = 0;
    args[i++] = strtok(cmd, " ");
    while (args[i - 1] != NULL) {
        args[i++] = strtok(NULL, " ");
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

int main() {
    char cmd[MAX_CMD_LEN];
    while (1) {
        printf("> ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';
        if (strlen(cmd) > 0) {
            execute_command(cmd);
        }
    }
    return 0;
}
