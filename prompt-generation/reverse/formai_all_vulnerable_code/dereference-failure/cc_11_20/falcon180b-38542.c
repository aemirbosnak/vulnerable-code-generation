//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    void *shmaddr;
    char *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    shmptr = (char *) shmaddr;
    for (int i = 0; i < SHM_SIZE; i++) {
        shmptr[i] = '\0';
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        sleep(1);
        shmptr = (char *) shmat(shmid, NULL, 0);
        if (shmptr == (void *) -1) {
            perror("shmat");
            exit(1);
        }
        for (int i = 0; i < SHM_SIZE; i++) {
            shmptr[i] = 'A';
        }
        printf("Child process wrote to shared memory.\n");
    } else {
        // Parent process reads from shared memory
        sleep(2);
        shmptr = (char *) shmat(shmid, NULL, 0);
        if (shmptr == (void *) -1) {
            perror("shmat");
            exit(1);
        }
        for (int i = 0; i < SHM_SIZE; i++) {
            if (shmptr[i]!= 'A') {
                printf("Parent process read incorrect data from shared memory.\n");
                exit(1);
            }
        }
        printf("Parent process read from shared memory.\n");
    }

    return 0;
}