//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define TRUE 1
#define FALSE 0
#define SEM_KEY 1234
#define SHM_KEY 5678
#define SEM_SIZE 10
#define SHM_SIZE 100

int main() {
    int shmid, semid;
    char *shm;
    int *sem;

    // Create shared memory
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory.\n");
        exit(1);
    }
    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching shared memory.\n");
        exit(1);
    }

    // Initialize shared memory
    memset(shm, 0, SHM_SIZE);

    // Create semaphore
    semid = semget(SEM_KEY, SEM_SIZE, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore.\n");
        exit(1);
    }
    sem = (int *) semctl(semid, 0, IPC_STAT, 0);
    if (sem == (int *) -1) {
        printf("Error getting semaphore status.\n");
        exit(1);
    }
    sem[0] = 0;

    // Fork child processes
    int pid1, pid2;
    switch (fork()) {
        case -1:
            printf("Error forking.\n");
            exit(1);
        case 0:
            // Child 1
            printf("Child 1 started.\n");
            sleep(1);
            sem[0] = 1;
            printf("Child 1 finished.\n");
            exit(0);
        default:
            // Parent
            printf("Parent waiting for child 1.\n");
            wait(NULL);
            printf("Parent waiting for child 2.\n");
            break;
    }
    switch (fork()) {
        case -1:
            printf("Error forking.\n");
            exit(1);
        case 0:
            // Child 2
            printf("Child 2 started.\n");
            sleep(1);
            sem[0] = 0;
            printf("Child 2 finished.\n");
            exit(0);
        default:
            // Parent
            printf("Parent waiting for child 2.\n");
            wait(NULL);
            printf("Parent finished.\n");
            exit(0);
    }
    return 0;
}