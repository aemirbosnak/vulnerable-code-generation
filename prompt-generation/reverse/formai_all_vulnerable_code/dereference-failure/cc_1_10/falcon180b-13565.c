//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int shmid;
    char *shm;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE, 0666 | IPC_CREAT);

    if (shmid == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        printf("Error in shmat\n");
        exit(2);
    }

    for (i = 0; i < SIZE; i++) {
        shm[i] = i;
    }

    printf("Shared memory segment created\n");

    sleep(10);

    for (i = 0; i < SIZE; i++) {
        if (shm[i]!= i) {
            printf("Error in shared memory\n");
            exit(3);
        }
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory segment deleted\n");

    return 0;
}