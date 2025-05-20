#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 64

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command> [args] [&]\n", argv[0]);
        return 1;
    }

    int bg = 0;
    if (strcmp(argv[argc - 1], "&") == 0) {
        bg = 1;
        argv[--argc] = NULL;
    }

    char *cmd = argv[1];
    char *args[MAX_ARGS];
    for (int i = 2; i < argc; i++) {
        args[i - 2] = argv[i];
    }
    args[argc - 2] = NULL;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(cmd, args);
        perror("execvp");
        exit(1);
    } else {
        if (!bg) {
            wait(NULL);
        }
    }

    return 0;
}
