//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main(int argc, char *argv[]) {
    int shmid;
    char *shmptr;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error in shmget\n");
        exit(1);
    }

    shmptr = shmat(shmid, 0, 0);
    if (shmptr == (void *) -1) {
        printf("Error in shmat\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 'A' + i;
    }

    printf("Shared memory segment has been created\n");
    printf("Contents of shared memory segment:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%c ", shmptr[i]);
    }
    printf("\n");

    sleep(5);

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 'a' + i;
    }

    printf("Contents of shared memory segment after modification:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%c ", shmptr[i]);
    }
    printf("\n");

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}