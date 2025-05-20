//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define SEM_KEY 100
#define SHM_KEY 200

// Struct for shared memory
typedef struct {
    int value;
} shared_data;

int main() {
    int sem_id, shm_id;
    key_t sem_key = SEM_KEY, shm_key = SHM_KEY;
    shared_data *shm_ptr;

    // Create shared memory segment
    shm_id = shmget(shm_key, sizeof(shared_data), 0666 | IPC_CREAT);
    if (shm_id == -1) {
        printf("Failed to create shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm_ptr = (shared_data *) shmat(shm_id, (void *) 0, 0);
    if (shm_ptr == (void *) -1) {
        printf("Failed to attach shared memory segment\n");
        exit(1);
    }

    // Initialize shared data
    shm_ptr->value = 0;

    // Create semaphore
    sem_id = semget(sem_key, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        printf("Failed to create semaphore\n");
        exit(1);
    }

    // Initialize semaphore value to 0
    semctl(sem_id, 0, SETVAL, 0);

    // Loop to increment shared data value and display it
    while (1) {
        sleep(1);
        shm_ptr->value++;
        printf("Shared data value: %d\n", shm_ptr->value);
    }

    return 0;
}