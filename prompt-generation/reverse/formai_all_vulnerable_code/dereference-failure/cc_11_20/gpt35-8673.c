//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
/* This is a sample C program that demonstrates interprocess communication using semaphores and shared memory.
 * The program creates two child processes, one which writes to the shared memory and another which reads from it.
 * The parent process creates the semaphores and initializes the shared memory.
 * Author: Dennis M. Ritchie
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>

// Define constants
#define SHM_SIZE 1024 // Shared memory size
#define SEM_WRITE 0 // Semaphore 0 for writing
#define SEM_READ 1 // Semaphore 1 for reading

// Define union for semaphores
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    int shmid; // Shared memory ID
    char *shm; // Pointer to shared memory
    int semid; // Semaphore ID
    union semun sem_args; // Semaphore arguments
    pid_t pid1, pid2; // Child process IDs

    // Create shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget error\n");
        exit(1);
    }

    // Attach shared memory to process space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat error\n");
        exit(1);
    }

    // Initialize shared memory to 0
    for (int i = 0; i < SHM_SIZE; i++) {
        *(shm + i) = 0;
    }

    // Create semaphores
    if ((semid = semget(IPC_PRIVATE, 2, IPC_CREAT | 0666)) < 0) {
        perror("semget error\n");
        exit(1);
    }

    // Initialize semaphores
    sem_args.val = 1;
    if (semctl(semid, SEM_WRITE, SETVAL, sem_args) < 0) {
        perror("semctl error\n");
        exit(1);
    }
    sem_args.val = 0;
    if (semctl(semid, SEM_READ, SETVAL, sem_args) < 0) {
        perror("semctl error\n");
        exit(1);
    }

    // Create first child process for writing
    if ((pid1 = fork()) == 0) {
        for (int i = 0; i < 10; i++) {
            // Wait for semaphore 0
            struct sembuf sem_buffer = {SEM_WRITE, -1, 0};
            semop(semid, &sem_buffer, 1);

            // Write to shared memory
            sprintf(shm, "Child process 1 writes to shared memory %d\n", i);

            // Signal semaphore 1
            sem_buffer.sem_num = SEM_READ;
            sem_buffer.sem_op = 1;
            semop(semid, &sem_buffer, 1);
        }
        exit(0);
    }

    // Create second child process for reading
    if ((pid2 = fork()) == 0) {
        for (int i = 0; i < 10; i++) {
            // Wait for semaphore 1
            struct sembuf sem_buffer = {SEM_READ, -1, 0};
            semop(semid, &sem_buffer, 1);

            // Read from shared memory
            printf("Child process 2 reads from shared memory: %s", shm);

            // Signal semaphore 0
            sem_buffer.sem_num = SEM_WRITE;
            sem_buffer.sem_op = 1;
            semop(semid, &sem_buffer, 1);
        }
        exit(0);
    }

    // Wait for child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // Detach shared memory
    shmdt(shm);

    // Delete shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    // Delete semaphores
    semctl(semid, 0, IPC_RMID);
    
    return 0;
}