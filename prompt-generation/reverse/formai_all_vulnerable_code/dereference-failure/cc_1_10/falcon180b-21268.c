//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0
#define SEM_ID 0
#define SHM_ID 1

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    int shmid, semid;
    char *shmptr;
    int *shmint;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    shmint = (int *)shmptr;
    *shmint = 0;

    // Create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore
    union semun arg;
    arg.val = 1;
    if (semctl(semid, SEM_ID, SETVAL, arg) == -1) {
        perror("semctl");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);
        printf("Child process: Incrementing shared memory\n");
        (*shmint)++;
        sleep(1);
        printf("Child process: Decrementing shared memory\n");
        (*shmint)--;
        exit(0);
    } else {
        // Parent process
        sleep(2);
        printf("Parent process: Shared memory value: %d\n", *shmint);
        exit(0);
    }

    return 0;
}