//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    int *shmaddr;
    char *shmname = "my_shm";

    //create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), 0666);
    if (shmid == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    //attach to shared memory segment
    shmaddr = (int *) shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error in shmat\n");
        exit(1);
    }

    //initialize shared memory segment
    for (int i = 0; i < SIZE; i++) {
        *(shmaddr + i) = i;
    }

    //detach from shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error in shmdt\n");
        exit(1);
    }

    //attach to shared memory segment again
    shmaddr = (int *) shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error in shmat\n");
        exit(1);
    }

    //print shared memory segment
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(shmaddr + i));
    }
    printf("\n");

    //detach from shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error in shmdt\n");
        exit(1);
    }

    //delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error in shmctl\n");
        exit(1);
    }

    return 0;
}