//Code Llama-13B DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_BUF 1024
#define MAX_ARGS 10

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int rc;
    char *args[MAX_ARGS];
    char *cmd;
    char buf[MAX_BUF];
    pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [args]\n", argv[0]);
        exit(1);
    }

    cmd = argv[1];
    args[0] = cmd;
    for (int i = 2; i < argc; i++) {
        args[i - 1] = argv[i];
    }
    args[argc - 1] = NULL;

    if ((pid = fork()) < 0) {
        error("fork failed");
    } else if (pid == 0) {
        if ((rc = execvp(cmd, args)) < 0) {
            error("execvp failed");
        }
        exit(rc);
    } else {
        if (wait(&rc) < 0) {
            error("wait failed");
        }
    }

    return rc;
}