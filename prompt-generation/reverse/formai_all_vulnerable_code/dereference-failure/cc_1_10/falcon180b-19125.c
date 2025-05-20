//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SEM_ID 0x1234
#define SHM_ID 0x4321
#define SHM_SIZE 1024

int main() {
    int sem_id;
    int shm_id;
    int *shm_ptr;
    char *shm_name = "/my_shm";

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, SHM_SIZE, 0777);
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void*)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    strcpy(shm_ptr, "Hello, world!");

    // Create semaphore
    sem_id = semget(SEM_ID, 1, 0777);
    if (sem_id == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    // Wait for semaphore to be available
    if (semop(sem_id, &(struct sembuf){0, -1, SEM_UNDO}, 1) == -1) {
        printf("Error waiting for semaphore\n");
        exit(1);
    }

    // Write to shared memory segment
    strcat(shm_ptr, " from process 1");

    // Signal semaphore for next process
    if (semop(sem_id, &(struct sembuf){0, 1, IPC_NOWAIT}, 1) == -1) {
        printf("Error signaling semaphore\n");
        exit(1);
    }

    // Detach from shared memory segment
    if (shmdt(shm_ptr) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Exit first process
    return 0;
}