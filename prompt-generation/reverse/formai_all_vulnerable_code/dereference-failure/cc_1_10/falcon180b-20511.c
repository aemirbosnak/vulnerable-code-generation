//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 256

int main() {
    int fd_parent[2], fd_child[2];
    pid_t pid;

    // Create pipe
    if (pipe(fd_parent) == -1 || pipe(fd_child) == -1) {
        fprintf(stderr, "Pipe creation failed: %s\n", strerror(errno));
        exit(1);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd_parent[0]);
        close(fd_child[1]);

        // Read from parent and write to child
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
            write(fd_child[0], buffer, strlen(buffer));
        }

        // Close pipes and exit
        close(fd_parent[1]);
        close(fd_child[0]);
        exit(0);
    } else {
        // Parent process
        close(fd_parent[1]);
        close(fd_child[0]);

        // Write to child and read from parent
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
            write(fd_parent[0], buffer, strlen(buffer));
        }

        // Close pipes and wait for child to exit
        close(fd_parent[0]);
        close(fd_child[1]);
        waitpid(pid, NULL, 0);
    }

    return 0;
}