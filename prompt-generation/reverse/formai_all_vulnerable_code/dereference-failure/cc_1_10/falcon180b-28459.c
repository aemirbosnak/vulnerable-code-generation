//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    char *shmaddr;
    int i, j;

    if (argc < 3) {
        printf("Usage: %s <key> <operation>\n", argv[0]);
        exit(1);
    }

    shmid = shmget(atoi(argv[1]), SIZE, IPC_CREAT | 0777);

    if (shmid == -1) {
        printf("Failed to create shared memory segment.\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (char *)-1) {
        printf("Failed to attach shared memory segment.\n");
        exit(1);
    }

    switch (atoi(argv[2])) {
        case 1: // Write to shared memory
            for (i = 0; i < SIZE; i++) {
                shmaddr[i] = 'a';
            }
            break;
        case 2: // Read from shared memory
            for (i = 0; i < SIZE; i++) {
                printf("%c", shmaddr[i]);
            }
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }

    if (shmdt(shmaddr) == -1) {
        printf("Failed to detach shared memory segment.\n");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Failed to remove shared memory segment.\n");
        exit(1);
    }

    return 0;
}