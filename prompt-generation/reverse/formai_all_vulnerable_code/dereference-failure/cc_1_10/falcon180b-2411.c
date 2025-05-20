//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid, semid;
    char *shmptr;
    int i, pid;
    struct sembuf sem_op;

    //create shared memory
    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0666);
    if (shmid == -1) {
        printf("Shared memory creation failed\n");
        exit(1);
    }

    //attach shared memory
    shmptr = (char *)shmat(shmid, NULL, 0);
    if ((int)shmptr == -1) {
        printf("Shared memory attachment failed\n");
        exit(1);
    }

    //initialize shared memory
    for (i = 0; i < SIZE; i++) {
        *(shmptr+i) = 0;
    }

    //create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT|0666);
    if (semid == -1) {
        printf("Semaphore creation failed\n");
        exit(1);
    }

    //initialize semaphore
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1) {
        printf("Semaphore initialization failed\n");
        exit(1);
    }

    //fork child process
    pid = fork();
    if (pid == 0) {
        //child process
        for (i = 0; i < SIZE; i++) {
            *(shmptr+i) = i;
        }
        printf("Child process has written to shared memory\n");
        exit(0);
    } else {
        //parent process
        for (i = 0; i < SIZE; i++) {
            if (*(shmptr+i)!= i) {
                printf("Shared memory not written correctly\n");
                exit(1);
            }
        }
        printf("Shared memory written correctly\n");
        exit(0);
    }
}