//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

// Define the number of processes and the shared memory size
#define NUM_PROCESSES 5
#define SHM_SIZE 1024

// Define the semaphore key and the shared memory key
#define SEM_KEY 1234
#define SHM_KEY 5678

// Define the semaphore operations
#define SEM_OP_LOCK -1
#define SEM_OP_UNLOCK 1

// Define the shared memory structure
typedef struct {
    int value;
} shared_memory;

// Function to create a semaphore
int create_semaphore() {
    // Create a semaphore with the given key and initial value
    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Set the initial value of the semaphore to 1
    if (semctl(sem_id, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    return sem_id;
}

// Function to lock a semaphore
void lock_semaphore(int sem_id) {
    // Perform a semaphore operation to lock the semaphore
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = SEM_OP_LOCK;
    sem_op.sem_flg = 0;
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

// Function to unlock a semaphore
void unlock_semaphore(int sem_id) {
    // Perform a semaphore operation to unlock the semaphore
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = SEM_OP_UNLOCK;
    sem_op.sem_flg = 0;
    if (semop(sem_id, &sem_op, 1) == -1) {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

// Function to create shared memory
int create_shared_memory() {
    // Create shared memory with the given key and size
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    return shm_id;
}

// Function to attach shared memory to a process
shared_memory* attach_shared_memory(int shm_id) {
    // Attach shared memory to the process
    shared_memory* shm_ptr = (shared_memory*)shmat(shm_id, NULL, 0);
    if (shm_ptr == (shared_memory*)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    return shm_ptr;
}

// Function to detach shared memory from a process
void detach_shared_memory(shared_memory* shm_ptr) {
    // Detach shared memory from the process
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}

// Function to remove shared memory
void remove_shared_memory(int shm_id) {
    // Remove shared memory from the system
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
}

// Function to remove semaphore
void remove_semaphore(int sem_id) {
    // Remove semaphore from the system
    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    // Create a semaphore and shared memory
    int sem_id = create_semaphore();
    int shm_id = create_shared_memory();

    // Attach shared memory to the main process
    shared_memory* shm_ptr = attach_shared_memory(shm_id);

    // Spawn child processes
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process

            // Lock the semaphore
            lock_semaphore(sem_id);

            // Increment the shared memory value
            shm_ptr->value++;

            // Unlock the semaphore
            unlock_semaphore(sem_id);

            // Detach shared memory from the child process
            detach_shared_memory(shm_ptr);

            exit(EXIT_SUCCESS);
        }
    }

    // Wait for child processes to finish
    for (int i = 0; i < NUM_PROCESSES; i++) {
        wait(NULL);
    }

    // Print the final value of shared memory
    printf("The final value of shared memory is: %d\n", shm_ptr->value);

    // Detach shared memory from the main process
    detach_shared_memory(shm_ptr);

    // Remove shared memory and semaphore
    remove_shared_memory(shm_id);
    remove_semaphore(sem_id);

    return EXIT_SUCCESS;
}