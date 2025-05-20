//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 4096

int main() {
    int shmid;
    void *shmaddr;
    int fd[2];
    char *message = "Hello, world!";
    pid_t childpid;

    // Create shared memory segment
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        fprintf(stderr, "shmget failed: %s\n", strerror(errno));
        exit(1);
    }

    // Map shared memory into process address space
    if ((shmaddr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0)) == MAP_FAILED) {
        fprintf(stderr, "mmap failed: %s\n", strerror(errno));
        exit(1);
    }

    // Write message to shared memory
    memcpy(shmaddr, message, strlen(message) + 1);

    // Create pipe for inter-process communication
    if (pipe(fd) == -1) {
        fprintf(stderr, "pipe failed: %s\n", strerror(errno));
        exit(1);
    }

    // Fork child process
    if ((childpid = fork()) == -1) {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (childpid == 0) {
        // Child process
        close(fd[0]);
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
        exit(0);
    } else {
        // Parent process
        close(fd[1]);
        char buffer[SHM_SIZE];
        read(fd[0], buffer, SHM_SIZE);
        close(fd[0]);
        printf("Received message: %s\n", buffer);
        munmap(shmaddr, SHM_SIZE);
        shmdt(shmaddr);
        exit(0);
    }
}