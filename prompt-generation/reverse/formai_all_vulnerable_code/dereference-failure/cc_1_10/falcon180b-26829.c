//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int fd[2];
    char buffer[BUFFER_SIZE];
    pid_t child_pid;

    // Create a pipe
    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        exit(1);
    }

    child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp("ls", "ls", NULL);

        perror("execlp");
        exit(1);
    } else {
        // Parent process
        close(fd[1]);
        fdopen(fd[0], "r");

        char c;
        while ((c = fgetc(stdin))!= EOF) {
            write(fd[0], &c, 1);
        }

        close(fd[0]);
        wait(NULL);
    }

    return 0;
}