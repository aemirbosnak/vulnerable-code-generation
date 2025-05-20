//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SHM_SIZE; i++) {
        *shm = i;
        shm++;
    }

    // Detach from shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment again
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Print contents of shared memory
    for (i = 0; i < SHM_SIZE; i++) {
        printf("%d ", *shm);
        shm++;
    }

    // Detach from shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(1);
    }

    return 0;
}