//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define MAX_SIZE 100

int main() {
    int shmid;
    char *shmaddr;
    key_t key;

    // Generate a unique key for shared memory segment
    key = ftok("shm.c", 65);

    // Create a shared memory segment
    shmid = shmget(key, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write some data to the shared memory segment
    strcpy(shmaddr, "Hello, world!");

    // Detach the shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}