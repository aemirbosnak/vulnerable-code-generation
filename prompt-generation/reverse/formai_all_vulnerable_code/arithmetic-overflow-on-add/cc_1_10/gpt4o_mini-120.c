//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>

#define SHM_SIZE 10

typedef struct {
    int buffer[SHM_SIZE];
    int in;
    int out;
} shared_data;

int main() {
    int shm_id;
    shared_data *data;
    sem_t *sem_empty, *sem_full;
    
    // Create shared memory
    shm_id = shmget(IPC_PRIVATE, sizeof(shared_data), IPC_CREAT | 0666);
    data = (shared_data *)shmat(shm_id, NULL, 0);
    
    // Initialize buffer
    data->in = 0;
    data->out = 0;

    // Create semaphores
    sem_empty = sem_open("/sem_empty", O_CREAT, 0644, SHM_SIZE);
    sem_full = sem_open("/sem_full", O_CREAT, 0644, 0);

    // Fork the producer process
    if (fork() == 0) {
        for (int i = 0; i < 20; i++) {
            sem_wait(sem_empty); // Wait for empty slot
            
            // Produce an item
            int item = rand() % 100;
            data->buffer[data->in] = item;
            printf("Produced: %d\n", item);
            data->in = (data->in + 1) % SHM_SIZE;

            sem_post(sem_full); // Signal that a new item is available
            sleep(rand() % 2);
        }
        exit(0);
    }

    // Fork the consumer process
    if (fork() == 0) {
        for (int i = 0; i < 20; i++) {
            sem_wait(sem_full); // Wait for full slot
            
            // Consume an item
            int item = data->buffer[data->out];
            printf("Consumed: %d\n", item);
            data->out = (data->out + 1) % SHM_SIZE;

            sem_post(sem_empty); // Signal that a slot is now empty
            sleep(rand() % 3);
        }
        exit(0);
    }

    // Wait for child processes to terminate
    wait(NULL);
    wait(NULL);

    // Cleanup shared memory and semaphores
    shmdt(data);
    shmctl(shm_id, IPC_RMID, NULL);
    sem_close(sem_empty);
    sem_unlink("/sem_empty");
    sem_close(sem_full);
    sem_unlink("/sem_full");

    return 0;
}