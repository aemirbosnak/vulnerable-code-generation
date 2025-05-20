//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>

#define SEM_ID 0
#define SEM_KEY 1234

int main() {
    int shmid, semid;
    char *shmaddr;
    struct sembuf sem_op;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // Create semaphore set
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore set.\n");
        exit(1);
    }

    // Initialize semaphore to 0
    sem_op.sem_num = 0;
    sem_op.sem_op = 0;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1) {
        printf("Error initializing semaphore.\n");
        exit(1);
    }

    // Write message to shared memory
    strcpy(shmaddr, "Welcome to the post-apocalyptic world!");

    // Signal semaphore to indicate message is ready
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1) {
        printf("Error signaling semaphore.\n");
        exit(1);
    }

    // Wait for message to be read
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(semid, &sem_op, 1) == -1) {
        printf("Error waiting for semaphore.\n");
        exit(1);
    }

    // Read message from shared memory
    printf("Message: %s\n", shmaddr);

    // Remove shared memory segment and semaphore set
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    return 0;
}