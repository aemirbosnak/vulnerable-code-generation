//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 10

int main() {
    int fd[2]; // file descriptors for parent-child communication
    pid_t child_pid; // process id of child process
    char *ptr; // pointer to shared memory
    int i;

    // create pipe for communication
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    // fork a child process
    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    // parent process
    if (child_pid > 0) {
        // close reading end of pipe
        close(fd[0]);

        // write data to pipe
        for (i = 0; i < SIZE; i++) {
            write(fd[1], &i, sizeof(i));
        }

        // close writing end of pipe
        close(fd[1]);

        // wait for child to finish
        wait(NULL);
    } else {
        // child process
        close(fd[1]); // close writing end of pipe

        // map shared memory
        ptr = (char *)mmap(NULL, SIZE * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd[0], 0);
        if (ptr == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }

        // read data from shared memory
        for (i = 0; i < SIZE; i++) {
            printf("%d ", *(ptr + i));
        }

        // unmap shared memory
        if (munmap(ptr, SIZE * sizeof(int)) == -1) {
            perror("munmap");
            exit(1);
        }

        // close reading end of pipe
        close(fd[0]);
    }
    return 0;
}