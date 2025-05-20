//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHMKEY  123456789L
#define SEMKEY  987654321L
#define SHMSIZE 4096

typedef struct {
    int a;
    int b;
    int c;
} shared_memory;

int main() {
    // Create shared memory segment
    int shmid = shmget(SHMKEY, SHMSIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // Attach shared memory segment to address space
    shared_memory *shm = (shared_memory *)shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // Create semaphore set
    int semid = semget(SEMKEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        return EXIT_FAILURE;
    }

    // Initialize semaphore to 1
    semctl(semid, 0, SETVAL, 1);

    // Process 1
    if (fork() == 0) {
        // Lock semaphore
        struct sembuf op = {0, -1, 0};
        if (semop(semid, &op, 1) == -1) {
            perror("semop");
            return EXIT_FAILURE;
        }

        // Access shared memory
        shm->a = 1;
        shm->b = 2;
        shm->c = 3;

        // Unlock semaphore
        op.sem_op = 1;
        if (semop(semid, &op, 1) == -1) {
            perror("semop");
            return EXIT_FAILURE;
        }
    }
    // Process 2
    else {
        // Lock semaphore
        struct sembuf op = {0, -1, 0};
        if (semop(semid, &op, 1) == -1) {
            perror("semop");
            return EXIT_FAILURE;
        }

        // Access shared memory
        printf("a = %d, b = %d, c = %d\n", shm->a, shm->b, shm->c);

        // Unlock semaphore
        op.sem_op = 1;
        if (semop(semid, &op, 1) == -1) {
            perror("semop");
            return EXIT_FAILURE;
        }
    }

    // Detach shared memory segment from address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return EXIT_FAILURE;
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return EXIT_FAILURE;
    }

    // Delete semaphore set
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}