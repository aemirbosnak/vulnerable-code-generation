//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PIPE_LENGTH 4096

int main(int argc, char *argv[]) {
    pid_t child, parent;
    int pipe_fds[2];
    char pipe_buf[MAX_PIPE_LENGTH];

    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    child = fork();
    if (child == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child == 0) {
        close(pipe_fds[0]);
        dup2(pipe_fds[1], STDOUT_FILENO);
        dup2(pipe_fds[1], STDIN_FILENO);
        close(pipe_fds[1]);

        printf("Child process, ready to receive input\n");
        while (1) {
            memset(pipe_buf, 0, sizeof(pipe_buf));
            read(pipe_fds[0], pipe_buf, sizeof(pipe_buf));
            if (strcmp(pipe_buf, "exit") == 0) {
                break;
            }
            printf("Child process received: %s\n", pipe_buf);
            write(STDOUT_FILENO, pipe_buf, strlen(pipe_buf));
        }

        exit(EXIT_SUCCESS);
    } else {
        parent = wait(&child);
    }

    printf("Parent process, ready to send input\n");
    while (1) {
        memset(pipe_buf, 0, sizeof(pipe_buf));
        printf("Parent process, send input: ");
        scanf("%s", pipe_buf);
        if (strcmp(pipe_buf, "exit") == 0) {
            break;
        }
        write(pipe_fds[1], pipe_buf, strlen(pipe_buf));
    }

    return 0;
}