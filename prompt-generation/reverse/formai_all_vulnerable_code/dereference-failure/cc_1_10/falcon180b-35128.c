//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    int fd;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // Write data to shared memory segment
    strcpy(shm, "Hello, world!");

    // Create a file and write data to it
    fd = open("output.txt", O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        printf("Error creating output file.\n");
        exit(1);
    }
    write(fd, shm, strlen(shm));
    close(fd);

    // Detach shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment.\n");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment.\n");
        exit(1);
    }

    return 0;
}