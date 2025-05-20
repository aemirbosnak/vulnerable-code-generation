//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PIPE_LENGTH 1024

int main(int argc, char *argv[]) {
    char command[MAX_COMMAND_LENGTH];
    char pipe_name[MAX_PIPE_LENGTH];
    int fd[2];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    strcat(command, " ");
    for (int i = 2; i < argc; i++) {
        strcat(command, argv[i]);
        strcat(command, " ");
    }

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed\n");
        return 1;
    }

    if (fork() == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("sh", "sh", "-c", command, NULL);
        fprintf(stderr, "execlp failed\n");
        return 1;
    } else {
        // Parent process
        close(fd[1]);
        fd[0] = open("pipe.txt", O_RDONLY);
        if (fd[0] == -1) {
            fprintf(stderr, "Open failed\n");
            return 1;
        }
        char buffer[1024];
        while (read(fd[0], buffer, sizeof(buffer)) > 0) {
            printf("%s", buffer);
        }
        close(fd[0]);
    }

    return 0;
}