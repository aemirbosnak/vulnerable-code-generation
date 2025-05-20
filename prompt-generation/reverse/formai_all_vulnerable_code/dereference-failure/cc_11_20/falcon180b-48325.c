//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 1024
#define NUM_ITER 100

int main() {
    int fd[2];
    pid_t pid;
    char *shared_mem;
    int i, j;

    // Create a pipe
    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        exit(1);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]); // Close read end of pipe
        shared_mem = (char *)mmap(NULL, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd[1], 0);
        if (shared_mem == MAP_FAILED) {
            printf("Memory mapping failed\n");
            exit(1);
        }
        for (i = 0; i < NUM_ITER; i++) {
            for (j = 0; j < SIZE; j++) {
                shared_mem[j] = i;
            }
        }
        munmap(shared_mem, SIZE);
        close(fd[1]); // Close write end of pipe
        exit(0);
    } else {
        // Parent process
        close(fd[1]); // Close write end of pipe
        sleep(1); // Wait for child to finish
        int status;
        waitpid(pid, &status, 0);
        char *shared_mem = (char *)mmap(NULL, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd[0], 0);
        if (shared_mem == MAP_FAILED) {
            printf("Memory mapping failed\n");
            exit(1);
        }
        for (i = 0; i < NUM_ITER; i++) {
            for (j = 0; j < SIZE; j++) {
                if (shared_mem[j]!= i) {
                    printf("Iteration %d failed\n", i);
                    exit(1);
                }
            }
        }
        munmap(shared_mem, SIZE);
        close(fd[0]); // Close read end of pipe
        exit(0);
    }
}