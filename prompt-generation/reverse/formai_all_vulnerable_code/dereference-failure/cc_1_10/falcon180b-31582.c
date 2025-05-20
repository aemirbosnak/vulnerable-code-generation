//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("shmget failed\n");
        exit(1);
    }

    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        printf("shmat failed\n");
        exit(2);
    }

    // Initialize shared memory
    for (int i = 0; i < SIZE; i++) {
        *(int *)shm = i;
        shm += sizeof(int);
    }

    // Fork a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        for (int i = 0; i < SIZE; i++) {
            *(int *)shm += 10;
            shm += sizeof(int);
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process completed\n");
        exit(0);
    }

    return 0;
}