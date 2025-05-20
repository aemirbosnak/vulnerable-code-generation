//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 10
#define SEM_ID 0
#define SEM_KEY 1234
#define SHM_ID 0
#define SHM_KEY 5678

int main() {
    int shmid;
    int semid;
    int i;
    int *shmptr;
    struct sembuf sem_op;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SIZE*sizeof(int), IPC_CREAT|0666);
    if (shmid == -1) {
        printf("Error: Failed to create shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void*)-1) {
        printf("Error: Failed to attach shared memory segment\n");
        exit(1);
    }

    // initialize shared memory
    for (i = 0; i < SIZE; i++) {
        *(shmptr+i) = 0;
    }

    // create semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT|0666);
    if (semid == -1) {
        printf("Error: Failed to create semaphore\n");
        exit(1);
    }

    // set semaphore value to 0
    sem_op.sem_num = 0;
    sem_op.sem_op = 0;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1) {
        printf("Error: Failed to set semaphore value\n");
        exit(1);
    }

    // start child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        printf("Error: Failed to fork child process\n");
        exit(1);
    } else if (child_pid == 0) {
        // child process
        for (i = 0; i < SIZE; i++) {
            *(shmptr+i) = i;
        }
        exit(0);
    } else {
        // parent process
        sleep(1); // wait for child process to update shared memory
        for (i = 0; i < SIZE; i++) {
            printf("%d ", *(shmptr+i));
        }
        printf("\n");
    }

    // destroy semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        printf("Error: Failed to destroy semaphore\n");
        exit(1);
    }

    // detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error: Failed to detach shared memory segment\n");
        exit(1);
    }

    // destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error: Failed to destroy shared memory segment\n");
        exit(1);
    }

    return 0;
}