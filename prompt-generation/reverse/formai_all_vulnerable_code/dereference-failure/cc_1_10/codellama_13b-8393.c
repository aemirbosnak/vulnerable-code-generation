//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: puzzling
/*
 * Puzzling IPC Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>

#define PIPE_SIZE 4096

int main(int argc, char **argv) {
    int fd[2];
    int pid;
    char *buf;
    int i;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]);
        buf = (char *)mmap(NULL, PIPE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd[1], 0);
        if (buf == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }

        for (i = 0; i < PIPE_SIZE; i++) {
            buf[i] = 'A' + i % 26;
        }

        close(fd[1]);
        exit(0);
    } else {
        // Parent process
        close(fd[1]);
        buf = (char *)mmap(NULL, PIPE_SIZE, PROT_READ, MAP_SHARED, fd[0], 0);
        if (buf == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }

        wait(NULL);

        for (i = 0; i < PIPE_SIZE; i++) {
            printf("%c", buf[i]);
        }

        munmap(buf, PIPE_SIZE);
        close(fd[0]);
        exit(0);
    }

    return 0;
}