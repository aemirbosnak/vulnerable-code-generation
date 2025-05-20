//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

// Declare the shared memory segment
int *shared_memory;

// Declare the semaphore
int semaphore_id;

// Initialize the shared memory segment
void init_shared_memory() {
    // Create the shared memory segment
    int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | IPC_EXCL | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process
    shared_memory = shmat(shm_id, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Initialize the shared memory segment to 0
    *shared_memory = 0;
}

// Initialize the semaphore
void init_semaphore() {
    // Create the semaphore
    semaphore_id = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (semaphore_id == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore to 1
    semctl(semaphore_id, 0, SETVAL, 1);
}

// Increment the shared memory segment
void increment_shared_memory() {
    // Lock the semaphore
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(semaphore_id, &sem_op, 1);

    // Increment the shared memory segment
    *shared_memory += 1;

    // Unlock the semaphore
    sem_op.sem_op = 1;
    semop(semaphore_id, &sem_op, 1);
}

// Decrement the shared memory segment
void decrement_shared_memory() {
    // Lock the semaphore
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(semaphore_id, &sem_op, 1);

    // Decrement the shared memory segment
    *shared_memory -= 1;

    // Unlock the semaphore
    sem_op.sem_op = 1;
    semop(semaphore_id, &sem_op, 1);
}

// Main function
int main() {
    // Initialize the shared memory segment
    init_shared_memory();

    // Initialize the semaphore
    init_semaphore();

    // Create a child process
    int pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // If the current process is the child process
    if (pid == 0) {
        // Increment the shared memory segment 100 times
        for (int i = 0; i < 100; i++) {
            increment_shared_memory();
        }

        // Exit the child process
        exit(EXIT_SUCCESS);
    }

    // If the current process is the parent process
    else {
        // Decrement the shared memory segment 100 times
        for (int i = 0; i < 100; i++) {
            decrement_shared_memory();
        }

        // Wait for the child process to finish
        wait(NULL);

        // Print the final value of the shared memory segment
        printf("The final value of the shared memory segment is: %d\n", *shared_memory);

        // Detach the shared memory segment from the current process
        shmdt(shared_memory);

        // Destroy the shared memory segment
        shmctl(shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | IPC_EXCL | 0666), IPC_RMID, NULL);

        // Destroy the semaphore
        semctl(semaphore_id, 0, IPC_RMID);
    }

    return EXIT_SUCCESS;
}