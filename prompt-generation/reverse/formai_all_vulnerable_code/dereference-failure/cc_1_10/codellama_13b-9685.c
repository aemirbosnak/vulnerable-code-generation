//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

// Shared memory segment
int shmid;
char *shm;

// Semaphore
int semid;
struct sembuf sem_op;

// Parent process
int parent() {
    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, 1024, 0666);
    shm = (char *)shmat(shmid, NULL, 0);

    // Create semaphore
    semid = semget(IPC_PRIVATE, 1, 0666);
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;

    // Write to shared memory
    strcpy(shm, "Hello, world!");

    // Wait for semaphore
    semop(semid, &sem_op, 1);

    // Read from shared memory
    printf("Child process wrote: %s\n", shm);

    // Detach shared memory
    shmdt(shm);

    // Exit
    exit(0);
}

// Child process
int child() {
    // Attach to shared memory
    shm = (char *)shmat(shmid, NULL, 0);

    // Post semaphore
    semop(semid, &sem_op, 1);

    // Wait for semaphore
    semop(semid, &sem_op, 1);

    // Read from shared memory
    printf("Parent process wrote: %s\n", shm);

    // Detach shared memory
    shmdt(shm);

    // Exit
    exit(0);
}

int main() {
    // Create a child process
    pid_t pid = fork();

    // Parent process
    if (pid > 0) {
        parent();
    }

    // Child process
    if (pid == 0) {
        child();
    }

    // Wait for child process to exit
    wait(NULL);

    // Clean up
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    return 0;
}