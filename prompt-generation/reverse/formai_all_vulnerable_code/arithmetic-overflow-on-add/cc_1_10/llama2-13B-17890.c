//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define SHM_NAME "my_shared_mem"

int main() {
    // Create a shared memory segment
    int shm_id = shmget(SHM_NAME, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    char *shm_ptr = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Create a semaphore to synchronize access to the shared memory
    int sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0644);
    if (sem_id == -1) {
        perror("semget");
        return 1;
    }

    // Create a message to be sent to the other process
    char message[] = "Hello from process 1!";

    // Acquire the semaphore to ensure that only one process can access the shared memory at a time
    if (sem_wait(sem_id) == -1) {
        perror("sem_wait");
        return 1;
    }

    // Write the message to the shared memory
    strcpy(shm_ptr, message);

    // Release the semaphore to allow the other process to access the shared memory
    sem_post(sem_id);

    // Wait for the other process to finish
    wait(NULL);

    // Print the message from the other process
    printf("Received message from process 2: %s\n", shm_ptr);

    // Unmap the shared memory
    munmap(shm_ptr, BUFFER_SIZE);

    // Destroy the semaphore
    sem_destroy(sem_id);

    return 0;
}