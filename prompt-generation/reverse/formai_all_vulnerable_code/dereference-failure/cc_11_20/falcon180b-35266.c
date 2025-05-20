//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SEM_ID 0
#define SHM_ID 1
#define SIZE 1024

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main() {
    int semid, shmid;
    char *shm;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shm[i] = i;
    }

    // Create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    // Initialize semaphore
    union semun init = { 0 };
    if (semctl(semid, SEM_ID, SETVAL, init) == -1) {
        printf("Error initializing semaphore\n");
        exit(1);
    }

    // Start child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        sleep(1);

        // Access shared memory segment
        for (i = 0; i < SIZE; i++) {
            shm[i] += 1;
        }

        // Signal semaphore
        union semun signal = { 1 };
        if (semop(semid, &signal, 1) == -1) {
            printf("Error signaling semaphore\n");
            exit(1);
        }

        exit(0);
    } else {
        // Parent process
        sleep(2);

        // Access shared memory segment
        for (i = 0; i < SIZE; i++) {
            if (shm[i]!= i + 1) {
                printf("Error: shared memory segment not updated correctly\n");
                exit(1);
            }
        }

        // Signal semaphore
        union semun signal = { 1 };
        if (semop(semid, &signal, 1) == -1) {
            printf("Error signaling semaphore\n");
            exit(1);
        }

        exit(0);
    }
}