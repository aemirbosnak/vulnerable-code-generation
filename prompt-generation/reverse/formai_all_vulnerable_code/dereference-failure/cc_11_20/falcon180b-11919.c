//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 100

int main() {
    int shmid;
    char *shm;
    int semid;
    int sem;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shm[i] = '0';
    }

    // Create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore
    sem = 0;
    if (semctl(semid, 0, SETVAL, sem) == -1) {
        perror("semctl");
        exit(1);
    }

    // Fork child process
    switch (fork()) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            // Child process
            sleep(1);
            for (i = 0; i < SIZE; i++) {
                shm[i] = '1';
            }
            sem++;
            if (semctl(semid, 0, SETVAL, sem) == -1) {
                perror("semctl");
                exit(1);
            }
            break;
        default:
            // Parent process
            sleep(2);
            for (i = 0; i < SIZE; i++) {
                if (shm[i]!= '1') {
                    printf("Interprocess communication failed\n");
                    exit(1);
                }
            }
            break;
    }

    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

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