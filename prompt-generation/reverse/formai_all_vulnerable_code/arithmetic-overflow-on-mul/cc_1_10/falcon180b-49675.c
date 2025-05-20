//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 50
#define NUM_CHILDREN 5

int main() {
    int fd[2];
    int i;
    pid_t pid;

    // create pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    for (i = 0; i < NUM_CHILDREN; i++) {
        pid = fork();

        if (pid < 0) { // error occurred
            fprintf(stderr, "Fork Failed");
            return 1;
        } else if (pid > 0) { // parent process
            close(fd[0]);
            write(fd[1], &i, sizeof(int));
            close(fd[1]);
            wait(NULL);
        } else { // child process
            close(fd[1]);
            read(fd[0], &i, sizeof(int));
            close(fd[0]);

            printf("Child %d started\n", i);

            int* shared_memory = (int*)mmap(NULL, SIZE * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

            if (shared_memory == MAP_FAILED) {
                fprintf(stderr, "Mmap Failed");
                return 1;
            }

            int j;
            for (j = 0; j < SIZE; j++) {
                shared_memory[j] = i * 100 + j;
            }

            munmap(shared_memory, SIZE * sizeof(int));
            return 0;
        }
    }

    return 0;
}