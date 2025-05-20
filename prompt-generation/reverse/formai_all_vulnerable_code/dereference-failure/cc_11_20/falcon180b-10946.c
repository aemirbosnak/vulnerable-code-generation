//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

/* structure for shared memory */
struct shm_struct {
    int semid;
    int shmid;
    int count;
};

int main() {
    int shmid, semid;
    struct shm_struct *ptr;
    int count = 0;

    /* create a shared memory segment */
    shmid = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    /* attach the shared memory to our data segment */
    ptr = (struct shm_struct *) shmat(shmid, NULL, 0);
    if ((long)ptr == -1) {
        perror("shmat");
        exit(1);
    }

    /* initialize the semaphore */
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    /* set the semaphore value to 1 */
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(1);
    }

    /* loop until we have reached the maximum count */
    while (count < MAX_SIZE) {
        /* wait for the semaphore to be available */
        if (semop(semid, &ptr->semid, 1) == -1) {
            perror("semop");
            exit(1);
        }

        /* increment the count */
        count++;
        ptr->count = count;

        /* release the semaphore */
        if (semop(semid, &ptr->semid, 1) == -1) {
            perror("semop");
            exit(1);
        }
    }

    /* detach the shared memory */
    if (shmdt(ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    /* remove the shared memory segment */
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    /* remove the semaphore */
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}