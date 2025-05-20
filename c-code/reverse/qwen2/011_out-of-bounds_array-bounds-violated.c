#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

int main() {
    char cmd[MAX_CMD_LEN];
    while (1) {
        printf("Enter command: ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execlp(cmd, cmd, NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);
        }
    }
    return 0;
}
