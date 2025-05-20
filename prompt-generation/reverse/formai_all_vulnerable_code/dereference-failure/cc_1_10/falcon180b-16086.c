//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmptr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, 0, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = i;
    }

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process again
    shmptr = shmat(shmid, 0, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Print contents of shared memory segment
    printf("Shared memory segment contents:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", *(shmptr + i));
    }
    printf("\n");

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}