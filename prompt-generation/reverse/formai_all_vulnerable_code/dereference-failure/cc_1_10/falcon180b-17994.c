//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 50

int main() {
    int shmid;
    char *shmaddr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0777);
    if (shmid < 0) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmaddr + i) = 'A' + i;
    }

    // Print shared memory segment
    for (i = 0; i < SIZE; i++) {
        printf("%c ", *(shmaddr + i));
    }
    printf("\n");

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1) {
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