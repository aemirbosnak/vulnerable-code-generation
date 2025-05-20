//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid, semid;
    key_t key;
    int i, j;
    char *shm;
    int *sem;

    // Create shared memory segment
    key = ftok(".", 'A');
    if ((shmid = shmget(key, SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if ((long)shm == -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        shm[i] = 0;
    }

    // Create semaphore set
    if ((semid = semget(key, 2, IPC_CREAT | 0666)) < 0) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphores
    sem = (int *)semget(semid, 2, 0);
    if (sem == (int *)-1) {
        perror("semget");
        exit(1);
    }
    sem[0] = 1;
    sem[1] = 0;

    // Fork child process
    switch (fork()) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            // Child process
            for (j = 0; j < 10; j++) {
                sem[0] = 0;
                sleep(1);
                printf("Child: %d\n", j);
                sem[1] = 1;
            }
            break;
        default:
            // Parent process
            for (j = 0; j < 10; j++) {
                sem[1] = 0;
                sleep(1);
                printf("Parent: %d\n", j);
                sem[0] = 1;
            }
            break;
    }

    // Detach from shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove shared memory segment and semaphore set
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}