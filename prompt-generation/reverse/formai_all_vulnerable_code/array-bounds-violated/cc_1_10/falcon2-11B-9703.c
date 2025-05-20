//Falcon2-11B DATASET v1.0 Category: System administration ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD_STDIN 0
#define CHILD_STDOUT 1
#define CHILD_STDERR 2

int main(int argc, char *argv[]) {
    int pid;
    int status;
    int fd[3];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (pipe(fd) == -1) {
        fprintf(stderr, "Error creating pipe\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking child process\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(CHILD_STDIN);
        close(CHILD_STDOUT);
        close(CHILD_STDERR);

        dup2(fd[fd[0]], CHILD_STDIN);
        dup2(fd[fd[1]], CHILD_STDOUT);
        dup2(fd[fd[2]], CHILD_STDERR);

        execlp("wc", "wc", "-l", argv[1], NULL);
        fprintf(stderr, "Error executing wc\n");
        return 1;
    } else {
        // Parent process
        close(fd[0]);
        close(fd[1]);
        close(fd[2]);

        dup2(fd[CHILD_STDIN], 0);
        dup2(fd[CHILD_STDOUT], 1);
        dup2(fd[CHILD_STDERR], 2);

        waitpid(pid, &status, 0);

        int num_lines = WEXITSTATUS(status);
        printf("Number of lines: %d\n", num_lines);

        close(0);
        close(1);
        close(2);
    }

    return 0;
}