//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    void *shmptr;
    char *str = "Hello World!";

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("shmget failed\n");
        exit(1);
    }

    // Attach shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        printf("shmat failed\n");
        exit(1);
    }

    // Copy string to shared memory
    strcpy(shmptr, str);

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("shmdt failed\n");
        exit(1);
    }

    // Attach shared memory segment in read-only mode
    shmptr = shmat(shmid, NULL, SHM_RDONLY);
    if (shmptr == (void *) -1) {
        printf("shmat failed\n");
        exit(1);
    }

    // Print string from shared memory
    printf("%s\n", shmptr);

    // Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("shmdt failed\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("shmctl failed\n");
        exit(1);
    }

    return 0;
}