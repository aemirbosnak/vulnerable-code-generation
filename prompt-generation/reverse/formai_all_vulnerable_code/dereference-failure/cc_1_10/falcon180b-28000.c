//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_WAIT_TIME 10

int main() {
    char *buffer = malloc(BUFFER_SIZE);
    int fd[2];
    pid_t child_pid;

    // Create pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe creation failed: %s\n", strerror(errno));
        exit(1);
    }

    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        exit(1);
    }

    if (child_pid == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp("cat", "cat", NULL);

        fprintf(stderr, "Exec failed: %s\n", strerror(errno));
        exit(1);
    }

    close(fd[1]);
    fcntl(fd[0], F_SETFL, O_NONBLOCK);

    while (1) {
        int bytes_read = read(fd[0], buffer, BUFFER_SIZE);

        if (bytes_read == -1 && errno!= EAGAIN) {
            fprintf(stderr, "Read failed: %s\n", strerror(errno));
            exit(1);
        }

        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("%s", buffer);
        }

        usleep(100000);
    }

    return 0;
}