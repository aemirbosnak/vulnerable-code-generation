//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmaddr;
    key_t key;
    int i;

    // Create shared memory segment
    key = ftok("program_name", 65);
    shmid = shmget(key, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) - 1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // Print shared memory segment
    for (i = 0; i < SIZE; i++) {
        printf("%d ", *(shmaddr + i));
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