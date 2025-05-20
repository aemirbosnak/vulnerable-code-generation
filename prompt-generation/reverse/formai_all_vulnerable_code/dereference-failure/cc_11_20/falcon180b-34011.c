//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main() {
    int shmid, semid;
    char *shmaddr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(int) * 10, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shmaddr = (char *) shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < 10; i++) {
        ((int *) shmaddr)[i] = i;
    }

    // Create semaphore set
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore set
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
    }

    // Wait for semaphore to be released
    sem_op.sem_op = -1;
    while (semop(semid, &sem_op, 1) == -1) {
        perror("semop");
        sleep(1);
    }

    // Access shared memory segment
    for (i = 0; i < 10; i++) {
        printf("%d\n", ((int *) shmaddr)[i]);
    }

    // Detach shared memory segment from process address space
    if (shmdt(shmaddr) == -1) {
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