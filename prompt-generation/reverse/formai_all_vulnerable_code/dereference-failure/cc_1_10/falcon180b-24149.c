//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SEM_ID 0x1234
#define SHM_ID 0x5678

int main() {
    int semid;
    int shmid;
    char *shm;

    // Create a semaphore
    semid = semget(SEM_ID, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        printf("Error creating semaphore.\n");
        return 1;
    }

    // Create a shared memory segment
    shmid = shmget(SHM_ID, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        return 1;
    }

    shm = (char *) shmat(shmid, NULL, 0);
    if ((int) shm == -1) {
        printf("Error attaching to shared memory segment.\n");
        return 1;
    }

    // Initialize the shared memory segment
    strcpy(shm, "Hello, World!");

    // Wait for the semaphore
    semop(semid, &(struct sembuf) { 0, -1, IPC_NOWAIT }, 1);

    // Read from the shared memory segment
    printf("Shared memory segment contents: %s\n", shm);

    // Release the semaphore
    semop(semid, &(struct sembuf) { 0, 1, IPC_NOWAIT }, 1);

    // Detach from the shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment.\n");
        return 1;
    }

    // Delete the semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        printf("Error deleting semaphore.\n");
        return 1;
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment.\n");
        return 1;
    }

    return 0;
}