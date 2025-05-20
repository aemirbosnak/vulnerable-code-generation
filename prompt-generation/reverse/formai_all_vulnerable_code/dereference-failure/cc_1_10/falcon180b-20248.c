//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024

int main(int argc, char **argv) {
    int fd[2];
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_COMMAND_LENGTH / 3];

    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);

    int i = 0;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[i] = token;
        i++;
        if (i >= MAX_COMMAND_LENGTH / 3) {
            printf("Too many arguments.\n");
            return 1;
        }
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]);
        execvp(args[0], args);
        perror("execvp");
        return 1;
    } else {
        close(fd[0]);
        write(fd[1], "\n", 1);
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}