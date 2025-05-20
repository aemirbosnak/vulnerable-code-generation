//Falcon-180B DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char buf[BUF_SIZE];
    char **args;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", strerror(errno));
        exit(1);
    }

    args = malloc(sizeof(char *) * 3);

    args[0] = strdup("sh");
    args[1] = strdup("-c");
    buf[0] = '\0';

    while (fgets(buf, BUF_SIZE, fp)!= NULL) {
        strcat(buf, " ");
        args[2] = strdup(buf);
        execute_command(args);
        free(args[2]);
    }

    fclose(fp);

    return 0;
}