//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>

#define MAX_SIZE 100

int main() {
    int shmid, semid;
    char *shmaddr;
    int i;
    char *msg;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < MAX_SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // Create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = 0;
    sem_op.sem_flg = SEM_UNDO;

    if (semctl(semid, 0, SETVAL, 1) < 0) {
        printf("Error setting semaphore\n");
        exit(1);
    }

    // Fork child process
    pid_t pid = fork();

    if (pid < 0) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (i = 0; i < MAX_SIZE; i++) {
            *(shmaddr + i) = i * 2;
        }
        printf("Child process finished\n");
        exit(0);
    } else {
        // Parent process
        sleep(1);
        for (i = 0; i < MAX_SIZE; i++) {
            if (*(shmaddr + i)!= i * 2) {
                printf("Error: Shared memory not updated correctly\n");
                exit(1);
            }
        }
        printf("Parent process finished\n");
        exit(0);
    }
}