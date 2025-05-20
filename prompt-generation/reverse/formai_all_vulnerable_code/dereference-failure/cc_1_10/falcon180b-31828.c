//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define SHM_SIZE 1024
#define SHM_KEY 0x12345678

int main(int argc, char *argv[]) {
    int shmid;
    char *shmptr;
    int i;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SHM_SIZE; i++) {
        ((char *) shmptr)[i] = 0;
    }

    // Create child process
    pid = fork();
    if (pid == 0) {
        // Child process writes to shared memory
        sleep(1);
        sprintf(shmptr, "Hello from child process %d", getpid());
    } else {
        // Parent process reads from shared memory
        sleep(2);
        printf("Shared memory content: %s\n", shmptr);
    }

    return 0;
}