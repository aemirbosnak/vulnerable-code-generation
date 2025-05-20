//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    char *shm;
    char *str = "Hello, world!\n";
    int len = strlen(str) + 1;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        fprintf(stderr, "Error: shmget() failed with error: %d\n", errno);
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) - 1) {
        fprintf(stderr, "Error: shmat() failed with error: %d\n", errno);
        exit(1);
    }

    // Copy string to shared memory
    for (i = 0; i < len; i++) {
        *(shm + i) = *(str + i);
    }

    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
        fprintf(stderr, "Error: shmdt() failed with error: %d\n", errno);
        exit(1);
    }

    // Attach shared memory segment to process again
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) - 1) {
        fprintf(stderr, "Error: shmat() failed with error: %d\n", errno);
        exit(1);
    }

    // Print string from shared memory
    printf("String from shared memory: %s\n", shm);

    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
        fprintf(stderr, "Error: shmdt() failed with error: %d\n", errno);
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "Error: shmctl() failed with error: %d\n", errno);
        exit(1);
    }

    return 0;
}