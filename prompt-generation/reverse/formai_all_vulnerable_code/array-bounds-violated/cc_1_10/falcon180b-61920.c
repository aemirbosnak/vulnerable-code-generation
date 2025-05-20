//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

void read_from_pipe(int fd) {
    char buf[BUF_SIZE];
    int n;

    while ((n = read(fd, buf, BUF_SIZE)) > 0) {
        buf[n] = '\0';
        printf("Received message: %s\n", buf);
    }

    if (n == -1) {
        if (errno == EAGAIN) {
            printf("No data available\n");
        } else {
            perror("read");
        }
    }
}

void write_to_pipe(int fd) {
    char buf[BUF_SIZE];
    int n;

    while (fgets(buf, BUF_SIZE, stdin)!= NULL) {
        n = strlen(buf);
        if (buf[n - 1] == '\n') {
            buf[n - 1] = '\0';
            n--;
        }

        if (write(fd, buf, n)!= n) {
            perror("write");
        }
    }
}

int main() {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to pipe
        close(fd[0]);
        write_to_pipe(fd[1]);
        close(fd[1]);
        exit(0);
    } else {
        // Parent process reads from pipe
        close(fd[1]);
        read_from_pipe(fd[0]);
        close(fd[0]);
    }

    return 0;
}