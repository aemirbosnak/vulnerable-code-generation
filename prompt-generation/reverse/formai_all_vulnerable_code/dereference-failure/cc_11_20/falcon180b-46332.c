//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    int fd;
    pid_t pid;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("shmget failed\n");
        exit(1);
    }

    // Attach shared memory to process
    shmptr = (char *)shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        printf("shmat failed\n");
        exit(1);
    }

    // Initialize shared memory
    memset(shmptr, 0, SIZE);

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        printf("fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Open message queue
        fd = open("/dev/ptmx", O_RDWR);
        if (fd == -1) {
            printf("open failed\n");
            exit(1);
        }

        // Grant access to message queue
        if (grantpt(fd) == -1) {
            printf("grantpt failed\n");
            exit(1);
        }
        if (unlockpt(fd) == -1) {
            printf("unlockpt failed\n");
            exit(1);
        }

        // Create file descriptor for message queue
        fd = open("/dev/ptmx", O_RDWR);
        if (fd == -1) {
            printf("open failed\n");
            exit(1);
        }

        // Send message to parent process
        write(fd, "Hello, world!", 13);

        // Detach shared memory
        if (shmdt(shmptr) == -1) {
            printf("shmdt failed\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Receive message from child process
        char buffer[13];
        read(fd, buffer, 13);
        printf("Received message: %s\n", buffer);

        // Detach shared memory
        if (shmdt(shmptr) == -1) {
            printf("shmdt failed\n");
            exit(1);
        }

        // Wait for child process to exit
        wait(NULL);
    }

    return 0;
}