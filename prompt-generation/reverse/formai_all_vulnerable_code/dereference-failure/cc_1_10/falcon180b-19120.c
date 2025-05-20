//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    int shmid;
    int *shmaddr;
    key_t key;
    char *name = "my_shm";
    int shm_size = 1024;

    // Generate a unique key
    key = ftok(name, 65);

    // Create shared memory
    if ((shmid = shmget(key, shm_size, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    memset(shmaddr, 0, shm_size);

    // Write data to shared memory
    strcpy(shmaddr, "Hello, world!");

    // Detach from shared memory
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}