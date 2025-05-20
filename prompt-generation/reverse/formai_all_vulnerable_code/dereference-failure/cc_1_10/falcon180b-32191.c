//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shm_id;
    int *shm_ptr;
    int i;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);

    // Check if shared memory segment created successfully
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm_ptr = (int *)shmat(shm_id, NULL, 0);

    // Check if shared memory segment attached successfully
    if (shm_ptr == (int *)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shm_ptr[i] = i;
    }

    // Detach shared memory segment from process
    if (shmdt(shm_ptr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}